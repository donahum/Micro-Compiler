#ifndef VARREF_H
#define VARREF_H

#include "ASTNode.hpp"

class VarRefNode : public ASTNode
{
	public:
		VarRefNode(std::string idSrc, ASTNodeType type);
		std::string ident;
		
		std::string getIdent();
};

#endif