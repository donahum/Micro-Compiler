%{
    #include "../generated/parser.hpp"
    extern char * yytext;
    //extern YYSTYPE * yylval;
%}

%option noyywrap
%option yylineno

IDENTIFIER          (?i:[a-z][a-z0-9]*)
INTLITERAL          [0-9]+
FLOATLITERAL        ([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*)
STRINGLITERAL       \"[^\"]*\"
COMMENT             --.*
EATUPWHITESPACE     [ \t\r\n]+

%%

{EATUPWHITESPACE}   { ; }

{COMMENT}           { ; }

"PROGRAM"           { yylval.s = strdup(yytext);return _PROGRAM; }
"BEGIN"             { return _BEGIN; }
"END"               { return _END; }
"FUNCTION"          { return _FUNCTION; }
"READ"              { return _READ; }
"WRITE"             { return _WRITE; }
"IF"                { return _IF; }
"ELSE"              { return _ELSE; }
"ENDIF"             { return _ENDIF; }
"WHILE"             { return _WHILE; }
"ENDWHILE"          { return _ENDWHILE; }
"RETURN"            { return _RETURN; }
"INT"               { yylval.s = strdup(yytext); return _INT; }
"VOID"              { yylval.s = strdup(yytext); return _VOID; }
"STRING"            { yylval.s = strdup(yytext); return _STRING; }
"FLOAT"             { yylval.s = strdup(yytext); return _FLOAT; }
"TRUE"              { return _TRUE; }
"FALSE"             { return _FALSE; }

{IDENTIFIER}        { yylval.s = strdup(yytext);return _IDENTIFIER; }

{STRINGLITERAL}     { yylval.s = strdup(yytext); return _STRINGLITERAL; }

{FLOATLITERAL}      { yylval.s = strdup(yytext); return _FLOATLITERAL; }

{INTLITERAL}        { yylval.s = strdup(yytext); return _INTLITERAL; }

":="                { return _ASSIGN; }
"!="                { return _NEQ; }
"<="                { return _LEQ; }
">="                { return _GEQ; }
"+"                 { yylval.s = strdup(yytext);return _PLUS; }
"-"                 { yylval.s = strdup(yytext);return _MINUS; }
"*"                 { yylval.s = strdup(yytext);return _MUL; }
"/"                 { yylval.s = strdup(yytext);return _DIV; }
"="                 { return _EQ; }
"<"                 { return _LT; }
">"                 { return _GT; }
"("                 { return _OPAREN; }
")"                 { return _CPAREN; }
";"                 { return _SEMICOLON; }
","                 { return _COMMA; }


%%

