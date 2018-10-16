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
%}



%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN    
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK     _ASSIGN _NEQ _LEQ _GEQ
%token  _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA
%token _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _INT _VOID _STRING _FLOAT  _MUL _DIV _PLUS _MINUS

%type <s> id str var_type any_type
%type <str_list> id_list id_tail 
%type <node> expr_prefix factor factor_prefix postfix_expr expr primary expr_list expr_list_tail call_expr addop mulop assign_expr
%type <node> if_stmt stmt base_stmt loop_stmt read_stmt write_stmt control_stmt return_stmt assign_stmt else_part while_stmt func_decl
%type <ast_list> stmt_list func_body func_declarations pgm_body 

%union{
  std::string* s;
  std::list<std::string> * str_list;
  ASTNode * node;
  std::list<ASTNode*> * ast_list;
}


%%
/* Program */
program             : _PROGRAM id _BEGIN
                    {
                      global = new SymbolTable("GLOBAL", NULL);
                      ststack.push(global);
                    } pgm_body _END 
                    {
                      global->printST();
                      for(auto func : *$5){
                        func -> TO_IR();
                      }
                    }
                    ;

id                  : _IDENTIFIER { $$ = new std::string(yytext);}
                    ;

pgm_body            : decl func_declarations { $$ = $2; }
                    ;

decl                : string_decl decl
                    | var_decl decl
                    | %empty 
                    ;

/* Global String Declaration */
string_decl         : _STRING id _ASSIGN str _SEMICOLON 
                    {
                      SymbolTableEntry* tmp = new SymbolTableEntry(*$2, "STRING", *$4);
                      ststack.top()->addEntry(tmp);
                    }
                    ;

str                 : _STRINGLITERAL  { $$ = new std::string(yytext);}
                    ;

/* Variable Declaration */

var_decl            : var_type id_list _SEMICOLON 
                    { 
                      for(auto &varName : *$2){
                        SymbolTableEntry * varEntry = new SymbolTableEntry(varName, *$1);
                        ststack.top()->addEntry(varEntry);
                      }
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
param_decl_list     : param_decl param_decl_tail
                    | %empty      
                    ;

param_decl          : var_type id 
                    {
                      SymbolTableEntry* tmp = new SymbolTableEntry(*$2, *$1);
                      ststack.top()->addEntry(tmp);
                    }
                    ;

param_decl_tail     : _COMMA param_decl param_decl_tail
                    | %empty
                    ;

/* Function Declarations */
func_declarations   : func_decl func_declarations 
                    {
                      $$ = $2;
                      $$->push_front($1);
                    }  
                    | %empty  {$$ = new std::list<ASTNode *>;}
                    ;

func_decl           : _FUNCTION any_type id _OPAREN 
                    {
                      SymbolTable* tmp = new SymbolTable(*$3, ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                    } 
                    param_decl_list _CPAREN _BEGIN func_body _END   
                    {
                      $$ = new FuncNode(*$3, $9, ststack.top(), ASTNodeType::FUNC);
                      ststack.pop();
                    }
                    ;

func_body           : decl stmt_list  {$$ = $2;}
                    ;

/* Statement List */
stmt_list           : stmt stmt_list  
                    {   
                      $$ = $2;
                      $$->push_front($1);
                    }
                    | %empty  {$$ = new std::list<ASTNode*>;}
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
                    }
                    ;

read_stmt           : _READ _OPAREN id_list _CPAREN _SEMICOLON {$$ = NULL;}
                    ;

write_stmt          : _WRITE _OPAREN id_list _CPAREN _SEMICOLON {$$ = NULL;}
                    ;

return_stmt         : _RETURN expr _SEMICOLON{$$ = NULL;}
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
                    | call_expr { $$ = NULL; }
                    ;

call_expr           : id _OPAREN expr_list _CPAREN  {$$ = NULL;}
                    ;

expr_list           : expr expr_list_tail {$$ = NULL;}
                    | %empty  { $$ = NULL; }
                    ;

expr_list_tail      : _COMMA expr expr_list_tail  { $$ = NULL; }
                    | %empty  { $$ = NULL; }
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
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                    }
                    stmt_list
                    {
                      ststack.pop();
                    } 
                    else_part _ENDIF  
                    {               
                      $$ = NULL;
                    }
                    ;

else_part           : _ELSE decl  
                    { 
                      //std::cout << "Else Scope It: " << scope_iterator << std::endl;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                    } 
                    stmt_list  
                    {
                      ststack.pop();
                    }
                    | %empty  { $$ = NULL; }
                    ;

cond                : expr compop expr 
                    | _TRUE 
                    | _FALSE
                    ;

compop              : _LT 
                    | _GT 
                    | _EQ 
                    | _NEQ 
                    | _LEQ 
                    | _GEQ
                    ;

while_stmt          : _WHILE _OPAREN cond _CPAREN decl 
                    { 
                      // std::cout << "Else Scope It: " << scope_iterator << std::endl;
                      SymbolTable* tmp = new SymbolTable("BLOCK " + std::to_string(scope_iterator++), ststack.top());
                      ststack.top()->children.push_back(tmp);
                      ststack.push(tmp);
                    } 
                    stmt_list _ENDWHILE  
                    {  
                      ststack.pop(); 
                      $$ = NULL;
                    }
                    ;

/*ECE468 ONLY*/
control_stmt        : return_stmt {$$ = $1;}
                    ;

loop_stmt           : while_stmt  {$$ = $1;}
                    ;

%%
