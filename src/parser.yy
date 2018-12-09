%code requires{
  #include "../src/SymbolTable.hpp"
  #include "../src/Node.hpp"
}
%{
  #include <stdio.h>
  #include <iostream>
  #include <string>
  #include <vector>
  #include <list>
  #include <stack>
  #include <cstring>
  #include "../src/SymbolTable.hpp"
  #include "../src/Node.hpp"
  extern int yylex();
  extern int yylineno;
  extern char * yytext;
  void yyerror(const char * s) {
      //printf("DECLARATION ERROR <%s>\n", s);
  }
  long long scope_iterator = 1;
  std::stack<SymbolTable*> ststack; 
  SymbolTable* global;
  long long currentBlockID = 0;
  //int slot_count = 1;
%}

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN    
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK     _ASSIGN _NEQ _LEQ _GEQ
%token  _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA
%token _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _INT _VOID _STRING _FLOAT  _MUL _DIV _PLUS _MINUS

%type <s> id str var_type any_type
%type <str_list> id_list id_tail 
%type <node> expr_prefix factor factor_prefix postfix_expr expr primary call_expr addop mulop assign_expr
%type <node> if_stmt stmt base_stmt loop_stmt read_stmt write_stmt control_stmt return_stmt assign_stmt else_part while_stmt func_decl
%type <ast_list> stmt_list func_body func_declarations pgm_body expr_list expr_list_tail
%type <jtype> compop
%type <condition> cond
%type <ste_vec> param_decl_tail param_decl_list decl var_decl
%type <ste> param_decl string_decl

%union{
  std::string* s;
  std::list<std::string> * str_list;
  ASTNode * node;
  WhileNode * while_node;
  IfNode * if_node;
  ElseNode * else_node;
  std::vector<ASTNode*> * ast_list;
  JumpType * jtype;
  Conditional * condition;
  //std::vector<FuncSTE> * func_ste_vec;
  //FuncSTE * func_ste;
  std::vector<SymbolTableEntry *> * ste_vec;
  SymbolTableEntry * ste;
}


%%
/* Program */
program             : _PROGRAM id _BEGIN
                    {
                      global = new SymbolTable("GLOBAL", NULL);
                      ststack.push(global);
                    } pgm_body _END 
                                    {
                                      for(auto func : *$5){
                                        if(func){
                                          func -> TO_IR(NULL);
                                        }
                                      }
                                    }
                    ;

id                  : _IDENTIFIER { $$ = new std::string(yytext);}
                    ;

pgm_body            : decl  { //ststack.top()->printST();
                              for(auto entry : *$1)
                              {
                                  //std::cout << "adding to global " << entry->name << std::endl;
                                  //entry->printSTE();
                                  //std::cout << std::endl;
                                  ststack.top()->addEntry(entry);
                                  //entry->printSTE();
                                  //std::cout << std::endl;
                              }
                              ststack.top()->numLocals = $1->size();
                              //ststack.top()->printST();
                            }

                      func_declarations   { 
                                            $$ = $3; 
                                            for(auto funcST : *$3)
                                            {
                                              //static_cast<FuncNode *> (funcST)->table->printST();
                                            }
                                          }
                    ;

decl                : string_decl decl  {//std::cout << "str decl\n";
                                          $$ = $2;
                                          /*for(auto entry : *$2)
                                          {
                                            $$->push_back(entry);
                                          }*/
                                          $$->push_back($1);
                                          //$$->push_back(*$1);

                                        }
                    | var_decl decl   {//std::cout << "var decl\n";
                                          $$ = $2;
                                          //int i = 0;
                                          //$$ = new std::vector<SymbolTableEntry>();
                                          for(auto entry : *$1)
                                          {
                                            $$->push_back(entry);
                                            //$$->insert($$->begin() + i, entry);
                                            //i++;
                                          }
                                          /*for(auto entry : *$2)
                                          {
                                            $$->push_back(entry);
                                          }*/
                                      }
                    | %empty  { //std::cout << "empty decl\n";
                                $$ = new std::vector<SymbolTableEntry *>;
                              }
                    ;

