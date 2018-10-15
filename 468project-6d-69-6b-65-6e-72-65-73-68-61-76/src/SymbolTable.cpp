#ifndef ST_H
#define ST_H
#include "SymbolTable.hpp"
#endif

#ifndef STE_H
#define STE_H
#include "SymbolTableEntry.hpp"
#endif


void SymbolTable::addEntry(SymbolTableEntry * newEntry)
{
	if(table.find(newEntry->name) != table.end()){
		std::cout<<"DECLARATION ERROR\n"<<newEntry->name<<"\n";
		exit(0);
	}
	table.insert(newEntry->name, newEntry);
	ordered_table.push_back(newEntry);
}

void SymbolTable::printST()
{
	// std::cout << "Symbol table " << scope << "\n";

	// for(std::vector<int>::size_type i = 0; i != vec.size(); ++i)
	// {
	// 	if(i != 0){
	// 		std::cout << std::endl;
	// 	}
	// 	vec[i].printSTE();
	// }
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