
#include "Node.hpp"

int availableTemp = 0;
int isINTType = 0;//1 for int, 0 for float
ThreeAC toInsert;
std::vector<ThreeAC> IR;
extern std::stack<SymbolTable*> ststack; 

void ASTNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

void WriteNode::printNode()
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
	}else if(Type == ASTNodeType::WRITE){
		std::cout << "WRITE" << std::endl;
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

void ReadNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

MulExprNode::MulExprNode(std::string inputOp, ASTNodeType type) : ASTNode::ASTNode(type){
	mul_op = inputOp;
}


LiteralNode::LiteralNode(LiteralType litType_src, std::string val_src, ASTNodeType type) : ASTNode::ASTNode(type){
	litType = litType_src;
	val = val_src;
}

FuncNode::FuncNode(std::string name_src, std::list<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type) 
					: ASTNode::ASTNode(type){
	name = name_src;
	node_list = node_src;
	table = table_src;
}

AssignNode::AssignNode(ASTNode * var_src, ASTNode * expr_src, ASTNodeType type) : ASTNode::ASTNode(type){
	Left = var_src;
	Right = expr_src;
}

AddExprNode::AddExprNode(std::string inputOp2, ASTNodeType type) : ASTNode::ASTNode(type){
	add_op = inputOp2;
}

VarRefNode::VarRefNode(std::string idSrc, ASTNodeType type) : ASTNode::ASTNode(type){
	ident = idSrc;
}

WriteNode::WriteNode(std::list<std::string> * str_list_src, ASTNodeType type) : ASTNode::ASTNode(type){
	ident_list = str_list_src;
}

ReadNode::ReadNode(std::list<std::string> * str_list_src2, ASTNodeType type) : ASTNode::ASTNode(type){
	ident_list2 = str_list_src2;
}

std::string FuncNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string funcName = this->name;
	toInsert.Fill("LABEL", "FUNC_"+ funcName, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("LINK", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	for(auto stmt : *node_list){
		if(stmt)
		{
			stmt->TO_IR();
		}
	}

	//std::cout << funcName << std::endl;

	return "";
}

std::string WriteNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	ThreeAC * currWrite = NULL;

	SymbolTable * stackTop = ststack.top();
	int isString = 0;

	for(std::list<std::string>::const_iterator i = this->ident_list->begin(); i != this->ident_list->end(); i++)	
	{
		if(stackTop->getTypeFromID(*i) == "STRING")
		{
			isString = 1;
		}else{
			isString = 0;
		}

		if(stackTop->getTypeFromID(*i) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}

		currWrite = new ThreeAC();
		if(isString)
		{
			currWrite->Fill("WRITES", *i, "", "");
			IR.push_back(*currWrite);
		}
		else if(isINTType){
			currWrite->Fill("WRITEI", *i, "", "");
			IR.push_back(*currWrite);
		}else{
			currWrite->Fill("WRITEF", *i, "", "");
			IR.push_back(*currWrite);
		}
	}

	return "";
}

std::string ReadNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	ThreeAC * currRead = NULL;

	SymbolTable * stackTop = ststack.top();

	for(std::list<std::string>::const_iterator j = this->ident_list2->begin(); j != this->ident_list2->end(); j++)	
	{
		if(stackTop->getTypeFromID(*j) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}

		currRead = new ThreeAC();
		if(isINTType){
			currRead->Fill("READI", "", "", *j);
			IR.push_back(*currRead);
		}else{
			currRead->Fill("READF", "", "", *j);
			IR.push_back(*currRead);
		}
	}

	return "";
}

std::string AssignNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string idKey = this->Left->TO_IR();
	SymbolTable * stackTop = ststack.top();
	
	if(stackTop->getTypeFromID(idKey) == "INT")
	{
		isINTType = 1;
	}else{
		isINTType = 0;
	}

	std::string targetTmpy = this->Right->TO_IR();
	ThreeAC newAssign = ThreeAC();

	if(isINTType){
		newAssign.Fill("STOREI", targetTmpy, "", idKey);
	}else{
		newAssign.Fill("STOREF", targetTmpy, "", idKey);
	}

	IR.push_back(newAssign);
	
	//this->printTree();
	return "";
}

std::string AddExprNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string leftTmpy = this->Left->TO_IR();
	std::string rightTmpy = this->Right->TO_IR();

	ThreeAC newAdd;

	if(this->add_op == "+")
	{
		if(isINTType){
			newAdd.Fill("ADDI", leftTmpy, rightTmpy, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newAdd.Fill("ADDF", leftTmpy, rightTmpy, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}else{
		if(isINTType){
			newAdd.Fill("SUBI", leftTmpy, rightTmpy, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newAdd.Fill("SUBF", leftTmpy, rightTmpy, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}

	IR.push_back(newAdd);

	//this->printTree();
	return newAdd.result;
}

std::string MulExprNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	std::string leftTmpry = this->Left->TO_IR();
	std::string rightTmpry = this->Right->TO_IR();

	ThreeAC newMult = ThreeAC();

	if(this->mul_op == "*")
	{
		if(isINTType){
			newMult.Fill("MULI", leftTmpry, rightTmpry, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newMult.Fill("MULF", leftTmpry, rightTmpry, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}else{
		if(isINTType){
			newMult.Fill("DIVI", leftTmpry, rightTmpry, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newMult.Fill("DIVF", leftTmpry, rightTmpry, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}

	IR.push_back(newMult);

	return newMult.result;
}

std::string LiteralNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	ThreeAC newLit = ThreeAC();
	if(isINTType){
		newLit.Fill("STOREI", this->val, "", "!T"+std::to_string(availableTemp));
		availableTemp++;
	}else{
		newLit.Fill("STOREF", this->val, "", "!T"+std::to_string(availableTemp));
		availableTemp++;
	}
	IR.push_back(newLit);

	return newLit.result;
}

std::string VarRefNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	return this->ident;
}