#include <iostream>
#include <cstring>
#include "../generated/parser.hpp" 
extern int yylex();
extern char * yytext;
extern FILE * yyin;
extern std::vector<SymbolTable *> tableVector;

#ifndef ST_H
#define ST_H
#include "SymbolTable.hpp"
#endif

#ifndef STE_H
#define STE_H
#include "SymbolTableEntry.hpp"
#endif

int main(int argc, char **argv){
    if ( argc > 1 )
        yyin = fopen( argv[1], "r" );
    else
        yyin = stdin;



        //std::cout<<"\nValue: "<<yytext<<"\n";
        if(!yyparse()){
            printf("Accepted\n");
        }else{
            printf("Not Accepted\n");
        }

    
    return 0;
}
