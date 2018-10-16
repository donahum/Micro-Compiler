#ifndef ST_H
#define ST_H

#include <iostream>
#include <vector>
#include <map>

class SymbolTableEntry
{
public:
	SymbolTableEntry(std::string nm, std::string tp, std::string val):name(nm), type(tp), value(val){}
	SymbolTableEntry(std::string nm, std::string tp):name(nm), type(tp), value(""){}
	std::string name;
	std::string type;
	std::string value;
	void printSTE();///print the symbol
};

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
};

#endif