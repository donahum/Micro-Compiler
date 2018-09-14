
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
        //printf("Error Line %d token %s\n",yylineno,yytext);
    }
%}

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _ENDIF _WHILE _ENDWHILE _RETURN _INT _VOID _STRING _FLOAT
%token _TRUE _FALSE _FOR _ENDFOR _CONTINUE _BREAK _IDENTIFIER _STRINGLITERAL _FLOATLITERAL _INTLITERAL _ASSIGN _NEQ _LEQ _GEQ
%token _PLUS _MINUS _MUL _DIV _EQ _LT _GT _OPAREN _CPAREN _SEMICOLON _COMMA

%%
/* Program */
program           : _PROGRAM id _BEGIN pgm_body _END;
id                : _IDENTIFIER;
pgm_body          : decl func_declarations;
decl                : string_decl decl | var_decl decl | %empty;

/* Global String Declaration */
string_decl       : _STRING id _ASSIGN str _SEMICOLON;
str               : _STRINGLITERAL;

/* Variable Declaration */
var_decl          : var_type id_list _SEMICOLON;
var_type            : _FLOAT | _INT;
any_type          : var_type | _VOID;
id_list           : id id_tail;
id_tail           : _COMMA id id_tail | %empty;

/* Function Paramater List */
param_decl_list   : param_decl param_decl_tail | %empty;
param_decl        : var_type id;
param_decl_tail   : _COMMA param_decl param_decl_tail | %empty;

/* Function Declarations */
func_declarations : func_decl func_declarations | %empty;
func_decl         : _FUNCTION any_type id _OPAREN param_decl_list _CPAREN _BEGIN func_body _END;
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
if_stmt           : _IF _OPAREN cond _CPAREN decl stmt_list else_part _ENDIF;
else_part         : _ELSE decl stmt_list | %empty;
cond              : expr compop expr | _TRUE | _FALSE;
compop            : _LT | _GT | _EQ | _NEQ | _LEQ | _GEQ;
while_stmt        : _WHILE _OPAREN cond _CPAREN decl stmt_list _ENDWHILE;


/*ECE468 ONLY*/
control_stmt      : return_stmt;
loop_stmt         : while_stmt;

%%
