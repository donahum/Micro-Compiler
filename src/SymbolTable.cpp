#include "SymbolTable.hpp"

SymbolTableEntry::SymbolTableEntry(std::string nm, std::string tp, std::string val){
	name = nm;
	type = tp;
	value = val;
}

SymbolTableEntry::SymbolTableEntry(std::string nm, std::string tp, std::string val, int slt){
	name = nm;
	type = tp;
	value = val;
	slot = slt;
}

SymbolTableEntry::SymbolTableEntry(std::string nm, std::string tp){
	name = nm;
	type = tp;
	value = "";
	slot = 0;
}

SymbolTableEntry::SymbolTableEntry(std::string nm, std::string tp, int slt){
	name = nm;
	type = tp;
	value = "";
	slot = slt;
}

void SymbolTableEntry::printSTE(){
	if(!type.compare("STRING")){
		std::cout << "name " << name << " type " << type << " value " << value << " slot " << slot;
	}else if((!type.compare("INT")) || (!type.compare("FLOAT")) || (!type.compare("VOID")))	{
		std::cout << "name " << name << " type " << type << " slot " << slot;
	}
}

SymbolTable::SymbolTable(std::string s, SymbolTable* p){
	scope = s;
	parent = p;
	numParams = 0;
	numLocals = 0;
}

void SymbolTable::addEntry(SymbolTableEntry * newEntry)
{
	if(table.find(newEntry->name) != table.end()){
		std::cout<<"DECLARATION ERROR\n"<<newEntry->name<<"\n";
		exit(0);
	}
	table.insert(std::pair<std::string, SymbolTableEntry *>(newEntry->name, newEntry));
	ordered_table.push_back(newEntry);
}

void SymbolTable::printST(){
	std::cout<< "SYMBOL TABLE " << scope << "\n";
	std::cout<< "NumParams: " << this->numParams << std::endl;
	std::cout<< "NumLocals: " << this->numLocals << std::endl;
	for(auto sym : ordered_table){
		sym->printSTE();
		std::cout<<"\n";
	}
	std::cout<<"\n";
	/*for(auto child : children){
		child->printST();
		std::cout<<"\n";
	}*/
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

int SymbolTable::getSlotFromID(std::string idName)
{
	if(table.find(idName) == table.end()){
		/*SymbolTable * parentTable = this->parent;
		while(parentTable != NULL)
		{
			if(parentTable->table.find(idName) == table.end()){
				parentTable = parentTable->parent;
			}else{
				return parentTable->table.at(idName)->slot;
			}
		}*/
		return NULL;
	}else{
		return table.at(idName)->slot;
	}

	//return NULL;
} 

/*FuncSTE::FuncSTE(std::string nm, std::string tp, std::string val, int slt) : SymbolTableEntry::SymbolTableEntry(nm, tp, val){
	name = nm;
	type = tp;
	value = val;
	slot = slt;
}

FuncSTE::FuncSTE(std::string nm, std::string tp, int slt) : SymbolTableEntry::SymbolTableEntry(nm, tp){
	name = nm;
	type = tp;
	value = "";
	slot = slt;
}

void FuncSTE::printSTE(){
	if(!type.compare("STRING")){
		std::cout << "name " << name << " type " << type << " value " << value << " slot " << slot;
	}else if((!type.compare("INT")) || (!type.compare("FLOAT")) || (!type.compare("VOID")))	{
		std::cout << "name " << name << " type " << type << " slot " << slot;
	}
}

FuncST::FuncST(std::vector<FuncSTE *> func_params, std::string s, SymbolTable* p) : SymbolTable::SymbolTable(s, p){
	params = func_params;
	scope = s;
	parent = p;
}

void FuncST::printST(){
	std::cout<<"SYMBOL TABLE "<<scope<<"\n";
	
	for(auto func_params : params){
		func_params->printSTE();
		std::cout<<"\n";
	}
	std::cout << std::endl;
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

void FuncST::addEntry(FuncSTE * newEntry)
{
	if(table.find(newEntry->name) != table.end()){
		std::cout<<"DECLARATION ERROR\n"<<newEntry->name<<"\n";
		exit(0);
	}
	table.insert(std::pair<std::string, FuncSTE *>(newEntry->name, newEntry));
	ordered_table.push_back(newEntry);
}*/

/*std::string FuncST::getTypeFromID(std::string idName)
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
}*/