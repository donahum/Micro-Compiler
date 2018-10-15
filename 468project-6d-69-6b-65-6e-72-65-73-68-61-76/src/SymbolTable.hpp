#ifndef STE_H
#define STE_H
#include "SymbolTableEntry.hpp"
#endif

//#include "SymbolTableEntry.hpp"

#include <iostream>
#include <vector>

class SymbolTable
{
	public:
		std::map<std::string, SymbolTableEntry*> table;
		std::vector<SymbolTableEntry*> ordered_table;
		SymbolTable* parent;
		std::vector<SymbolTable*> children;
		std::string scope; 

		SymbolTable(std::string s, SymbolTable* p): scope(s), parent(p){}
		void addEntry(SymbolTableEntry * newEntry);
		void printST();
		
	private:
		std::string scope;	//global, func x, block x, etc
};