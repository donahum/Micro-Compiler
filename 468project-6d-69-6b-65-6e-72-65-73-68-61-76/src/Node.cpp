
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
}

VarRefNode::VarRefNode(std::string idSrc, ASTNodeType type) : ASTNode::ASTNode(type){
	ident = idSrc;
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
	}else if(Type == ASTNodeType::FUNC){
		std::cout << "FUNC" << std::endl;
	}else if(Type == ASTNodeType::ASSIGN){
		std::cout << "ASSIGN" << std::endl;
	}else{
		std::cout << "LITERAL" << std::endl;
	}
}

void ASTNode::printTree()
{
	if(this == NULL)
	{
		return;
	}
	else
	{
		this->printNode();
		if(this->Left != NULL)
		{
			this->Left->printTree();
		}
		if(this->Right != NULL)
		{
			this->Right->printTree();
		}
	}
}

void AddExprNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
	std::cout << "Op: " << add_op << std::endl;
}

void MulExprNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
	std::cout << "Op: " << mul_op << std::endl;
}

void VarRefNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

void LiteralNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
	std::cout << "litType: ";
	printLitType();
}

void FuncNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

void AssignNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
	//std::cout << "Var Ref for Assign: ";
	//var_node->printNode();
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
	//this->printTree();
}
std::string LiteralNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//this->printTree();
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
		std::cout << "Node Start" << std::endl;
		if(stmt){
			std::cout << "pre-IR" << std::endl;
			stmt->TO_IR();
			std::cout << "post-IR" << std::endl;
		}else{
			std::cout << "Chris, what do you mean lol" << std::endl;
		}
	}
}

std::string AssignNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//this->printTree();
}
std::string AddExprNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//this->printTree();
}
std::string VarRefNode::TO_IR(){
	printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//this->printTree();
}