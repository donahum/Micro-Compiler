#include "SymbolTable.hpp"
//#include "SymbolTableEntry.hpp"

void SymbolTable::addEntry(SymbolTableEntry * newEntry)
{
	if(table.find(newEntry->name) != table.end()){
		std::cout<<"DECLARATION ERROR\n"<<newEntry->name<<"\n";
		exit(0);
	}
	//table.insert(newEntry->name, newEntry);
	table.insert(std::pair<std::string, SymbolTableEntry *>(newEntry->name, newEntry));
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