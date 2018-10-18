#include <iostream>
#include <cstring>
#include "../generated/parser.hpp" 
#include "SymbolTable.hpp"
#include "Node.hpp"

//for flex/bison
extern int yylex();
extern char * yytext;
extern FILE * yyin;

//external vars
extern std::stack<SymbolTable*> ststack; 
extern std::vector<ThreeAC> IR;

//function declarations
void printIR(ThreeAC duh);
void toTinyCode(ThreeAC duh2);
std::string formatTemp(std::string);

//global
int tmpyIndex = 0;

int main(int argc, char **argv){
    if ( argc > 1 ){
        yyin = fopen( argv[1], "r" );
    }
    else{
        yyin = stdin;
    }
    yyparse();

    //print IR Code!
    std::cout << ";IR code" << std::endl;

    for(std::vector<ThreeAC>::iterator it = IR.begin(); it != IR.end(); ++it)
    {
        printIR(*it);
    }

    //print Tiny Code!
    //print var declarations first (all global for this step)
    SymbolTable * stackTop = ststack.top();
    for(auto ste : stackTop->ordered_table){
        if(ste->type == "STRING"){
            std::cout << "str " << ste->name << " " << ste->value << std::endl;
        }else{
            std::cout << "var " << ste->name << std::endl;
        }
    }

    for(std::vector<ThreeAC>::iterator it = IR.begin(); it != IR.end(); ++it)
    {
        toTinyCode(*it);
    }

    std::cout << "sys halt" << std::endl;

    fclose(yyin);
    
    return 0;
}

void printIR(ThreeAC toPrint)
{
    if(toPrint.opcode == "ADDI" || "ADDF" || "SUBI" || "SUBF" || "MULI" || "MULF" || "DIVI" || "DIVF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
    }else if(toPrint.opcode == "STOREI" || "STOREF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.result << std::endl;
    }else if(toPrint.opcode == "READI" || "READF"){
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.result << std::endl;
    }else if(toPrint.opcode == "LABEL"){
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.op1 << std::endl;
    }else if(toPrint.opcode == "LINK"){
        std::cout << ";" << toPrint.opcode << std::endl;
    }else{  //writes
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.op1 << std::endl;
    }
}

void toTinyCode(ThreeAC toTiny)
{
    if(toTiny.opcode == "LABEL"){

    }
    else if(toTiny.opcode == "LINK"){
        
    }
    else if(toTiny.opcode == "STOREI" || toTiny.opcode == "STOREF"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "MULI"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "muli " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "MULF"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "mulr " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "ADDI"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "addi " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "ADDF"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "addr " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "SUBI"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "subi " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "SUBF"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "subr " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "DIVI"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "divi " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "DIVF"){
        std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        std::cout << "divr " << formatTemp(toTiny.op2) << " " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "WRITEI"){
        std::cout << "sys writei  " << formatTemp(toTiny.op1) << std::endl;
    }else if(toTiny.opcode == "WRITEF"){
        std::cout << "sys writer  " << formatTemp(toTiny.op1) << std::endl;
    }else if(toTiny.opcode == "WRITES"){
        std::cout << "sys writes  " << formatTemp(toTiny.op1) << std::endl;
    }else if(toTiny.opcode == "READI"){
        std::cout << "sys readi  " << formatTemp(toTiny.result) << std::endl;
    }else if(toTiny.opcode == "READF"){
        std::cout << "sys readr  " << formatTemp(toTiny.result) << std::endl;
    }

}

std::string formatTemp(std::string couldBeTmp)
{
    std::string returnStr = couldBeTmp;
    std::string tmpForm = "!T";
    if(returnStr.find("!T") != std::string::npos)
    {
        returnStr.replace(returnStr.find(tmpForm), tmpForm.length(), "r");
        return(returnStr);
    }else{
        return couldBeTmp;
    }
}