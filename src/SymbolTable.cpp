#include "SymbolTable.hpp"

void SymbolTable::addEntry(SymbolTableEntry * newEntry)
{
	if(table.find(newEntry->name) != table.end()){
		std::cout<<"DECLARATION ERROR\n"<<newEntry->name<<"\n";
		exit(0);
	}
	table.insert(std::pair<std::string, SymbolTableEntry *>(newEntry->name, newEntry));
	ordered_table.push_back(newEntry);
}

void SymbolTableEntry::printSTE(){
	if(!type.compare("STRING")){
		std::cout << "name " << name << " type " << type << " value " << value;
	}else if((!type.compare("INT")) || (!type.compare("FLOAT")) || (!type.compare("VOID")))	{
		std::cout << "name " << name << " type " << type;
	}
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

std::string SymbolTable::getTypeFromID(std::string idName)
{
	if(table.find(idName) == table.end()){
		SymbolTable * parentTable = this->parent;
		while(parentTable != NULL)
		{
			if(parentTable->table.find(idName) == table.end()){
				parentTable = parentTable->parent;
			}else{
				return parentTable->table.at(idName)->type;
			}
		}
	}else{
		return table.at(idName)->type;
	}

	return NULL;
} 
