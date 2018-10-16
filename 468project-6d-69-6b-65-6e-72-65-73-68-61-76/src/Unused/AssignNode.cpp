#include "AssignNode.hpp"

AssignNode::AssignNode(VarRefNode * var_src, ASTNode * expr_src, ASTNodeType type) : ASTNode::ASTNode(type){
	var_node = var_src;
	expr_node = expr_src;
}

void AssignNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}