/* Global String Declaration */
string_decl         : _STRING id _ASSIGN str _SEMICOLON 
                    {
                      SymbolTableEntry* tmp = new SymbolTableEntry(*$2, "STRING", *$4, 0);
                      $$ = tmp;
                      //tmp->printSTE();
                      //std::cout<<std::endl;
                      //ststack.top()->addEntry(tmp);
                    }
                    ;

str                 : _STRINGLITERAL  { $$ = new std::string(yytext);}
                    ;

/* Variable Declaration */

var_decl            : var_type id_list _SEMICOLON 
                    { 
                      $$ = new std::vector<SymbolTableEntry *>;
                      //for(auto &varName : *$2){
                      for(std::list<std::string>::reverse_iterator rit = $2->rbegin();  rit != $2->rend();  ++rit){
                        //std::cout << "Var Name: " << varName << std::endl;
                        SymbolTableEntry * varEntry = new SymbolTableEntry(*rit, *$1, 0);
                        $$->push_back(varEntry);
                        //ststack.top()->addEntry(varEntry);
                        //varEntry->printSTE();
                        //std::cout << std::endl;
                      }
                      //$$ = var_entries;
                    }
                    ;  

var_type            : _FLOAT  { $$ = new std::string("FLOAT");}
                    | _INT  {$$ = new std::string("INT");}
                    ;   

any_type            : var_type  {$$ = $1;}
                    | _VOID   {$$ = new std::string("VOID");}
                    ;     

id_list             : id id_tail  
                    {
                      $$ = $2;
                      $$->push_front(*$1);
                    }
                    ; 

id_tail             : _COMMA id id_tail 
                    {
                      $$ = $3;
                      $$->push_front(*$2);
                    }   
                    | %empty  { $$ = new std::list<std::string>;}
                    ;

/* Function Paramater List */
param_decl_list     : param_decl param_decl_tail  {
                                                      $$ = $2;
                                                      $$->insert($$->begin(), $1);
                                                  }
                    | %empty  {
                                $$ = new std::vector<SymbolTableEntry *>;
                              }
                    ;

param_decl          : var_type id 
                    {
                      SymbolTableEntry * tmp = new SymbolTableEntry(*$2, *$1, 0);
                      //ststack.top()->addEntry(tmp);
                      $$ = tmp;
                    }
                    ;

param_decl_tail     : _COMMA param_decl param_decl_tail {
                                                            $$ = $3;
                                                            $$->insert($$->begin(), $2);
                                                            //slot_count++;
                                                        }
                    | %empty  {
                                  //slot_count = 1;
                                  $$ = new std::vector<SymbolTableEntry *>;
                              };

/* Function Declarations */
func_declarations   : func_decl func_declarations 
                    {
                      $$ = $2;
                      $$->insert($$->begin(), $1);
                    }  
                    | %empty  {$$ = new std::vector<ASTNode *>;}
                    ;

