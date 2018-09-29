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

        if(!yyparse()){
            printf("Accepted\n");
        }else{
            printf("Not Accepted\n");
        }
    
    return 0;
}