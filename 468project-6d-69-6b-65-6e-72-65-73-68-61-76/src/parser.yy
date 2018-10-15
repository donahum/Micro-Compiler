
%{
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <list>
    #include <stack>
    #include <cstring>
    extern int yylex();
    extern int yylineno;
    extern char * yytext;
    void yyerror(const char * s) {
        //printf("DECLARATION ERROR <%s>\n", s);
    }
%}

%code requires{
    #ifndef ST_H
    #define ST_H
    #include "../src/SymbolTable.hpp"
    #endif

    #ifndef STE_H
    #define STE_H
    #include "../src/SymbolTableEntry.hpp"
    #endif

    //#ifndef AST_H
    //#define AST_H
    #ifndef AST_H
    #include "../src/ASTNode.hpp"
    #endif

    #ifndef ADDNODE_H
    #include "../src/AddExprNode.hpp"
    #endif

    #ifndef MULNODE_H
    #include "../src/MulExprNode.hpp"
    #endif

    #ifndef VARNODE_H
    #include "../src/VarRefNode.hpp"
    #endif

    #ifndef LITERALNODE_H
    #include "../src/LiteralNode.hpp"
    #endif

}

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN    
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK     _ASSIGN _NEQ _LEQ _GEQ
%token  _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA

%token <s> _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _INT _VOID _STRING _FLOAT  _MUL _DIV _PLUS _MINUS

%type <s> id str var_type any_type
%type <node> expr_prefix factor factor_prefix postfix_expr expr primary expr_list expr_list_tail call_expr func_decl
%type <add_node> addop 
%type <mul_node> mulop 
//%type <var_node> primary
//%type <lit_node> primary

%type <s_table> var_decl 
%type <str_list> id_list id_tail
%type <node> if_stmt stmt else_part loop_stmt while_stmt base_stmt assign_stmt read_stmt write_stmt control_stmt assign_expr return_stmt
%type<astlist> stmt_list func_body func_declarations pgm_body
%union{
  SymbolTableEntry * s_entry;
  char * s;
  SymbolTable * s_table;
  std::vector<SymbolTable *> * st_list;
  std::vector<char *> * str_list;
  ASTNode * node;
  AddExprNode * add_node;
  MulExprNode * mul_node;
  VarRefNode * var_node;
  LiteralNode * lit_node;
  std::vector<ASTNode*>* astlist;
}

%{
    long long scope_iterator = 1;
    std::vector<SymbolTable *> tableVector;
    std::stack<SymbolTable*> ststack; 
    SymbolTable* global;
%}

%%
/* Program */
program           : _PROGRAM id _BEGIN
                  {
                    global = new SymbolTable("GLOBAL", NULL);
                    ststack.push(global);
                  } pgm_body _END {
                                                        for(int i = $5->size() - 1; i >= 0; i--){
                                                          (*$5)[i]->TOIR();
                                                        }
                                                     };
id                : _IDENTIFIER { $$ = $1; 
                                  //printf("Base Identifer: %s\n", $1);
                                };

pgm_body          : decl func_declarations  {
                                              $$ = $2;
                                            };

decl                : string_decl decl 
                    | var_decl decl
                    | %empty 
                    ;

/* Global String Declaration */
string_decl       : _STRING id _ASSIGN str _SEMICOLON {
                                                        //printf("Type: %s\n", $1);
                                                        //printf("Name: %s\n", $2);
                                                        //printf("Value: %s\n", $4);
                                                        SymbolTableEntry* tmp = new SymbolTableEntry($2, $1, $4);
                                                        ststack.top().addEntry(tmp);
                                                        //$$->printSTE();
                                                        //std::cout << std::endl;
                                                      };
str               : _STRINGLITERAL  {$$ = $1;
                                    };

/* Variable Declaration */

var_decl          : var_type id_list _SEMICOLON { 
                                                  for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                                  {
                                                      char * varName = $2->at(i);
                                                      SymbolTableEntry * varEntry = new SymbolTableEntry(varName, $1);
                                                      ststack.top().addEntry(varEntry);
                                                  };
                                                };  

var_type          : _FLOAT  { $$ = $1;
                              //printf("%s\n", $1);  
                            };
                    | _INT  {$$ = $1;
                              //printf("%s\n", $1);  
                            };   

