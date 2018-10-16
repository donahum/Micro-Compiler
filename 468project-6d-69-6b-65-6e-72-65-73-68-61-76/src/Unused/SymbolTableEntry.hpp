#ifndef STE_H
#define STE_H

#include <iostream>
#include <vector>

class SymbolTableEntry
{
public:
	SymbolTableEntry(std::string nm, std::string tp, std::string val);
	SymbolTableEntry(std::string nm, std::string tp);

	std::string name;
	std::string type;
	std::string value;
};

#endif