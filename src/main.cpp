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
extern int availableTemp;

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
    std::cout << "\n\n;IR code" << std::endl;
    //std::cout << ";PUSH" << std::endl;
    //std::cout << ";JSR FUNC_main" << std::endl;
    //std::cout << ";HALT" << std::endl;

    ThreeAC main_tiny = ThreeAC();
    main_tiny.Fill("HALT", "", "", "");
    IR.insert(IR.begin(), main_tiny);
    main_tiny.Clear();

    main_tiny.Fill("JSR", "FUNC_main", "", "");
    IR.insert(IR.begin(), main_tiny);
    main_tiny.Clear();

    main_tiny.Fill("PUSH", "", "", "");
    IR.insert(IR.begin(), main_tiny);
    main_tiny.Clear();

    for(std::vector<ThreeAC>::iterator it = IR.begin(); it != IR.end(); ++it)
    {
        printIR(*it);
    }

    //print Tiny Code!
    //print var declarations first (all global for this step)
    SymbolTable * stackTop = ststack.top();
    std::vector<SymbolTableEntry *>::iterator rit = stackTop->ordered_table.begin();
    for(; rit != stackTop->ordered_table.end(); ++rit){
    //for(auto ste : stackTop->ordered_table){
        if((*rit)->type == "STRING"){
            std::cout << "str " << (*rit)->name << " " << (*rit)->value << std::endl;
        }else{
            std::cout << "var " << (*rit)->name << std::endl;
        }
    }

    for(std::vector<ThreeAC>::iterator it = IR.begin(); it != IR.end(); ++it)
    {
        toTinyCode(*it);
    }

    //std::cout << "unlnk" << std::endl;
    //std::cout << "ret" << std::endl;
    
    //fclose(yyin);
    
    return 0;
}

//intermediate representation code
void printIR(ThreeAC toPrint)
{
    int i = 0;
    if(toPrint.opcode == "ADDI"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 1;
    }else if(toPrint.opcode == "ADDF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 2;
    }else if(toPrint.opcode == "SUBI"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 3;
    }else if(toPrint.opcode == "SUBF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 4;
    }else if(toPrint.opcode == "MULI"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 5;
    }else if(toPrint.opcode == "MULF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 6;
    }else if(toPrint.opcode == "DIVI"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 7;
    }else if(toPrint.opcode == "DIVF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 8;
    }else if(toPrint.opcode == "STOREI"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.result << std::endl;
        i = 9;
    }else if(toPrint.opcode == "STOREF"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << " " << toPrint.result << std::endl;
        i = 10;
    }else if(toPrint.opcode == "READI"){
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.result << std::endl;
        i = 11;
    }else if(toPrint.opcode == "READF"){
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.result << std::endl;
        i = 12;
    }else if(toPrint.opcode == "LABEL"){
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.op1 << std::endl;
        i = 13;
    }else if(toPrint.opcode == "LINK"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << std::endl;
        i = 14;
    }else if(toPrint.opcode == "PUSH"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << std::endl;
        i = 15;
    }else if(toPrint.opcode == "PUSHREGS"){
        std::cout << ";" << toPrint.opcode << std::endl;
        i = 16;
    }else if(toPrint.opcode == "JSR"){
        std::cout << ";" << toPrint.opcode << " " << toPrint.op1 << std::endl;
        i = 17;
    }else if(toPrint.opcode == "HALT"){
        std::cout << ";" << toPrint.opcode << std::endl;
        i = 18;
    }else if(toPrint.opcode == "UNLINK"){
        std::cout << ";" << toPrint.opcode << std::endl;
        i = 19;
    }else if(toPrint.opcode == "RET"){
        std::cout << ";" << toPrint.opcode << std::endl;
        i = 20;
    }else{  //writes
        std::cout << ";" << toPrint.opcode <<  " " << toPrint.op1 << " " << toPrint.op2 << " " << toPrint.result << std::endl;
        i = 21;
    }
    //std::cout << ";Test case: " << i << std::endl;
}

//Tiny Assembler code
void toTinyCode(ThreeAC toTiny)
{
        if(toTiny.opcode ==  "LEI"){
            std::cout << "cmpi " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jle " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "LTI"){
            std::cout << "cmpi " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jlt " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "GEI"){
            std::cout << "cmpi " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jge " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "GTI"){
            std::cout << "cmpi " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jgt " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "EQI"){
            std::cout << "cmpi " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jeq " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "NEI"){
            std::cout << "cmpi " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jne " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "LEF"){
            std::cout << "cmpr " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jle " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "LTF"){
            std::cout << "cmpr " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jlt " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "GEF"){
            std::cout << "cmpr " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jge " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "GTF"){
            std::cout << "cmpr " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jgt " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "EQF"){
            std::cout << "cmpr " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jeq " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "NEF"){
            std::cout << "cmpr " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.op2) << std::endl;
            std::cout << "jne " << toTiny.result << std::endl;
        }
        else if(toTiny.opcode ==  "JUMP"){
            std::cout << "jmp " << formatTemp(toTiny.op1) << std::endl;
        }
        else if(toTiny.opcode == "LABEL"){
            std::cout << "label " << formatTemp(toTiny.op1) << std::endl;
        }
        else if(toTiny.opcode == "LINK"){
            std::cout << "link " << toTiny.op1 <<std::endl;
        }
        else if(toTiny.opcode == "PUSH" && toTiny.opcode != "PUSHREGS"){
            std::cout << "push " << formatTemp(toTiny.op1) << std::endl;
        }
        else if(toTiny.opcode == "JSR"){
            std::cout << "jsr " << toTiny.op1 << std::endl;
        }
        else if(toTiny.opcode == "HALT"){
            std::cout << "sys halt" << std::endl;
        }else if(toTiny.opcode == "STOREI"){
            std::cout << "move " << formatTemp(toTiny.op1) << " " << formatTemp(toTiny.result) << std::endl;
        }else if(toTiny.opcode == "STOREF"){
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
        else if(toTiny.opcode == "UNLINK"){
            std::cout << "unlnk"  << std::endl;
        }else if(toTiny.opcode == "RET"){
            std::cout << "ret" << std::endl;
        }else if(toTiny.opcode == "POP"){
            std::cout << "pop " << formatTemp(toTiny.result) << std::endl;
        }
}

//converts any temporaries into registers
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
