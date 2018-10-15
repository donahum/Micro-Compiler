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
    if ( argc > 1 ){
        yyin = fopen( argv[1], "r" );
    }
    else{
        yyin = stdin;
    }
    yyparse();
    int error = 0;
    const char * errorID = "";
    for(std::vector<int>::size_type i = 0; i != tableVector.size(); ++i)
    {
        for(std::vector<int>::size_type j = 0; j != tableVector.at(i)->vec.size(); ++j)
        {
            for(std::vector<int>::size_type k = 0; k != tableVector.at(i)->vec.size(); ++k)
            {
                //std::cout << "First: " << tableVector.at(i)->vec.at(j).getName().c_str() << std::endl;
                //std::cout << "Second: " << tableVector.at(i)->vec.at(k).getName().c_str() << std::endl;
                //std::cout << "J: " << j << std::endl;
                //std::cout << "K: " << k << std::endl;

                if( !std::strcmp(tableVector.at(i)->vec.at(j).getName().c_str(), tableVector.at(i)->vec.at(k).getName().c_str() ) )
                {
                    //std::cout << (j != k) << std::endl;
                    if(j != k)
                    {
                        error = 1;
                        errorID = tableVector.at(i)->vec.at(j).getName().c_str();
                        goto PrintError;
                    }
                }
            }
        }
    }

    /*if(!error){
        for(std::vector<int>::size_type i = 0; i != tableVector.size(); ++i)
        {
            if(i != 0){
                //std::cout << std::endl;
            }
            tableVector.at(i)->printST();
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }*/

    if(error){
        PrintError:
            printf("DECLARATION ERROR %s\n", errorID);
    }   
    /*if(!yyparse()){
        printf("Accepted\n");
    }else{
        printf("Not Accepted\n");
    }*/
    
    return 0;
}