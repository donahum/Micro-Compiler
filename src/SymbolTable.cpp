#ifndef ST_H
#define ST_H
#include "SymbolTable.hpp"
#endif

#ifndef STE_H
#define STE_H
#include "SymbolTableEntry.hpp"
#endif

SymbolTable::SymbolTable(std::string sc)
{
	scope = sc;
	vec = std::vector<SymbolTableEntry>();
}

SymbolTable::SymbolTable(std::string * sc)
{
	scope = *sc;
	vec = std::vector<SymbolTableEntry>();
}

SymbolTable::SymbolTable()
{
	scope = "";
	vec = std::vector<SymbolTableEntry>();
}

void SymbolTable::setScope(std::string sc)
{
	scope = sc;
}

void SymbolTable::addEntry(SymbolTableEntry * newEntry)
{
	//std::cout << "Adding new entry to symbol table " << scope << "\n";
	vec.push_back(*newEntry);
}

void SymbolTable::addEntryToFront(SymbolTableEntry * newEntry)
{
	//std::cout << "Adding new entry to symbol table " << scope << "\n";
	vec.insert(vec.begin(), *newEntry);
}

void SymbolTable::copyEntriesFromST(SymbolTable * srcTable)
{
	for(std::vector<int>::size_type i = 0; i != (srcTable->vec).size(); ++i)
	{
		vec.push_back((srcTable->vec).at(i));
	}
}

void SymbolTable::copyEntriesFromSTToFront(SymbolTable * srcTable)
{
	for(std::vector<int>::size_type i = 0; i != (srcTable->vec).size(); ++i)
	{
		vec.insert(vec.begin(), (srcTable->vec).at(i));
	}
}

void SymbolTable::printST()
{
	std::cout << "Symbol table " << scope << "\n";

	for(std::vector<int>::size_type i = 0; i != vec.size(); ++i)
	{
		if(i != 0){
			std::cout << std::endl;
		}
		vec[i].printSTE();
	}
}

std::string SymbolTable::getScope()
{
	return scope;
}

/*int main()
{
	SymbolTableEntry entry1 = SymbolTableEntry("id1", "STRING", "This is a string.");
	SymbolTableEntry entry2 = SymbolTableEntry("id2", "INT");
	SymbolTableEntry entry3 = SymbolTableEntry("id3", "FLOAT");
	SymbolTable table = SymbolTable("GLOBAL");
	table.addEntry(entry1);
	table.addEntry(entry2);
	table.addEntry(entry3);
	table.printST();
	return 0;
}*/