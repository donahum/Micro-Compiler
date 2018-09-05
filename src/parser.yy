
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

program : _IDENTIFIER;

%%