func_decl           : _FUNCTION any_type id _OPAREN 
                    {
                      SymbolTable* tmp = new SymbolTable(*$3, ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                    } 
                    param_decl_list { //std::cout << "Printing func params...\n";
                                      int i = 2;  //param slots start at 2, after return pc from link
                                      for(auto param : *$6)
                                      {
                                        //param->slot = i - $6->size();
                                        param->slot = i++;  
                                        ststack.top()->addEntry(param);
                                        //param->printSTE();
                                        //i++;
                                      }
                                      //std::cout << "Param Size: " << $6->size() << std::endl;
                                      ststack.top()->numParams = $6->size();
                                    }
                    _CPAREN _BEGIN func_body _END   
                    {
                      //std::cout << "here's what the funcnode is getting...\n";
                      //ststack.top()->printST();
                      $$ = new FuncNode(*$3, $10, ststack.top(), ASTNodeType::FUNC);
                      ststack.pop();
                    }
                    ;

func_body           : decl  {
                              int i = 0;
                              //std::cout << "Printing function locals\n";
                              for(auto local : *$1)
                              {
                                //local->slot = i++;
                                local->slot = i++ - $1->size();
                                //local->printSTE();
                                ststack.top()->addEntry(local);
                                //std::cout<<std::endl;
                              }
                              //std::cout << "Local Size: " << $1->size() << std::endl;
                              ststack.top()->numLocals = $1->size();
                              //std::cout << "here's what the func_body is getting...\n";
                              //ststack.top()->printST();
                            }
                      stmt_list  {$$ = $3;}
                    ;

/* Statement List */
stmt_list           : stmt stmt_list  
                    {   
                      $$ = $2;
                      $$->insert($$->begin(), $1);
                    }
                    | %empty  {$$ = new std::vector<ASTNode*>;}
                    ;

stmt                : base_stmt   {$$ = $1;}
                    | if_stmt   {$$ = $1;}
                    | loop_stmt {$$ = $1;}
                    ;

base_stmt           : assign_stmt {$$ = $1;} 
                    | read_stmt {$$ = $1;}
                    | write_stmt {$$ = $1;}
                    | control_stmt{$$ = $1;}
                    ;

/* Basic Statements */
assign_stmt         : assign_expr _SEMICOLON { $$ = $1; }
                    ;

assign_expr         : id _ASSIGN expr 
                    {
                      VarRefNode* vid = new VarRefNode(*$1, ASTNodeType::VAR_REF);
                      $$ = new AssignNode(vid, $3, ASTNodeType::ASSIGN);
                      //$$->printTree();
                      //std::cout << std::endl;
                    }
                    ;

read_stmt           : _READ _OPAREN id_list _CPAREN _SEMICOLON {$$ = new ReadNode($3, ASTNodeType::READ);}
                    ;

write_stmt          : _WRITE _OPAREN id_list _CPAREN _SEMICOLON {$$ = new WriteNode($3, ASTNodeType::WRITE);}
                    ;

return_stmt         : _RETURN expr _SEMICOLON {
                                                $$ = new ReturnNode(ASTNodeType::RET);
                                                $$->Right = $2;
                                              }
                    ;

/* Expressions */
expr                : expr_prefix factor  
                    {
                      if($1 == NULL){
                        $$=$2;
                      }else{
                        $1->Right=$2;
                        $$ = $1;
                      }
                    }
                    ;

expr_prefix         : expr_prefix factor addop  
                    {
                      $$ = $3;
                      if($1 == NULL){
                        $$->Left=$2;
                      }else{
                        $$->Left=$1;
                        $1->Right=$2;
                      }
                    }
                    | %empty  {$$ = NULL;}
                    ; 

factor              : factor_prefix postfix_expr  
                    {
                      if($1 == NULL)
                      {
                        $$ = $2;
                      }else{
                        $1->Right=$2;
                        $$= $1;
                      }
                    }
                    ;

factor_prefix       : factor_prefix postfix_expr mulop  
                    {
                      $$ = $3;
                      if($1 == NULL) {
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
                    }
                    | %empty  {$$ = NULL;}
                    ;

postfix_expr        : primary   { $$ = $1;}
                    | call_expr { $$ = $1; }
                    ;

call_expr           : id _OPAREN expr_list _CPAREN  {
                                                      $$ = new CallNode($3, *$1, ASTNodeType::CALL_EXPR);
                                                    }
                    ;

expr_list           : expr expr_list_tail {
                                            $$ = $2;   
                                            $$->insert($$->begin(), $1);
                                          }
                    | %empty  { $$ = new std::vector<ASTNode *>; }
                    ;

expr_list_tail      : _COMMA expr expr_list_tail  { $$ = $3;  $$->insert($$->begin(), $2); }
                    | %empty  { $$ = new std::vector<ASTNode *>; }
                    ;

primary             : _OPAREN expr _CPAREN  { $$ = $2; }
                    | id  { $$ = new VarRefNode(*$1, ASTNodeType::VAR_REF); }
                    | _INTLITERAL { $$ = new LiteralNode(LiteralType::isINT, *(new std::string(yytext)), ASTNodeType::LITERAL);} 
                    | _FLOATLITERAL { $$ = new LiteralNode(LiteralType::isFLOAT, *(new std::string(yytext)), ASTNodeType::LITERAL); }
                    ;

addop               : _PLUS { $$ = new AddExprNode("+", ASTNodeType::ADD_EXPR); }
                    | _MINUS  { $$ = new AddExprNode("-", ASTNodeType::ADD_EXPR); }
                    ;

mulop               : _MUL  { $$ = new MulExprNode("*", ASTNodeType::MULT_EXPR); }
                    | _DIV{ $$ = new MulExprNode("/", ASTNodeType::MULT_EXPR); }
                    ;

/* Complex Statements and Condition */ 
if_stmt             : _IF _OPAREN cond _CPAREN decl
                    {
                      currentBlockID = scope_iterator;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                      $<if_node>$ = new IfNode($3->left_expr, $3->right_expr, currentBlockID, $3->jtype, ASTNodeType::IF);
                    }
                    stmt_list
                    {
                      ststack.pop();
                    } 
                    else_part _ENDIF  
                    {            
                      //std::cout << "Stmt List Address: " << $7 << std::endl;
                      //std::cout << "Else Address: " << $9 << std::endl;
                      //if (!$7->empty()){
                        $<if_node>6->copyStmtList(*$7);
                      //}else if ($9 != NULL){
                        $<if_node>6->copyElseNode( (ElseNode *) $9);
                     // }
                      $$ = $<if_node>6;
                    };

else_part           : _ELSE decl  
                    { 
                      currentBlockID = scope_iterator;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                      $<else_node>$ = new ElseNode(currentBlockID, ASTNodeType::ELSE);
                    } 
                    stmt_list  
                    {
                      ststack.pop();
                      $<else_node>3->copyStmtList(*$4);
                      $$ = $<else_node>3;
                    }
                    | %empty  { $$ = NULL; }
                    ;

cond                : expr compop expr 
                                        { 
                                          $$ = new Conditional();
                                          $$->Fill($1, $3, *$2);
                                        }
                    | _TRUE
                              {
                                $$ = NULL;
                                std::cout << "True cond found\n";
                              }
                    | _FALSE
                              {
                                $$ = NULL;
                                std::cout << "False cond found\n";
                              }
                    ;

compop              : _LT 
                            {
                              $$ = new JumpType(JumpType::L_T);
                            }
                    | _GT 
                            {
                              $$ = new JumpType(JumpType::G_T);
                            }
                    | _EQ 
                            {
                              $$ = new JumpType(JumpType::E_Q);
                            }
                    | _NEQ 
                            {
                              $$ = new JumpType(JumpType::N_E);
                            }
                    | _LEQ 
                            {
                              $$ = new JumpType(JumpType::L_E);
                            }
                    | _GEQ
                            {
                              $$ = new JumpType(JumpType::G_E);
                            }
                    ;

while_stmt          : _WHILE _OPAREN cond _CPAREN decl 
                    { 
                      currentBlockID = scope_iterator;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                      $<while_node>$ = new WhileNode($3->left_expr, $3->right_expr, currentBlockID, $3->jtype, ASTNodeType::WHILE);
                    } 
                    stmt_list _ENDWHILE  
                    {  
                      ststack.pop(); 
                      $<while_node>6->copyStmtList(*$7);
                      $$ = $<while_node>6;
                    }
                    ;

/*ECE468 ONLY*/
control_stmt        : return_stmt {$$ = $1;}
                    ;

loop_stmt           : while_stmt  {$$ = $1;}
                    ;

%%
