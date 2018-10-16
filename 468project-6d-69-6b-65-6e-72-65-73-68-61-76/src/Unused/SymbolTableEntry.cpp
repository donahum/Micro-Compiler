#include "SymbolTableEntry.hpp"

SymbolTableEntry::SymbolTableEntry()
{
	name = "";
	type = "";
	value = "";
}

SymbolTableEntry::SymbolTableEntry(SymbolTableEntry * newEntry)
{
	name = (*newEntry).getName();
	type = (*newEntry).getType();
	value = (*newEntry).getValue();
}

SymbolTableEntry::SymbolTableEntry(std::string nm, std::string tp, std::string val)	//for string declarations (includes value -- STRLITERAL)
{
	name = nm;
	type = tp;
	value = val;
}

SymbolTableEntry::SymbolTableEntry(std::string nm, std::string tp)				//for other var types (float, int, void?)
{
	name = nm;
	type = tp;
	value = "";
}

SymbolTableEntry::SymbolTableEntry(std::string * nm, std::string * tp, std::string * val)	//for string declarations (includes value -- STRLITERAL)
{
	name = *nm;
	type = *tp;
	value = *val;
}

SymbolTableEntry::SymbolTableEntry(std::string * nm, std::string * tp)				//for other var types (float, int, void?)
{
	name = *nm;
	type = *tp;
	value = "";
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

std::string SymbolTableEntry::getName(){
	return name;
}

std::string SymbolTableEntry::getType(){
	return type;
}

std::string SymbolTableEntry::getValue(){
	return value;
}

void SymbolTableEntry::setName(std::string nm){
	name = nm;
}

void SymbolTableEntry::setType(std::string tp){
	type = tp;
}

void SymbolTableEntry::setValue(std::string val){
	value = val;
}