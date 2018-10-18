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
	ASSIGN,
	WRITE,
	READ
};

enum class LiteralType
{
	isINT,
	isFLOAT
};

class ThreeAC{
public:
	std::string opcode, op1, op2, result;
	ThreeAC(){}
	void Fill(std::string o, std::string o1, std::string o2, std::string o3){
		opcode = o;
		op1 =o1;
		op2 =o2;
		result =o3;
	}
	void Clear(){ opcode = op1 = op2 = result = "";}
};

class ASTNode
{
public:
	ASTNodeType Type;
	ASTNode * Left;
	ASTNode * Right;
	ASTNode(){}	
	ASTNode(ASTNodeType type): Type(type){}		

	//virtual ~ASTNode() = default;
	void printTree();
	void printNodeType();
	virtual void printNode();
	virtual std::string TO_IR() = 0;		
};



class MulExprNode : public ASTNode
{
public:
	std::string mul_op;
	MulExprNode(std::string op, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

class LiteralNode : public ASTNode
{
public:
	LiteralType litType;
	std::string val;
	LiteralNode(LiteralType litType, std::string val, ASTNodeType type);
	void printNode();
	void printLitType();
	std::string TO_IR();
};


class FuncNode : public ASTNode
{
public:
	std::string name;
	std::list<ASTNode *> * node_list;
	SymbolTable * table;
	FuncNode(std::string name_src, std::list<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

class AssignNode : public ASTNode
{
public:
	int typeINT;
	AssignNode(ASTNode * var_src, ASTNode * expr_src, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

class AddExprNode : public ASTNode
{
public:
	std::string add_op;
	AddExprNode(std::string inputOp, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

class VarRefNode : public ASTNode
{
public:
	std::string ident;
	VarRefNode(std::string idSrc, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

class WriteNode : public ASTNode
{
public:
	std::list<std::string> * ident_list;
	WriteNode(std::list<std::string> * str_list_src, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

class ReadNode : public ASTNode
{
public:
	std::list<std::string> * ident_list2;
	ReadNode(std::list<std::string> * str_list_src2, ASTNodeType type);
	void printNode();
	std::string TO_IR();
};

#endif ///__NODE_H