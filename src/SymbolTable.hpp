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
		std::vector<SymbolTableEntry> vec;

		SymbolTable();

		SymbolTable(std::string sc);

		SymbolTable(std::string * sc);

		void addEntry(SymbolTableEntry * newEntry);
		void addEntryToFront(SymbolTableEntry * newEntry);

		void copyEntriesFromST(SymbolTable * srcTable);
		void copyEntriesFromSTToFront(SymbolTable * srcTable);

		void printST();

		std::string getScope();
		void setScope(std::string sc);
		
	private:
		std::string scope;	//global, func x, block x, etc
};