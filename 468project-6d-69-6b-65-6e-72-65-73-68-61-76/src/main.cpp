#include <iostream>
#include <cstring>
#include "../generated/parser.hpp" 
extern int yylex();
extern char * yytext;
extern FILE * yyin;
extern std::vector<SymbolTable *> tableVector;

#include "SymbolTable.hpp"

int main(int argc, char **argv){
    if ( argc > 1 ){
        yyin = fopen( argv[1], "r" );
    }
    else{
        yyin = stdin;
    }
    yyparse();
    
    return 0;
}