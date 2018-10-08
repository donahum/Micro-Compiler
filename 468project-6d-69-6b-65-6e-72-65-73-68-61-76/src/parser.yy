
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
    //#include "../src/SymbolTable.cpp"
    //#pragma once
    #ifndef STE_H
    #define STE_H
    #include "../src/SymbolTableEntry.hpp"
    #endif
    //#include "../src/SymbolTableEntry.cpp"
}

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN    
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK     _ASSIGN _NEQ _LEQ _GEQ
%token _PLUS _MINUS _MUL _DIV _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA

%token <s> _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _INT _VOID _STRING _FLOAT

%type <s> id str var_type any_type
%type <s_table> decl  var_decl param_decl_tail param_decl_list   
%type <s_entry> string_decl param_decl
%type <str_list> id_list id_tail
%type <st_list> func_declarations if_stmt stmt stmt_list func_body func_decl else_part loop_stmt while_stmt

%union{
  SymbolTableEntry * s_entry;
  char * s;
  SymbolTable * s_table;
  std::vector<SymbolTable *> * st_list;
  std::vector<char *> * str_list;
}

%{
    long long scope_iterator = 1;
    std::vector<SymbolTable *> tableVector;
%}

%%
/* Program */
program           : _PROGRAM id _BEGIN pgm_body _END {
                                                        
                                                     };
id                : _IDENTIFIER { $$ = $1; 
                                  //printf("Base Identifer: %s\n", $1);
                                };

pgm_body          : decl func_declarations  {
                                              tableVector = std::vector<SymbolTable *>();;
                                              $1->setScope("GLOBAL");
                                              tableVector.push_back($1);
                                              //$1->printST();
                                              for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                              {
                                                  tableVector.push_back($2->at(i));
                                                  //$2->at(i)->printST();
                                              };
                                            };

decl                : string_decl decl {  /*if( std::find($2->vec.begin(), $2->vec.end(), $1->getName()) != $2->vec.end()){
                                              yyerror(($1->getName()));
                                          };*/
                                          /*for(std::vector<int>::size_type i = 0; i != $2->vec.size(); ++i)
                                          {
                                              if($1->getName() == $2->vec.at(i).getName().c_str())
                                              {
                                                  yyerror($1->getName().c_str());
                                              };
                                          };*/
                                          $$ = $2;
                                          //$1->printSTE();
                                          //std::cout << std::endl;
                                          $$->addEntryToFront($1);
                                       }; 
                    | var_decl decl { 
                                      /*for(std::vector<int>::size_type j = 0; j != $1->vec.size(); ++j)
                                      {
                                          std::cout << "Var: " << $1->vec.at(j).getName().c_str() << std::endl;
                                      };

                                      for(std::vector<int>::size_type j = 0; j != $1->vec.size(); ++j)
                                      {
                                          std::cout << "Decl: " << $1->vec.at(j).getName().c_str() << std::endl;
                                      };

                                      for(std::vector<int>::size_type j = 0; j != $1->vec.size(); ++j)
                                      {
                                          for(std::vector<int>::size_type i = 0; i != $2->vec.size(); ++i)
                                          {
                                              int equal = std::strcmp($1->vec.at(j).getName().c_str(), $2->vec.at(i).getName().c_str()); //returns 0 if same
                                              //std::cout << "Var: " << $1->vec.at(j).getName().c_str() << std::endl;
                                              //std::cout << "Decl: " << $2->vec.at(i).getName().c_str() << std::endl;
                                              if(!equal)
                                              {
                                                  yyerror($1->vec.at(j).getName().c_str());
                                                  std::cout << "wtf\n";
                                                  return 1;
                                              };
                                          };
                                      };*/
                                      $$ = $2;
                                      $$->copyEntriesFromSTToFront($1);  
                                    };
                    | %empty  {
                                $$ = new SymbolTable();
                              };

/* Global String Declaration */
string_decl       : _STRING id _ASSIGN str _SEMICOLON {
                                                        //printf("Type: %s\n", $1);
                                                        //printf("Name: %s\n", $2);
                                                        //printf("Value: %s\n", $4);
                                                        $$ = new SymbolTableEntry($2, $1, $4);
                                                        //$$->printSTE();
                                                        //std::cout << std::endl;
                                                      };
str               : _STRINGLITERAL  {$$ = $1;
                                    };

/* Variable Declaration */

