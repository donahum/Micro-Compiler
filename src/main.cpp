#include <iostream>
#include "../generated/parser.hpp" 
extern int yylex();
extern char * yytext;
extern FILE * yyin;

int main(int argc, char **argv){
    if ( argc > 1 )
        yyin = fopen( argv[1], "r" );
    else
        yyin = stdin;

    int TOKEN = yylex();
    while(TOKEN != 0){
        std::cout<<"Token Type: ";
        switch(TOKEN){
            case    _PROGRAM:
            case    _BEGIN:
            case    _END:
            case    _FUNCTION:
            case    _READ:
            case    _WRITE:
            case    _IF:
            case    _ELSE:
            case    _ENDIF:
            case    _WHILE:
            case    _ENDWHILE:
            case    _RETURN:
            case    _INT:
            case    _VOID:
            case    _STRING:
            case    _FLOAT:
            case    _TRUE:
            case    _FALSE:
            case    _FOR:
            case    _ENDFOR:
            case    _CONTINUE:
            case    _BREAK:
                std::cout<<"KEYWORD";
                break;
            case    _IDENTIFIER:
                std::cout<<"IDENTIFIER";
                break;
            case    _STRINGLITERAL:
                std::cout<<"STRINGLITERAL";
                break;
            case    _FLOATLITERAL:
                std::cout<<"FLOATLITERAL";
                break;
            case    _INTLITERAL:
                std::cout<<"INTLITERAL";
                break;
            case    _ASSIGN:
            case    _NEQ:
            case    _LEQ:
            case    _GEQ:
            case    _PLUS:
            case    _MINUS:
            case    _MUL:
            case    _DIV:
            case    _EQ:
            case    _LT:
            case    _GT:
            case    _OPAREN:
            case    _CPAREN:
            case    _SEMICOLON:
            case    _COMMA:
                std::cout<<"OPERATOR";
                break;
        }
        std::cout<<"\nValue: "<<yytext<<"\n";
        TOKEN = yylex();
    }
    return 0;
}