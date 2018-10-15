#ifndef MULNODE_H
#define MULNODE_H

#include "ASTNode.hpp"

class MulExprNode : public ASTNode
{
	public:
		MulExprNode(std::string op, ASTNodeType type);
		std::string mul_op;
		
		std::string getOp();
};

#endif