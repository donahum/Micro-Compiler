%{
    #include "../generated/parser.hpp"
    extern char* yytext;
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

"PROGRAM"           { return _PROGRAM; }
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
"INT"               { return _INT; }
"VOID"              { return _VOID; }
"STRING"            { return _STRING; }
"FLOAT"             { return _FLOAT; }
"TRUE"              { return _TRUE; }
"FALSE"             { return _FALSE; }

"FOR"               { return _FOR; /*573 Only*/}
"ENDFOR"            { return _ENDFOR; /*573 Only*/}
"CONTINUE"          { return _CONTINUE; /*573 Only*/}
"BREAK"             { return _BREAK; /*573 Only*/}

{IDENTIFIER}        { return _IDENTIFIER; }

{STRINGLITERAL}     { return _STRINGLITERAL; }

{FLOATLITERAL}      { return _FLOATLITERAL; }

{INTLITERAL}        { return _INTLITERAL; }

":="                { return _ASSIGN; }
"!="                { return _NEQ; }
"<="                { return _LEQ; }
">="                { return _GEQ; }
"+"                 { return _PLUS; }
"-"                 { return _MINUS; }
"*"                 { return _MUL; }
"/"                 { return _DIV; }
"="                 { return _EQ; }
"<"                 { return _LT; }
">"                 { return _GT; }
"("                 { return _OPAREN; }
")"                 { return _CPAREN; }
";"                 { return _SEMICOLON; }
","                 { return _COMMA; }


%%

