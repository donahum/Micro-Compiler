
%{
    #include <stdio.h>
    #include <string>
    #include <vector>
    #include <list>
    #include <stack>
    extern int yylex();
    extern int yylineno;
    extern char * yytext;
    void yyerror(const char * s) {
        printf("Error Line %d token %s\n",yylineno,yytext);
    }
%}

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN _INT _VOID _STRING _FLOAT
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _ASSIGN _NEQ _LEQ _GEQ
%token _PLUS _MINUS _MUL _DIV _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA

%%
//strings
string_decl : _STRING _IDENTIFIER _ASSIGN _STRINGLITERAL _SEMICOLON;
//other variables
/*
var_type : _FLOAT | _INT;
any_type : var_type | _VOID;
id_tail : _COMMA _IDENTIFIER id_tail | %empty;
id_list : _IDENTIFIER id_tail;
var_decl : var_type id_list _SEMICOLON
decl : string_decl decl | var_decl decl | %empty;
*/
//statements
/*
expr_list_tail : 
expr_list : expr expr_list_tail | %empty;
call_expr : _IDENTIFIER _OPAREN expr_list _CPAREN
primary : _OPAREN expr _CPAREN | _IDENTIFIER | _INTLITERAL | _FLOATLITERAL;
postfix_expr : primary | call_expr;
factor_prefix : factor_prefix postfix_expr _MUL | %empty;
factor : factor_prefix postfix_expr;
expr_prefix : expr_prefix factor _PLUS | %empty;
expr : expr_prefix factor;
assign_expr : _IDENTIFIER _ASSIGN expr _SEMICOLON;
//functions
param_decl_list : param_decl param_decl_tail | %empty;
param_decl : var_type _IDENTIFIER;
param_decl_tail : _COMMA param_decl param_decl_tail | %empty;
func_decl : _FUNCTION any_type _IDENTIFIER _OPAREN param_decl_list _CPAREN _BEGIN func_body END;
func_decl_tail : func_decl func_decl_tail | %empty;
func_body : decl stmt_list;
//program
pgm_body : decl func_declarations;
program : _PROGRAM _IDENTIFIER _BEGIN pgm_body _END;
*/

%%