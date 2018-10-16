#include "FuncNode.hpp"

FuncNode::FuncNode(std::string name, std::vector<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type) : ASTNode::ASTNode(type){
	name = name;
	node_list = node_src;
	table = table_src;
}

std::string FuncNode::getName(){
	return name;
}

std::vector<ASTNode *> * FuncNode::getASTVec()
{
	return node_list;
}

SymbolTable * FuncNode::getST()
{
	return table;
}

void FuncNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}