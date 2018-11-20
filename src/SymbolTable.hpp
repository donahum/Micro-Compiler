#ifndef ST_H
#define ST_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>

/*class SymbolTableEntry
{
public:
	SymbolTableEntry(std::string nm, std::string tp, std::string val);
	SymbolTableEntry(std::string nm, std::string tp);
	std::string name;
	std::string type;
	std::string value;
	void printSTE();///print the symbol
};

class FuncSTE : public SymbolTableEntry
{
public:
	FuncSTE(std::string nm, std::string tp, std::string val, int slt);
	FuncSTE(std::string nm, std::string tp, int slt);
	std::string name;
	std::string type;
	std::string value;
	int slot;
	void printSTE();
};*/

/*class SymbolTable
{
public:
	std::map<std::string, SymbolTableEntry*> table;
	std::vector<SymbolTableEntry*> ordered_table;
	SymbolTable* parent;
	std::vector<SymbolTable*> children;
	std::string scope; 

	SymbolTable(std::string s, SymbolTable* p);
	void addEntry(SymbolTableEntry * newEntry);
	std::string getTypeFromID(std::string idName);
	void printST();
};*/

/*class FuncST : public SymbolTable
{
public:
	std::vector<FuncSTE> params;
	std::vector<FuncSTE> locals;
	std::map<std::string, FuncSTE*> table;
	std::vector<FuncSTE*> ordered_table;
	SymbolTable * parent;
	std::vector<SymbolTable*> children;
	std::string scope; 

	FuncST(std::vector<FuncSTE*> func_params, std::string s, SymbolTable* p);
	void addEntry(FuncSTE * newEntry);
	std::string getTypeFromID(std::string idName);
	void printST();
};
*/

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
	std::map<std::string, SymbolTableEntry*> table;
	std::vector<SymbolTableEntry*> ordered_table;
	SymbolTable* parent;
	std::vector<SymbolTable*> children;
	std::string scope; 

	int numParams;
	int numLocals;

	SymbolTable(std::string s, SymbolTable* p);
	void addEntry(SymbolTableEntry * newEntry);
	std::string getTypeFromID(std::string idName);
	int getSlotFromID(std::string idName);
	void printST();
};

#endif 
