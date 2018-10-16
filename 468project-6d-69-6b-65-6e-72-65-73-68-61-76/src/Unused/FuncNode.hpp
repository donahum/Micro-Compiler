#ifndef FUNCNODE_H
#define FUNCNODE_H

#include "ASTNode.hpp"
#include "SymbolTable.hpp"

class FuncNode : public ASTNode
{
	public:
		FuncNode(std::string name, std::vector<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type);
		std::string name;
		std::vector<ASTNode *> * node_list;
		SymbolTable * table;

		std::string getName();
		std::vector<ASTNode *> * getASTVec();
		SymbolTable * getST();

		void printNode();
};

#endif