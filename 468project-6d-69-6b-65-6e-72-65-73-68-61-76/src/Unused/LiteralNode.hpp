#ifndef LITERALNODE_H
#define LITERALNODE_H

#include "ASTNode.hpp"

enum class LiteralType
{
	isINT,
	isFLOAT
};

class LiteralNode : public ASTNode
{
	public:
		LiteralNode(LiteralType litType, std::string val, ASTNodeType type);
		LiteralType litType;
		std::string val;

		
		LiteralType getLitType();
		std::string getVal();
		void printNode();
		void printLitType();
};

#endif