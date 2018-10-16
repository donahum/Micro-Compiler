#include "VarRefNode.hpp"

VarRefNode::VarRefNode(std::string idSrc, ASTNodeType type) : ASTNode::ASTNode(type){
	ident = idSrc;
	//Type = type;
}
std::string VarRefNode::getIdent(){
	return ident;
}