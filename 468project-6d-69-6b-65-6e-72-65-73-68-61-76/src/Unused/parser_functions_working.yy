
%{
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <list>
    #include <stack>
    extern int yylex();
    extern int yylineno;
    extern char * yytext;
    void yyerror(const char * s) {
        //printf("Error Line %d token %s\n",yylineno,yytext);
    }
%}

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN _INT _VOID _STRING _FLOAT
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _ASSIGN _NEQ _LEQ _GEQ
%token _PLUS _MINUS _MUL _DIV _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA

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

//%type <s_entry> string_decl
%type <s> id str var_type _STRINGLITERAL any_type id_list id_tail

%union{
  SymbolTableEntry * s_entry;
  char * s;   //char *
}

%{
    SymbolTable currTable = SymbolTable();// = SymbolTable("GLOBAL");
    SymbolTable funcTable = SymbolTable();
    SymbolTable ifTable = SymbolTable();
    SymbolTable elseTable = SymbolTable();
    SymbolTable whileTable = SymbolTable();
    int scope_iterator = 0;
    char * curr_type = "fLoAt";
    std::vector<SymbolTable> tableVector;
%}

%%
/* Program */
program           : _PROGRAM id _BEGIN pgm_body _END {  //std::cout << "Got to program\n";
                                                        //currTable.setScope("GLOBAL");
                                                        //currTable.printST();
                                                        //tableVector.insert(tableVector.begin(), currTable);
                                                     };
id                : _IDENTIFIER{$$ = $<s>1;};
pgm_body          : decl {currTable.setScope("GLOBAL");tableVector.insert(tableVector.begin(), currTable);} func_declarations;
decl              : string_decl {$<s_entry>$ = $<s_entry>1;} decl; 
                    | var_decl  {$<s_entry>$ = $<s_entry>1;} decl;
                    | %empty         {/*std::cout << "Found nothing in decl\n";*/};

/* Global String Declaration */
string_decl       : _STRING id _ASSIGN str _SEMICOLON { //std::cout << "str decl " << $<s>1 << " " << $<s>2 << " " << $<s>4 << std::endl;
                                                        $<s_entry>$ = new SymbolTableEntry($<s>2, $<s>1, $<s>4);
                                                        currTable.addEntry($<s_entry>$);
                                                        //std::cout << "new STE passed\n";
                                                        //$<s_entry>$ = *newEntry;
                                                        //currTable.addEntry(newEntry);
                                                      };
str               : _STRINGLITERAL {$$ = $<s>1;};

/* Variable Declaration */
var_decl          : var_type id_list _SEMICOLON {//std::cout << "var decl " << $<s>1 << " " << $<s>2 << std::endl;
                                                 $<s_entry>$ = new SymbolTableEntry($<s>1, $<s>2);
                                                 //$<s_entry>$ = *newEntry;
                                                 //currTable.addEntry(newEntry);
                                                 };  //adds symbol name and type to symbol table

var_type          : _FLOAT {$$ = $<s>1; 
                            curr_type = $<s>1;
                            };
                    | _INT {$$ = $<s>1; 
                            curr_type = $<s>1;
                           };                      //chooses b/w types
any_type          : var_type {  $$ = $<s>1; 
                                curr_type = $<s>1;
                             }; 
                    | _VOID  {  $$ = $<s>1;
                                curr_type = $<s>1;
                             };                                           
id_list           : id {SymbolTableEntry idEntry = SymbolTableEntry($<s>1, curr_type);  currTable.addEntry(idEntry);} id_tail; 
id_tail           : _COMMA id {SymbolTableEntry idtEntry = SymbolTableEntry($<s>2, curr_type);  currTable.addEntry(idtEntry);} id_tail | %empty;

/* Function Paramater List */
param_decl_list   : param_decl {//std::cout << "param_decl_list\n";
                                /*currTable.addEntry($<s_entry>1); */
                               } param_decl_tail 
                    | %empty   {/*std::cout << "empty param_decl_list\n";*/};

param_decl        : var_type id {//std::cout << "param_decl " << $<s>1 << $<s>2 << std::endl;  
                                 SymbolTableEntry newEntry = SymbolTableEntry($<s>2, $<s>1);
                                 funcTable.addEntry(newEntry);
                                 /*funcTable.printST();*/  
                                 /*std::cout << $<s>1 << " " << $<s>2 << "\n";*/
                                };

param_decl_tail   : _COMMA param_decl {//funcTable.addEntry($<s_entry>2);
                                       //std::cout << "param_decl_tail\n";
                                      } param_decl_tail 
                    | %empty          {/*std::cout << "empty param_decl_tail\n";*/};

/* Function Declarations */
func_declarations : func_decl func_declarations | %empty;
func_decl         : _FUNCTION any_type id {SymbolTable funcTable = SymbolTable($<s>3);} _OPAREN param_decl_list _CPAREN _BEGIN func_body _END {funcTable.setScope($<s>3);//funcTable.printST();
                                                                                                                                               tableVector.push_back(funcTable);
                                                                                                                                               funcTable = SymbolTable();
                                                                                                                                              };
func_body         : decl stmt_list;

/* Statement List */
stmt_list         : stmt stmt_list | %empty;
stmt              : base_stmt | if_stmt | loop_stmt;
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
if_stmt           : _IF {std::string newString = std::to_string(static_cast<long long>(scope_iterator)); 
                         ++scope_iterator;
                        } 
                    _OPAREN cond _CPAREN decl {ifTable.addEntry($<s_entry>4);} stmt_list {

                                                        } else_part _ENDIF;
else_part         : _ELSE decl stmt_list | %empty;
cond              : expr compop expr | _TRUE | _FALSE;
compop            : _LT | _GT | _EQ | _NEQ | _LEQ | _GEQ;
while_stmt        : _WHILE _OPAREN cond _CPAREN decl stmt_list _ENDWHILE;


/*ECE468 ONLY*/
control_stmt      : return_stmt;
loop_stmt         : while_stmt;

%%
