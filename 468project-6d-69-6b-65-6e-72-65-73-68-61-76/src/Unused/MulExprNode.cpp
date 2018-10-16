#include "MulExprNode.hpp"

MulExprNode::MulExprNode(std::string inputOp, ASTNodeType type) : ASTNode::ASTNode(type){
	mul_op = inputOp;
	//Type = type;
}
std::string MulExprNode::getOp(){
	return mul_op;
}