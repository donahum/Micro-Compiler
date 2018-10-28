
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

void WhileNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

void IfNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

void ElseNode::printNode()
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

FuncNode::FuncNode(std::string name_src, std::list<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type) : ASTNode::ASTNode(type){
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

WhileNode::WhileNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::list<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
	jtype = jtype_src;
}

WhileNode::WhileNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = std::list<ASTNode *>(0);
	blockID = blockID_src;
	jtype = jtype_src;
}

//else defined
IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::list<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype_src, ElseNode * else_node_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = else_node_src;
}

//else not defined
IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::list<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = new ElseNode(ASTNodeType::ELSE);
}

//stmt_nodes = null
IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype_src, ElseNode * else_node_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = std::list<ASTNode *>(0);
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = else_node_src;
}

IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = std::list<ASTNode *>(0);
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = new ElseNode(ASTNodeType::ELSE);
}

ElseNode::ElseNode(std::list<ASTNode *> stmt_nodes_src, int blockID_src, ASTNodeType type) : ASTNode::ASTNode(type){
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
}

ElseNode::ElseNode(int blockID_src, ASTNodeType type) : ASTNode::ASTNode(type){
	stmt_nodes = std::list<ASTNode *>(0);
	blockID = blockID_src;
}

ElseNode::ElseNode(ASTNodeType type) : ASTNode::ASTNode(type){
	stmt_nodes = std::list<ASTNode *>(0);
	blockID = -1;
}

void ElseNode::setBlockID(int blockID_supplied)
{
	blockID = blockID_supplied;
}

void WhileNode::copyStmtList(std::list<ASTNode *> stmt_nodes_supplied)
{
	stmt_nodes = stmt_nodes_supplied;
}

void IfNode::copyStmtList(std::list<ASTNode *> stmt_nodes_supplied)
{
	stmt_nodes = stmt_nodes_supplied;
}

void IfNode::copyElseNode(ElseNode * else_node_supplied)
{
	else_node = else_node_supplied;
}

void ElseNode::copyStmtList(std::list<ASTNode *> stmt_nodes_supplied)
{
	stmt_nodes = stmt_nodes_supplied;
}

std::string IfNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//std::cout << "IfNode->TO_IR()" << std::endl;
	std::string else_start = "ELSE_" + std::to_string(this->blockID);
	std::string else_end = "END_IF_ELSE_" + std::to_string(this->blockID);

	std::string leftCondTmpy = this->cond_node_left->TO_IR();
	std::string rightCondTmpy = this->cond_node_right->TO_IR();

	std::string rightRef = "";

	ThreeAC * branch_stmt = new ThreeAC();
	SymbolTable * stackTop = ststack.top();

	if( (this->cond_node_left->Type == ASTNodeType::VAR_REF) && (this->cond_node_right->Type == ASTNodeType::VAR_REF) )
	{
		ThreeAC putVarInReg = ThreeAC();
		if(isINTType){
			putVarInReg.Fill("STOREI", rightCondTmpy, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			putVarInReg.Fill("STOREF", rightCondTmpy, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}

		rightRef = putVarInReg.result;
		IR.push_back(putVarInReg);

		putVarInReg.Clear();
	}else{
		rightRef = rightCondTmpy;
	}

	if(stackTop->getTypeFromID(leftCondTmpy) == "INT")
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				branch_stmt->Fill("LEI", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTI", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEI", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTI", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQI", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEI", leftCondTmpy, rightRef, else_start);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
	}
	else if(stackTop->getTypeFromID(leftCondTmpy) == "FLOAT")
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				branch_stmt->Fill("LEF", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTF", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEF", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTF", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQF", leftCondTmpy, rightRef, else_start);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEF", leftCondTmpy, rightRef, else_start);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
	}

	//if(else_node){
		IR.push_back(*branch_stmt);
		branch_stmt->Clear();
	//}

	//std::cout << stmt_nodes.size() << std::endl;

	for(auto stmt : stmt_nodes){
		if(stmt)
		{	
			//std::cout << "if stmts->TO_IR()" << std::endl;
			stmt->TO_IR();
		}
	}

	

	//std::cout << "checking if there's an else node\n";
	//std::cout << else_node << std::endl;	
	//if(else_node)
	//{
		//std::cout << "there was an else node!\n";

		toInsert.Fill("JUMP", else_end, "", "");
		IR.push_back(toInsert);
		toInsert.Clear();

		toInsert.Fill("LABEL", else_start, "", "");
		IR.push_back(toInsert);
		toInsert.Clear();
		if(else_node){
			else_node->TO_IR();
		}
	//}
	//std::cout << "got past else node!\n";

	//if(else_node){
		toInsert.Fill("LABEL", else_end, "", "");
		IR.push_back(toInsert);
		toInsert.Clear();
	//}

	//std::cout << "end of IfNode->TO_IR()\n";

	return "";
}

std::string ElseNode::TO_IR(){
	//std::cout << "ElseNode->TO_IR()" << std::endl;
	//std::cout << stmt_nodes.size() << std::endl;
	
	for(auto stmt : this->stmt_nodes){
		if(stmt)
		{
			//std::cout << "else stmt->TO_IR()" << std::endl;
			stmt->TO_IR();
		}
	}

	return "";
}

