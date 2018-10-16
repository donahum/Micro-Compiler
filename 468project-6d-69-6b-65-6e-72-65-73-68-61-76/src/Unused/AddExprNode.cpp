	//#ifndef AST_H
	//#define AST_H
	//#endif

	#include "AddExprNode.hpp"

	#include <string>

	AddExprNode::AddExprNode(std::string inputOp, ASTNodeType type) : ASTNode::ASTNode(type){
		add_op = inputOp;
		//Type = type;
	}

	std::string AddExprNode::AddExprNode::getOp(){
		return add_op;
	}

	void AddExprNode::printNode()
	{
		std::cout << "Type: ";
		printNodeType();
		std::cout << "Op: " << add_op << std::endl;
	}