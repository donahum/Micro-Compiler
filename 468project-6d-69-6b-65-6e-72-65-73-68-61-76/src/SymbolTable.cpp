#include "SymbolTable.hpp"

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

void SymbolTableEntry::printSTE(){
	if(!type.compare("STRING")){
		std::cout << "name " << name << " type " << type << " value " << value;
		//std::cout << "name type value";
	}else if((!type.compare("INT")) || (!type.compare("FLOAT")) || (!type.compare("VOID")))	{
		std::cout << "name " << name << " type " << type;
		//std::cout << "name type";
	}
	return;
}

void SymbolTable::printST(){
	std::cout<<"SYMBOL TABLE "<<scope<<"\n";
	for(auto sym : ordered_table){
		sym->printSTE();
		std::cout<<"\n";
	}
	std::cout<<"\n";
	for(auto child : children){
		child->printST();
		std::cout<<"\n";
	}
}
