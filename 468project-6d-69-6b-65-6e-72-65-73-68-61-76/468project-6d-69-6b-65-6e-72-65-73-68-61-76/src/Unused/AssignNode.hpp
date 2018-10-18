#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include "ASTNode.hpp"
#include "VarRefNode.hpp"

#include <vector>

class AssignNode : public ASTNode
{
	public:
		AssignNode(VarRefNode * var_src, ASTNode * expr_src, ASTNodeType type);
		VarRefNode * var_node;
		ASTNode * expr_node;

		void printNode();
};

#endif