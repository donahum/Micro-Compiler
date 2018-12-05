#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
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
	READ,
	WHILE,
	IF,
	ELSE, 
	CALL_EXPR, 
	RET
};

enum class LiteralType
{
	isINT,
	isFLOAT
};

enum class JumpType
{
	G_T,
	G_E,
	L_T,
	L_E,
	N_E,
	E_Q
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
	virtual std::string TO_IR(SymbolTable * st_src) = 0;		
};

class Conditional{
public:
	ASTNode * left_expr;
	ASTNode * right_expr;
	JumpType jtype;
	Conditional(){}
	void Fill(ASTNode * left_expr_src, ASTNode * right_expr_src, JumpType jtype_src){
		left_expr = left_expr_src;
		right_expr = right_expr_src;
		jtype = jtype_src;
	}
};

class MulExprNode : public ASTNode
{
public:
	std::string mul_op;
	MulExprNode(std::string op, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class LiteralNode : public ASTNode
{
public:
	LiteralType litType;
	std::string val;
	LiteralNode(LiteralType litType, std::string val, ASTNodeType type);
	void printNode();
	void printLitType();
	std::string TO_IR(SymbolTable * st_src);
};


class FuncNode : public ASTNode
{
public:
	std::string name;
	std::vector<ASTNode *> * node_list;
	SymbolTable * table;
	FuncNode(std::string name_src, std::vector<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class CallNode : public ASTNode
{
public:
	std::vector<ASTNode *> * node_list;
	std::string name;
	CallNode(std::vector<ASTNode *> * node_list_src, std::string name_src, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class AssignNode : public ASTNode
{
public:
	int typeINT;
	AssignNode(ASTNode * var_src, ASTNode * expr_src, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class AddExprNode : public ASTNode
{
public:
	std::string add_op;
	AddExprNode(std::string inputOp, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class VarRefNode : public ASTNode
{
public:
	std::string ident;
	VarRefNode(std::string idSrc, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class WriteNode : public ASTNode
{
public:
	std::list<std::string> * ident_list;
	WriteNode(std::list<std::string> * str_list_src, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class ReadNode : public ASTNode
{
public:
	std::list<std::string> * ident_list2;
	ReadNode(std::list<std::string> * str_list_src2, ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

class WhileNode : public ASTNode
{
public:
	JumpType jtype;
	ASTNode * cond_node_left;
	ASTNode * cond_node_right;
	std::vector<ASTNode *> stmt_nodes;
	int blockID;
	WhileNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::vector<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype, ASTNodeType type);
	WhileNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype, ASTNodeType type);
	void printNode();
	void copyStmtList(std::vector<ASTNode *> stmt_nodes_supplied);
	std::string TO_IR(SymbolTable * st_src);
};

class ElseNode : public ASTNode
{
public:
	std::vector<ASTNode *> stmt_nodes;
	int blockID;
	ElseNode(std::vector<ASTNode *> stmt_nodes_src, int blockID_src, ASTNodeType type);
	ElseNode(int blockID, ASTNodeType type);
	ElseNode(ASTNodeType type);
	void printNode();
	void copyStmtList(std::vector<ASTNode *> stmt_nodes_supplied);
	void setBlockID(int blockID_supplied);
	std::string TO_IR(SymbolTable * st_src);
};

class IfNode : public ASTNode
{
public:
	JumpType jtype;
	ASTNode * cond_node_left;
	ASTNode * cond_node_right;
	ElseNode * else_node;
	std::vector<ASTNode *> stmt_nodes;
	int blockID;
	IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::vector<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype, ElseNode * else_node, ASTNodeType type);
	IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype, ElseNode * else_node, ASTNodeType type);
	IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::vector<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype, ASTNodeType type);
	IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype, ASTNodeType type);
	void printNode();
	void copyStmtList(std::vector<ASTNode *> stmt_nodes_supplied);
	void copyElseNode(ElseNode * else_node_supplied);
	std::string TO_IR(SymbolTable * st_src);
};

class ReturnNode : public ASTNode
{
public:
	//ASTNode * ret_expr;
	ReturnNode(ASTNodeType type);
	void printNode();
	std::string TO_IR(SymbolTable * st_src);
};

#endif ///__NODE_H