any_type          : var_type  {$$ = $1;
                                //printf("%s\n", $1);  
                              }; 

                    | _VOID   {$$ = $1;
                                //printf("%s\n", $1);  
                              };     

id_list           : id id_tail  {
                                  $$ = $2;
                                  $$->push_back($1);
                                  //std::cout << "id_list\n";
                                  for(std::vector<int>::size_type i = 0; i != $$->size(); ++i)
                                  {
                                      //std::cout << $$->at(i);
                                  };
                                  //std::cout << std::endl;
                                }; 

id_tail           : _COMMA id id_tail {
                                         $$ = $3;
                                         $$->push_back($2);
                                         //std::cout << "id_tail\n";
                                      }   
                    | %empty  { $$ = new std::vector<char *>();
                                //std::cout << "Making new id list vector\n";
                              };

/* Function Paramater List */
param_decl_list   : param_decl param_decl_tail
                    | %empty    ;

param_decl        : var_type id {
                                    SymbolTableEntry* tmp = new SymbolTableEntry($2, $1);
                                    ststack.top()->addEntry(tmp);
                                    //std::cout << "param_decl\n";
                                };

param_decl_tail   : _COMMA param_decl param_decl_tail
                    | %empty;

/* Function Declarations */
func_declarations : func_decl func_declarations { //std::cout << "func_declarations" << std::endl;
                                                  $$ = $2;
                                                  $$->push_back($1);
                                                };  
                    | %empty  {
                                $$ = new std::vector<ASTNode *>;
                              };

func_decl         : _FUNCTION any_type id _OPAREN {
                                                    SymbolTable* tmp = new SymbolTable(*$3, ststack.top());
                                                    ststack.top()->children.push_back(tmp);
                                                    ststack.push(tmp);
                                                  } param_decl_list _CPAREN _BEGIN func_body _END   
                                                  {
                                                    $$ = new FuncNode(*$3, $9, ststack.top());
                                                    ststack.pop();
                                                  };

func_body         : decl stmt_list  {0
                                      $$= $2;
                                    };

/* Statement List */
stmt_list         : stmt stmt_list  {   
                                        $$ = $1;
                                        $$->push_back($1);
                                      }
                    | %empty  {
                                  $$ = new std::vector<ASTNode*>;
                                  //std::cout << "stmt_list EMPTY\n";
                              };

stmt              : base_stmt   {$$ = $1;}
                    | if_stmt   {
                                    $$ = $1;
                                    //std::cout << "if_stmt\n";
                                }
                    | loop_stmt {
                                    $$ = $1;
                                    //std::cout << "loop_stmt\n";
                                };
base_stmt         : assign_stmt {$$ = $1;} | read_stmt {$$ = $1;}| write_stmt {$$ = $1;}| control_stmt{$$ = $1;};

/* Basic Statements */
assign_stmt       : assign_expr _SEMICOLON {$$ = $1;};
assign_expr       : id _ASSIGN expr {
                                      VarRefNode* vid = new VarRefNode(*$1,ASTNodeType::VAR_REF);
                                      $$ = new AssignNode(vid, $3);
                                    };
read_stmt         : _READ _OPAREN id_list _CPAREN _SEMICOLON{$$ = NULL;};
write_stmt        : _WRITE _OPAREN id_list _CPAREN _SEMICOLON{$$ = NULL;};
return_stmt       : _RETURN expr _SEMICOLON{$$ = NULL;};

/* Expressions */
expr              : expr_prefix factor  {
                                            //$$ = new ASTNode();
                                            if($1 == NULL)
                                            {
                                                $$=$2;
                                                //std::cout << "Print EXPR tree Right 1" << std::endl;
                                                //$2->printTree($2);
                                            }else{
                                                //std::cout << "Print EXPR tree Left 2" << std::endl;
                                                $1->Left=$2;
                                                $$ = $1;
                                                //$1->printTree($1);
                                                //std::cout << "Print EXPR tree Right 2" << std::endl;
                                                //$$->Right=$2;
                                                //$2->printTree($2);
                                            }
                                            /*if($$->Left == NULL)
                                            {
                                              std::cout << "Left is null" << std::endl;
                                            }
                                            if($$->Right == NULL)
                                            {
                                              std::cout << "Right is null" << std::endl;
                                            }
                                            $$->printTree($$);*/
                                            
                                        };

