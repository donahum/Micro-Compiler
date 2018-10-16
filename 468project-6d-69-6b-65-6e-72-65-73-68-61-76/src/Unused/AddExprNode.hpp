#ifndef ADDNODE_H
#define ADDNODE_H

#include "ASTNode.hpp"

class AddExprNode : public ASTNode
{
	public:
		std::string add_op;

		//AddExprNode() : ASTNode(){};
		AddExprNode(std::string inputOp, ASTNodeType type);
		
		std::string getOp();
		void printNode();
};

#endif