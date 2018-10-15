	//#ifndef AST_H
	//#define AST_H
	#include "ASTNode.hpp"
	//#endif

	ASTNode::ASTNode(ASTNodeType type)
	{
		Type = type;
		Left = NULL;
		Right = NULL;
	}

	ASTNode::ASTNode()
	{
		Type = ASTNodeType::UNDEFINED;
		Left = NULL;
		Right = NULL;
	}

	void ASTNode::setType(ASTNodeType Type)
	{
		Type = Type;
	}

	void ASTNode::setLeftChild(ASTNode * Left)
	{
		Left = Left;
	}

	void ASTNode::setRightChild(ASTNode * Right)
	{
		Right = Right;
	}

	void ASTNode::printNode()
	{

		std::cout << "Type: ";
		printNodeType();
	}

	void ASTNode::printNodeType()
	{
		if(Type == ASTNodeType::UNDEFINED)
		{
			std::cout << "UNDEFINED" << std::endl;
		}else if(Type == ASTNodeType::ADD_EXPR){
			std::cout << "ADD_EXPR" << std::endl;
		}else if(Type == ASTNodeType::MULT_EXPR){
			std::cout << "MULT_EXPR" << std::endl;
		}else if(Type == ASTNodeType::VAR_REF){
			std::cout << "VAR_REF" << std::endl;
		}else {
			std::cout << "LITERAL" << std::endl;
		}
	}

	void ASTNode::printTree(ASTNode * Current)
	{
		if(Current == NULL)
		{
			return;
		}
		else
		{
			Current->printNode();
			if(Current->Left != NULL)
			{
				ASTNode::printTree(Current->Left);
			}
			if(Current->Right != NULL)
			{
				ASTNode::printTree(Current->Right);
			}
		}
	}

//https://mariusbancila.ro/blog/2009/02/05/evaluating-expressions-part-3-building-the-ast/

//http://web.eecs.utk.edu/~bvz/teaching/cs461Sp11/notes/parse_tree/