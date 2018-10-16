#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "SymbolTable.hpp"


enum class ASTNodeType
{
	UNDEFINED,
	ADD_EXPR,
	MULT_EXPR,
	VAR_REF,
	LITERAL,
	FUNC,
	ASSIGN
};

enum class LiteralType
{
	isINT,
	isFLOAT
};

class ASTNode
{
public:
	ASTNodeType Type;
	ASTNode * Left;
	ASTNode * Right;
	ASTNode(){}	
	ASTNode(ASTNodeType type): Type(type){}		
	virtual std::string TO_IR() = 0;		
};

class MulExprNode : public ASTNode
{
public:
	std::string mul_op;
	MulExprNode(std::string op, ASTNodeType type);
	std::string TO_IR();
};

class LiteralNode : public ASTNode
{
public:
	LiteralType litType;
	std::string val;
	LiteralNode(LiteralType litType, std::string val, ASTNodeType type);
	std::string TO_IR();
};


class FuncNode : public ASTNode
{
public:
	std::string name;
	std::list<ASTNode *> * node_list;
	SymbolTable * table;
	FuncNode(std::string name, std::list<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type);
	std::string TO_IR();
};

class AssignNode : public ASTNode
{
public:
	AssignNode(ASTNode * var_src, ASTNode * expr_src, ASTNodeType type);
	std::string TO_IR();
};

class AddExprNode : public ASTNode
{
public:
	std::string add_op;
	AddExprNode(std::string inputOp, ASTNodeType type);
	std::string TO_IR();
};

class VarRefNode : public ASTNode
{
public:
	std::string ident;
	VarRefNode(std::string idSrc, ASTNodeType type);
	std::string TO_IR();
};



#endif ///__NODE_H


