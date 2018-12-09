#ifndef ST_H
#define ST_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>

class SymbolTableEntry
{
public:
	SymbolTableEntry(std::string nm, std::string tp, std::string val);
	SymbolTableEntry(std::string nm, std::string tp, std::string val, int slt);
	SymbolTableEntry(std::string nm, std::string tp);
	SymbolTableEntry(std::string nm, std::string tp, int slt);

	std::string name;
	std::string type;
	std::string value;
	int slot;

	void printSTE();///print the symbol
};

class SymbolTable
{
public:
	SymbolTable(std::string s, SymbolTable* p);

	std::map<std::string, SymbolTableEntry*> table;
	std::vector<SymbolTableEntry*> ordered_table;

	SymbolTable* parent;
	std::vector<SymbolTable*> children;
	std::string scope; 

	int numParams;
	int numLocals;

	void addEntry(SymbolTableEntry * newEntry);
	std::string getTypeFromID(std::string idName);
	int getSlotFromID(std::string idName);
	void printST();
};

#endif 