std::string WhileNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//std::cout << "in WhileNode->TO_IR()" << std::endl;
	std::string while_start = "WHILE_START_" + std::to_string(this->blockID);
	std::string while_end = "WHILE_END_" + std::to_string(this->blockID);

	toInsert.Fill("LABEL", while_start, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	//std::cout << std::to_string(this->blockID) << std::endl;
	

	std::string leftCondTmpy = this->cond_node_left->TO_IR();
	std::string rightCondTmpy = this->cond_node_right->TO_IR();
	std::string rightRef = "";

	ThreeAC * branch_stmt = new ThreeAC();
	SymbolTable * stackTop = ststack.top();

	if( (this->cond_node_left->Type == ASTNodeType::VAR_REF) && (this->cond_node_right->Type == ASTNodeType::VAR_REF) )
	{
		ThreeAC putVarInReg = ThreeAC();
		if(isINTType){
			putVarInReg.Fill("STOREI", rightCondTmpy, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			putVarInReg.Fill("STOREF", rightCondTmpy, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}

		rightRef = putVarInReg.result;
		IR.push_back(putVarInReg);

		putVarInReg.Clear();
	}else{
		rightRef = rightCondTmpy;
	}

	if(stackTop->getTypeFromID(leftCondTmpy) == "INT")
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				
				branch_stmt->Fill("LEI", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTI", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEI", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTI", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQI", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEI", leftCondTmpy, rightRef, while_end);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
	}
	else
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				branch_stmt->Fill("LEF", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTF", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEF", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTF", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQF", leftCondTmpy, rightRef, while_end);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEF", leftCondTmpy, rightRef, while_end);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
	}

	IR.push_back(*branch_stmt);

	for(auto stmt : stmt_nodes){
		if(stmt)
		{
			//std::cout << "while stmt->TO_IR()" << std::endl;
			stmt->TO_IR();
		}
	}

	toInsert.Fill("JUMP", while_start, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("LABEL", while_end, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	return "";
}

std::string FuncNode::TO_IR(){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string funcName = this->name;

    toInsert.Fill("PUSH", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("PUSHREGS", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("JSR", "FUNC_"+ funcName, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("HALT", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("LABEL", "FUNC_"+ funcName, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("LINK", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	for(auto stmt : *node_list){
		if(stmt)
		{
			//std::cout << "Func stmt->TO_IR()" << std::endl;
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
	ThreeAC newAssign = ThreeAC();

	std::string targetTmpy = this->Right->TO_IR();
	
	if(stackTop->getTypeFromID(idKey) == "INT")
	{
		isINTType = 1;
	}else{
		isINTType = 0;
	}

	if( (this->Right->Type == ASTNodeType::VAR_REF) && (this->Left->Type == ASTNodeType::VAR_REF) )
	{
		ThreeAC putVarInReg = ThreeAC();
		if(isINTType){
			putVarInReg.Fill("STOREI", targetTmpy, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			putVarInReg.Fill("STOREF", targetTmpy, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}

		IR.push_back(putVarInReg);

		if(isINTType){
			newAssign.Fill("STOREI", putVarInReg.result, "", idKey);
		}else{
			newAssign.Fill("STOREF", putVarInReg.result, "", idKey);
		}

		putVarInReg.Clear();
	}
	else{
		
		
		if(isINTType){
			newAssign.Fill("STOREI", targetTmpy, "", idKey);
		}else{
			newAssign.Fill("STOREF", targetTmpy, "", idKey);
		}

		
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

	SymbolTable * stackTop = ststack.top();

	if(this->Left->Type == ASTNodeType::VAR_REF)
	{
		if(stackTop->getTypeFromID( this->Left->TO_IR()) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if(this->Right->Type == ASTNodeType::VAR_REF)
	{
		if(stackTop->getTypeFromID( this->Right->TO_IR()) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if (this->Left->Type == ASTNodeType::LITERAL)
	{
		if(static_cast<LiteralNode *> (this->Left)->litType == LiteralType::isINT)
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if (this->Right->Type == ASTNodeType::LITERAL)
	{
		if(static_cast<LiteralNode *> (this->Right)->litType == LiteralType::isINT)
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}

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

	SymbolTable * stackTop = ststack.top();

	if(this->Left->Type == ASTNodeType::VAR_REF)
	{
		if(stackTop->getTypeFromID( this->Left->TO_IR()) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if(this->Right->Type == ASTNodeType::VAR_REF)
	{
		if(stackTop->getTypeFromID( this->Right->TO_IR()) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if (this->Left->Type == ASTNodeType::LITERAL)
	{
		if(static_cast<LiteralNode *> (this->Left)->litType == LiteralType::isINT)
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if (this->Right->Type == ASTNodeType::LITERAL)
	{
		if(static_cast<LiteralNode *> (this->Right)->litType == LiteralType::isINT)
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}

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
	if(this->litType == LiteralType::isINT){
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

	/*ThreeAC putVarInReg = ThreeAC();
	if(isINTType){
		putVarInReg.Fill("STOREI", ident, "", "!T"+std::to_string(availableTemp));
		availableTemp++;
	}else{
		putVarInReg.Fill("STOREF", ident, "", "!T"+std::to_string(availableTemp));
		availableTemp++;
	}

	IR.push_back(putVarInReg);
	putVarInReg.Clear();*/

	return this->ident;
}
