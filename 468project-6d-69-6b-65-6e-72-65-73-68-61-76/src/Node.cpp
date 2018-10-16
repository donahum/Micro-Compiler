
#include "Node.hpp"


MulExprNode::MulExprNode(std::string inputOp, ASTNodeType type) : ASTNode::ASTNode(type){
	mul_op = inputOp;
}


LiteralNode::LiteralNode(LiteralType litType, std::string val, ASTNodeType type) : ASTNode::ASTNode(type){
	litType = litType;
	val = val;
}

FuncNode::FuncNode(std::string name, std::list<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type) 
					: ASTNode::ASTNode(type){
	name = name;
	node_list = node_src;
	table = table_src;
}

AssignNode::AssignNode(ASTNode * var_src, ASTNode * expr_src, ASTNodeType type) : ASTNode::ASTNode(type){
	Left = var_src;
	Right = expr_src;
}


AddExprNode::AddExprNode(std::string inputOp, ASTNodeType type) : ASTNode::ASTNode(type){
	add_op = inputOp;
	//Type = type;
}

VarRefNode::VarRefNode(std::string idSrc, ASTNodeType type) : ASTNode::ASTNode(type){
	ident = idSrc;
	//Type = type;
}

class ThreeAC{
public:
	std::string opcode, op1, op2, op3;
	ThreeAC(){}
	void Fill(std::string o, std::string o1, std::string o2, std::string o3){
		opcode = o;
		op1 =o1;
		op2 =o2;
		op3 =o3;
	}
	void Clear(){ opcode = op1 = op2 = op3 = "";}
};

ThreeAC toInsert;
std::vector<ThreeAC> IR;
std::string MulExprNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
}
std::string LiteralNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
}
std::string FuncNode::TO_IR(){
	// std::string name;
	// std::list<ASTNode *> * node_list;
	// SymbolTable * table;
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	toInsert.Fill("LABEL", "FUNC_"+name, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();
	for(auto stmt : *node_list){
		if(stmt)
			stmt->TO_IR();
	}
}
std::string AssignNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
}
std::string AddExprNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
}
std::string VarRefNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
}	