var_decl          : var_type id_list _SEMICOLON { $$ = new SymbolTable();
                                                  for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                                  {
                                                      char * varName = $2->at(i);
                                                      SymbolTableEntry * varEntry = new SymbolTableEntry(varName, $1);
                                                      $$->addEntry(varEntry);
                                                      //printf("%s\n", $2[i]);
                                                      //printf("%s\n", $1);
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
param_decl_list   : param_decl param_decl_tail  {
                                                    $$ = $2;
                                                    $$->addEntryToFront($1);
                                                    //$1->printSTE();
                                                    //std::cout << std::endl;
                                                    //std::cout << "param_decl_list\n";
                                                }  
                    | %empty    {
                                    //std::cout << "param_decl_list EMPTY\n";
                                    $$ = new SymbolTable();
                                };

param_decl        : var_type id {
                                    $$ = new SymbolTableEntry($2, $1);
                                    //std::cout << "param_decl\n";
                                };

param_decl_tail   : _COMMA param_decl param_decl_tail { 
                                                          $$ = $3;
                                                          $$->addEntryToFront($2);
                                                          //$2->printSTE();
                                                          //std::cout << std::endl;
                                                          //std::cout << "param_decl_tail\n";
                                                      }  
                    | %empty  {
                                $$ = new SymbolTable();
                                //std::cout << "param_decl_tail EMPTY\n";
                              };

/* Function Declarations */
func_declarations : func_decl func_declarations { //std::cout << "func_declarations" << std::endl;
                                                  $$ = $2;
                                                  if($1->size() != 0){
                                                    for(std::vector<int>::size_type i = 0; i != $1->size(); ++i)
                                                    {
                                                        $$->insert($$->begin(),$1->at(i));
                                                    };
                                                  };
                                                  //$1->printST();
                                                  
                                                };  
                    | %empty  {
                                $$ = new std::vector<SymbolTable *>(0);
                                //$$->erase($$->begin(), $$->end());
                                //std::cout << "func_declarations EMPTY" << std::endl;
                              };

func_decl         : _FUNCTION any_type id _OPAREN param_decl_list _CPAREN _BEGIN func_body _END   {
                                                                                                      //std::cout << "func_decl\n";
                                                                                                      $$ = new std::vector<SymbolTable *>(0);
                                                                                                      SymbolTable * localTable = new SymbolTable($3);
                                                                                                      localTable->copyEntriesFromST($5);
                                                                                                      //$5->printST();
                                                                                                      localTable->setScope($3);
                                                                                                      localTable->copyEntriesFromST($8->at(0));
                                                                                                      $$->push_back(localTable);
                                                                                                      
                                                                                                      //localTable->printST();
                                                                                                      //std::cout << "LocalTable Size: " << $8->size() << "\n";

                                                                                                      if($8->size() != 0){
                                                                                                        for(std::vector<int>::size_type i = 1; i != $8->size(); ++i)
                                                                                                        {
                                                                                                            $$->insert($$->begin(),$8->at(i));
                                                                                                        };
                                                                                                      };
                                                                                                      //$8->printST();
                                                                                                      //$$->printST();
                                                                                                  };

func_body         : decl stmt_list  {
                                        //std::cout << "func_body" << std::endl;
                                        $$ = new std::vector<SymbolTable *>(0);
                                        $$->push_back($1);
                                        if($2->size() != 0){
                                          for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                          {
                                              $$->push_back($2->at(i));
                                          };
                                        };
                                    };

/* Statement List */
stmt_list         : stmt stmt_list  {   //std::cout << "stmt_list\n";
                                        //$$ = new std::vector<SymbolTable *>(0);
                                        $$ = $1;
                                        //for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                        //{
                                            
                                        //    $2->at(i)->printST();
                                            //std::cout << "balls" << std::endl;
                                            
                                        //};
                                        //std::cout << "Size: " << $1->size() << std::endl;
                                        //$1->at(0)->printST();
                                        //for(std::vector<int>::size_type i = 0; i != $1->size(); ++i)
                                        //{
                                            
                                        //    $1->at(i)->printST();
                                            //std::cout << "balls" << std::endl;
                                            
                                        //};
                                        
                                        //std::cout << "hasn't failed yet\n";
                                        

                                        /*if($2->size() != 0){
                                          for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                          {
                                              //std::cout << "no fail\n";
                                              $$->insert($$->begin(),$2->at(i));
                                              $2->at(i)->printST();
                                          };
                                        };*/

                                        if($2->size() != 0){
                                          for(std::vector<int>::size_type i = 0; i != $2->size(); ++i)
                                          {
                                              //std::cout << "no fail\n";
                                              $$->insert($$->begin(),$2->at(i));
                                              //$1->at(i)->printST();
                                          };
                                        };
                                        //std::cout << "stmt_list return contents\n";
                                        for(std::vector<int>::size_type i = 0; i != $$->size(); ++i)
                                          {
                                              //$$->at(i)->printST();
                                          };
                                    }
                    | %empty  {
                                  $$ = new std::vector<SymbolTable *>(0);
                                  //std::cout << "stmt_list EMPTY\n";
                              };

stmt              : base_stmt   {
                                    $$ = new std::vector<SymbolTable *>(0);
                                    //std::cout << "base_stmt\n";
                                }
                    | if_stmt   {
                                    $$ = $1;
                                    //std::cout << "if_stmt\n";
                                }
                    | loop_stmt {
                                    $$ = $1;
                                    //std::cout << "loop_stmt\n";
                                };
base_stmt         : assign_stmt | read_stmt | write_stmt | control_stmt;

/* Basic Statements */
assign_stmt       : assign_expr _SEMICOLON;
assign_expr       : id _ASSIGN expr;
read_stmt         : _READ _OPAREN id_list _CPAREN _SEMICOLON;
write_stmt        : _WRITE _OPAREN id_list _CPAREN _SEMICOLON;
return_stmt       : _RETURN expr _SEMICOLON;

/* Expressions */
expr              : expr_prefix factor;
expr_prefix       : expr_prefix factor addop | %empty;
factor            : factor_prefix postfix_expr;
factor_prefix     : factor_prefix postfix_expr mulop | %empty;
postfix_expr      : primary | call_expr;
call_expr         : id _OPAREN expr_list _CPAREN;
expr_list         : expr expr_list_tail | %empty;
expr_list_tail    : _COMMA expr expr_list_tail | %empty;
primary           : _OPAREN expr _CPAREN | id | _INTLITERAL | _FLOATLITERAL;
addop             : _PLUS | _MINUS;
mulop             : _MUL | _DIV;

/* Complex Statements and Condition */ 
if_stmt           : _IF _OPAREN cond _CPAREN decl{  //std::cout << "If Scope It: " << scope_iterator << std::endl;
                                                    $5->setScope("BLOCK " + std::to_string(scope_iterator++));
                                                  } 
                    stmt_list else_part _ENDIF  {   //std::cout << "if\n";
                                                    //$$ = new std::vector<SymbolTable *>(0);
                                                    if($8 != NULL){
                                                        $$ = $8;
                                                    }else{
                                                        $$ = new std::vector<SymbolTable *>(0);
                                                    };
                                                    
                                                    //$5->setScope("BLOCK " + std::to_string(scope_iterator++));
                                                    //$5->printST();

                                                    
                                                    if($7 != NULL){
                                                       if($7->size() != 0){
                                                          for(std::vector<int>::size_type i = 0; i != $7->size(); ++i)
                                                          {
                                                              $$->insert($$->begin(),$7->at(i));
                                                          };
                                                        };
                                                    }
                                                    $$->insert($$->begin(),$5);
                                                    //std::cout << "if return contents:\n";

                                                    for(std::vector<int>::size_type i = 0; i != $$->size(); ++i)
                                                      {
                                                          //std::cout << "printing stmt_list from ELSE\n";
                                                          //$$->at(i)->printST();
                                                      };
                                                };

else_part         : _ELSE decl  { //std::cout << "Else Scope It: " << scope_iterator << std::endl;
                                  $2->setScope("BLOCK " + std::to_string(scope_iterator++));
                                } 
                    stmt_list  {
                                  //$$ = new std::vector<SymbolTable *>(0);
                                  $$ = $4;
                                  
                                  //$2->setScope("BLOCK " + std::to_string(scope_iterator++));
                                  $$->insert($$->begin(),$2);
                                  //std::cout << "else\n";

                                  //td::cout << "else return contents:\n";

                                  for(std::vector<int>::size_type i = 0; i != $$->size(); ++i)
                                    {
                                        //std::cout << "printing stmt_list from ELSE\n";
                                        //$$->at(i)->printST();
                                    };

                                  /*if($3->size() != 0){
                                    for(std::vector<int>::size_type i = 0; i != $3->size(); ++i)
                                    {
                                        //std::cout << "adding to else st list\n";
                                        $$->push_back($3->at(i));
                                    };
                                  };*/
                                }
                    | %empty  {
                                  $$ = NULL;
                                  std::cout << "else EMPTY\n";
                              };

cond              : expr compop expr | _TRUE | _FALSE;
compop            : _LT | _GT | _EQ | _NEQ | _LEQ | _GEQ;
while_stmt        : _WHILE _OPAREN cond _CPAREN decl {$5->setScope("BLOCK " + std::to_string(scope_iterator++));} stmt_list _ENDWHILE  {   //std::cout << "while_stmt\n";
                                                                              //$$ = new std::vector<SymbolTable *>(0);
                                                                              $$ = new std::vector<SymbolTable *>();

                                                                              //$5->setScope("BLOCK " + std::to_string(scope_iterator++));
                                                                              $$->push_back($5);
                                                                              if($7->size() != 0){
                                                                                for(std::vector<int>::size_type i = 0; i != $7->size(); ++i)
                                                                                {
                                                                                    //std::cout << "no fail\n";
                                                                                    $$->push_back($7->at(i));
                                                                                };
                                                                              };
                                                                          };

/*ECE468 ONLY*/
control_stmt      : return_stmt;
loop_stmt         : while_stmt  {$$ = $1;};

%%