expr_prefix       : expr_prefix factor addop  {
                                                  $$ = $3;
                                                  //$3->printNode();
                                                  if($1 == NULL)
                                                  {
                                                      $$->Left=$2;
                                                  }else{
                                                      $$->Left=$1;
                                                      $$->Right=$2;
                                                  }
                                              };
                    | %empty  {
                                  $$ = NULL;
                              }; 

factor            : factor_prefix postfix_expr  {
                                                    if($1 == NULL)
                                                    {
                                                      $$ = $2;
                                                        //$$->Right=$2;
                                                    }else{
                                                        $1->Left=$2;
                                                        //$$->Right=$2;
                                                        $$= $1;
                                                    }
                                                };

factor_prefix     : factor_prefix postfix_expr mulop  {
                                                          $$ = $3;
                                                          if($1 == NULL)
                                                          {
                                                              $$->Left = $2;
                                                          }else{
                                                              if($1->Right == NULL){
                                                                  $1->Right = $2;
                                                                  $3->Left = $1;
                                                              }else{
                                                                  //may need to fix strat here
                                                                  $$->Left = $1;
                                                                  $$->Right=$2;
                                                            }
                                                          }
                                                      };
                    | %empty  {
                                  $$ = NULL;
                              };

postfix_expr      : primary   {
                                  $$ = $1;
                              };
                    | call_expr {
                                    $$ = NULL;
                                };

call_expr         : id _OPAREN expr_list _CPAREN  {
                                                      $$ = NULL;
                                                  };

expr_list         : expr expr_list_tail {
                                            $$ = NULL;
                                        };
                    | %empty  {
                                  $$ = NULL;
                              };

expr_list_tail    : _COMMA expr expr_list_tail  {
                                                    $$ = NULL;
                                                };
                    | %empty  {
                                  $$ = NULL;
                              };

primary           : _OPAREN expr _CPAREN  {
                                              $$ = $2;
                                              //$$ = NULL;
                                          };
                    | id  {
                              $$ = new VarRefNode($1, ASTNodeType::VAR_REF);
                              //$$ = NULL;
                          };
                    | _INTLITERAL {
                                      $$ = new LiteralNode(LiteralType::isINT, $1, ASTNodeType::LITERAL);
                                      //$$->printNode();
                                  }; 
                    | _FLOATLITERAL {
                                      $$ = new LiteralNode(LiteralType::isFLOAT, $1, ASTNodeType::LITERAL);
                                    };

addop             : _PLUS {
                              $$ = new AddExprNode($1, ASTNodeType::ADD_EXPR);
                              //$$->printNode();
                          };
                    | _MINUS  {
                                  $$ = new AddExprNode($1, ASTNodeType::ADD_EXPR);
                              };

mulop             : _MUL  {
                            $$ = new MulExprNode($1, ASTNodeType::MULT_EXPR);
                          }
                    | _DIV{
                            $$ = new MulExprNode($1, ASTNodeType::MULT_EXPR);
                            //$$->printNodeType();
                          };

/* Complex Statements and Condition */ 
if_stmt           : _IF _OPAREN cond _CPAREN decl
                                                {
                                                  SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                                                  ststack.top()->children.push_back(tmp);
                                                  ststack.push(tmp);
                                                }
                    stmt_list
                                                {
                                                  ststack.pop();
                                                } 
                  else_part _ENDIF  {               
                                        $$ = $7;
                                        //ststack.pop();
                                    };

else_part         : _ELSE decl  { //std::cout << "Else Scope It: " << scope_iterator << std::endl;
                                  SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                                  ststack.top()->children.push_back(tmp);
                                  ststack.push(tmp);
                                } 
                    stmt_list  {
                                  $$ = $4;
                                  ststack.pop();
                                }

                    | %empty  {
                                  $$ = NULL;
                              };

cond              : expr compop expr | _TRUE | _FALSE;
compop            : _LT | _GT | _EQ | _NEQ | _LEQ | _GEQ;
while_stmt        : _WHILE _OPAREN cond _CPAREN decl 
                  { //std::cout << "Else Scope It: " << scope_iterator << std::endl;
                    SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                    ststack.top()->children.push_back(tmp);
                    ststack.push(tmp);
                  } 
                  stmt_list _ENDWHILE  {  ststack.pop(); };

/*ECE468 ONLY*/
control_stmt      : return_stmt {$$ = NULL;};
loop_stmt         : while_stmt  {$$ = $1;};

%%
