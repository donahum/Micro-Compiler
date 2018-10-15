#ifndef ST_H
#define ST_H

#include <iostream>
#include <vector>
#include <map>

#include "SymbolTableEntry.hpp"

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
};

#endif