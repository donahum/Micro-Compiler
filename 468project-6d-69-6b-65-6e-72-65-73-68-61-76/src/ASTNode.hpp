//#include <iostream>
//#include <vector>

#pragma once

#include <string>
#include <iostream>

enum class ASTNodeType
{
	UNDEFINED,
	ADD_EXPR,
	MULT_EXPR,
	VAR_REF,
	LITERAL
};

class ASTNode
{
	public:
		ASTNodeType Type;
		ASTNode * Left;
		ASTNode * Right;

		ASTNode();
		ASTNode(ASTNodeType type);

		void setType(ASTNodeType Type);
		void setLeftChild(ASTNode * Left);
		void setRightChild(ASTNode * Right);
		void printTree(ASTNode * head);
		void printNode();
		void printNodeType();
		virtual std::string TOIR() = 0;
		
	private:
		
};

//#endif