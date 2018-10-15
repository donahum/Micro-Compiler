#ifndef STE_H
#define STE_H

#include <iostream>
#include <vector>

class SymbolTableEntry
{
	public:
		SymbolTableEntry();

		SymbolTableEntry(SymbolTableEntry * newEntry);

		SymbolTableEntry(std::string nm, std::string tp, std::string val);
		SymbolTableEntry(std::string nm, std::string tp);

		SymbolTableEntry(std::string * nm, std::string * tp, std::string * val);
		SymbolTableEntry(std::string * nm, std::string * tp);

		void printSTE();

		std::string getName();
		std::string getType();
		std::string getValue();

		void setName(std::string x);
		void setType(std::string x);
		void setValue(std::string x);

		std::string name;
		std::string type;
		std::string value;

	private:
		
		//friend class SymbolTable;
};

#endif