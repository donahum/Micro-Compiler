#include "LiteralNode.hpp"

LiteralNode::LiteralNode(LiteralType litType, std::string val, ASTNodeType type) : ASTNode::ASTNode(type){
	litType = litType;
	val = val;
	//Type = type;
}

LiteralType LiteralNode::getLitType(){
	return litType;
}

std::string LiteralNode::getVal(){
	return val;
}

void LiteralNode::printLitType()
{
	if(litType == LiteralType::isINT)
	{
		std::cout << "isINT" << std::endl;
	}else {
		std::cout << "isFLOAT" << std::endl;
	}
}

void LiteralNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
	std::cout << "litType: ";
	printLitType();
}