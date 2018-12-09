
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

void CallNode::printNode()
{
	std::cout << "Type: ";
	printNodeType();
}

void ReturnNode::printNode()
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

FuncNode::FuncNode(std::string name_src, std::vector<ASTNode *> * node_src, SymbolTable * table_src, ASTNodeType type) : ASTNode::ASTNode(type){
	name = name_src;
	node_list = node_src;
	table = table_src;
}

CallNode::CallNode(std::vector<ASTNode *> * node_list_src, std::string name_src, ASTNodeType type) : ASTNode::ASTNode(type){
	node_list = node_list_src;
	name = name_src;
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

WhileNode::WhileNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::vector<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
	jtype = jtype_src;
}

WhileNode::WhileNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = std::vector<ASTNode *>(0);
	blockID = blockID_src;
	jtype = jtype_src;
}

//else defined
IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::vector<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype_src, ElseNode * else_node_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = else_node_src;
}

//else not defined
IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, std::vector<ASTNode *> stmt_nodes_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
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
	stmt_nodes = std::vector<ASTNode *>(0);
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = else_node_src;
}

IfNode::IfNode(ASTNode * cond_node_left_src, ASTNode * cond_node_right_src, int blockID_src, JumpType jtype_src, ASTNodeType type) : ASTNode::ASTNode(type){
	cond_node_left = cond_node_left_src;
	cond_node_right = cond_node_right_src;
	stmt_nodes = std::vector<ASTNode *>(0);
	blockID = blockID_src;
	jtype = jtype_src;
	else_node = new ElseNode(ASTNodeType::ELSE);
}

ElseNode::ElseNode(std::vector<ASTNode *> stmt_nodes_src, int blockID_src, ASTNodeType type) : ASTNode::ASTNode(type){
	stmt_nodes = stmt_nodes_src;
	blockID = blockID_src;
}

ElseNode::ElseNode(int blockID_src, ASTNodeType type) : ASTNode::ASTNode(type){
	stmt_nodes = std::vector<ASTNode *>(0);
	blockID = blockID_src;
}

ElseNode::ElseNode(ASTNodeType type) : ASTNode::ASTNode(type){
	stmt_nodes = std::vector<ASTNode *>(0);
	blockID = -1;
}

ReturnNode::ReturnNode(ASTNodeType type) : ASTNode::ASTNode(type){
	//ret_expr = expr_src;
}

void ElseNode::setBlockID(int blockID_supplied)
{
	blockID = blockID_supplied;
}

void WhileNode::copyStmtList(std::vector<ASTNode *> stmt_nodes_supplied)
{
	stmt_nodes = stmt_nodes_supplied;
}

void IfNode::copyStmtList(std::vector<ASTNode *> stmt_nodes_supplied)
{
	stmt_nodes = stmt_nodes_supplied;
}

void IfNode::copyElseNode(ElseNode * else_node_supplied)
{
	else_node = else_node_supplied;
}

void ElseNode::copyStmtList(std::vector<ASTNode *> stmt_nodes_supplied)
{
	stmt_nodes = stmt_nodes_supplied;
}

std::string FuncNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string funcName = this->name;

    /*toInsert.Fill("PUSH", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("PUSHREGS", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();*/

	/*toInsert.Fill("JSR", "FUNC_"+funcName, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();*/

	/*toInsert.Fill("HALT", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();*/

	toInsert.Fill("LABEL", "FUNC_"+funcName, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	std::string linkNum = "";
	//std::cout << std::to_string(funcTable->numLocals) << std::endl;
	//funcTable->printST();
	//printf("Link num is %d", this->table->numLocals);
	linkNum += std::to_string(this->table->numLocals);

	toInsert.Fill("LINK", linkNum, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	for(auto stmt : *node_list){
		if(stmt)
		{
			availableTemp = 0;
			//std::cout << "Func stmt->TO_IR()" << std::endl;
			stmt->TO_IR(this->table);
		}
	}

	toInsert.Fill("UNLINK", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("RET", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	//std::cout << funcName << std::endl;

	return "";
}

std::string CallNode::TO_IR(SymbolTable * funcTable){
	ThreeAC pushParams = ThreeAC();

	//push return slot onto stack
	typename std::map<std::string, SymbolTableEntry *>::iterator map_it;
	std::string var_location = "";

	pushParams.Fill("PUSH", "", "", "");
	IR.push_back(pushParams);
	pushParams.Clear();

	//push function parameters onto stack
	for(std::vector<ASTNode *>::reverse_iterator expr = node_list->rbegin();	expr != node_list->rend();	++expr){
	//for(auto expr : *node_list){
		var_location = "";
		pushParams.Clear();
		std::string param = (*expr)->TO_IR(funcTable);

		//std::cout << param << std::endl;

		map_it = funcTable->table.find(param);
		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			var_location += "$";
			var_location += std::to_string(funcTable->table.at(param)->slot);
		}else{
			var_location += param;
		}

		pushParams.Fill("PUSH", var_location, "", "");
		IR.push_back(pushParams);
	}

	pushParams.Clear();

	//jump to subroutine
	pushParams.Fill("JSR", "FUNC_"+name, "", "");
	IR.push_back(pushParams);

	//pop arguments off stack
	for(auto expr : *node_list){
		pushParams.Clear();
		pushParams.Fill("POP", "", "", "");
		IR.push_back(pushParams);
	}

	//pop return value off stack into reg
	pushParams.Clear();
	std::string popped_reg = "!T"+std::to_string(availableTemp);
	pushParams.Fill("POP", "", "", popped_reg);
	availableTemp++;
	IR.push_back(pushParams);

	//WATCH OUT FOR THIS LINE
	availableTemp = 0;

	return popped_reg;
}

std::string ReturnNode::TO_IR(SymbolTable * funcTable){
	//no return value
	std::string location = this->Right->TO_IR(funcTable);
	std::string return_slot = "$";
	ThreeAC newReturn = ThreeAC();
	
	if(funcTable->scope == "main")
	{
		
	}
	else if(this->Right == NULL)
	{
		//empty return
		return "";
	}
	else if(this->Right->Type == ASTNodeType::LITERAL)
	{
		//literal
		return_slot += std::to_string(funcTable->numParams + 2);	//= num params + ret pc + ret val offsets
		//std::cout << "Return Slot: " << return_slot << std::endl;
		//if(isINTType){
			newReturn.Fill("STOREI", location, "", return_slot);
		//}else{
		//	newReturn.Fill("STOREF", location, "", return_slot);
		//}
		IR.push_back(newReturn);
		newReturn.Clear();
	}
	else
	{
		//store stack value in tmp
		typename std::map<std::string, SymbolTableEntry *>::iterator map_it = funcTable->table.find(location);
		std::string var_location = "";
		std::string temp_location = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope, it's a var
			var_location += "$";
			var_location += std::to_string(funcTable->table.at(location)->slot);

			temp_location += "!T"+std::to_string(availableTemp);

			if(isINTType){
				newReturn.Fill("STOREI", var_location, "", temp_location);
				availableTemp++;
			}else{
				newReturn.Fill("STOREF", var_location, "", temp_location);
				availableTemp++;
			}
			IR.push_back(newReturn);
			newReturn.Clear();
		}else{
			//right result is a complex expression, stored in tmp
			temp_location = location;
		}

		//store tmp in return slot
		std::string return_location = "$";
		return_location += std::to_string(funcTable->numParams + 2);
		if(isINTType){
			newReturn.Fill("STOREI", temp_location, "", return_location);
			availableTemp++;
		}else{
			newReturn.Fill("STOREF", temp_location, "", return_location);
			availableTemp++;
		}
		IR.push_back(newReturn);
		newReturn.Clear();
	}
	newReturn.Clear();
	//add link and return
	newReturn.Fill("UNLINK", "", "", "");
	IR.push_back(newReturn);
	newReturn.Clear();

	newReturn.Fill("RET", "", "", "");
	IR.push_back(newReturn);
	newReturn.Clear();

	//availableTemp = 0;

	return "";
}

std::string AssignNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string idKey = this->Left->TO_IR(funcTable);
	//SymbolTable * stackTop = ststack.top();
	ThreeAC newAssign = ThreeAC();

	std::string targetTmpy = this->Right->TO_IR(funcTable);

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it;
	std::string lookup_slot = "";
	
	if(funcTable->getTypeFromID(idKey) == "INT")
	{
		isINTType = 1;
	}else{
		isINTType = 0;
	}

	if(this->Right->Type == ASTNodeType::CALL_EXPR)
	{
		//we're just storing the result from the function call here (from return slot)
		//get slot for left ref
		map_it = funcTable->table.find(idKey);
		lookup_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			lookup_slot += "$";
			lookup_slot += std::to_string(funcTable->table.at(idKey)->slot);
		}else{
			lookup_slot += idKey;
		}

		if(isINTType){
			newAssign.Fill("STOREI", targetTmpy, "", lookup_slot);
		}else{
			newAssign.Fill("STOREF", targetTmpy, "", lookup_slot);
		}
		IR.push_back(newAssign);
		newAssign.Clear();
	}
	else if(this->Right->Type == ASTNodeType::VAR_REF)
	{	
		map_it = funcTable->table.find(targetTmpy);
		lookup_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			lookup_slot += "$";
			lookup_slot += std::to_string(funcTable->table.at(targetTmpy)->slot);
		}else{
			lookup_slot += targetTmpy;
		}

		//get a new tmpy
		std::string tmp = "";
		tmp += "!T"+std::to_string(availableTemp);
		availableTemp++;

		//store right ref's stack slot into tmpy
		if(isINTType){
			newAssign.Fill("STOREI", lookup_slot, "", tmp);
		}else{
			newAssign.Fill("STOREF", lookup_slot, "", tmp);
		}
		IR.push_back(newAssign);
		newAssign.Clear();

		//get slot for left ref
		map_it = funcTable->table.find(idKey);
		lookup_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			lookup_slot += "$";
			lookup_slot += std::to_string(funcTable->table.at(idKey)->slot);
		}
		else
		{
			lookup_slot += idKey;
		}

		//store tmpy into left ref's stack slot
		if(isINTType){
			newAssign.Fill("STOREI", tmp, "", lookup_slot);
		}else{
			newAssign.Fill("STOREF", tmp, "", lookup_slot);
		}
		IR.push_back(newAssign);
		newAssign.Clear();
	}else{
		//storing any type of expression on the right
		//get lookup slot for left ref
		map_it = funcTable->table.find(idKey);
		lookup_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			lookup_slot += "$";
			lookup_slot += std::to_string(funcTable->table.at(idKey)->slot);
		}else{
			lookup_slot += idKey;
		}

		//store tmpy into left ref's stack slot
		if(isINTType){
			newAssign.Fill("STOREI", targetTmpy, "", lookup_slot);
		}else{
			newAssign.Fill("STOREF", targetTmpy, "", lookup_slot);
		}
		IR.push_back(newAssign);
		newAssign.Clear();
	}
	
	return "";
}

std::string IfNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//std::cout << "IfNode->TO_IR()" << std::endl;
	std::string else_start = "ELSE_" + std::to_string(this->blockID);
	std::string else_end = "END_IF_ELSE_" + std::to_string(this->blockID);

	std::string leftIdent = this->cond_node_left->TO_IR(funcTable);
	std::string rightIdent = this->cond_node_right->TO_IR(funcTable);

	if(funcTable->getTypeFromID(leftIdent) == "INT")
	{
		isINTType = 1;
	}else{
		isINTType = 0;
	}

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it = funcTable->table.find(leftIdent);
	std::string return_slot_left = "";
	if(map_it != funcTable->table.end())
	{
		//found entry in func scope
		return_slot_left += "$";
		return_slot_left += std::to_string(funcTable->table.at(leftIdent)->slot);
	}
	else
	{
		return_slot_left += leftIdent;
	}

	std::string leftLocation = return_slot_left;

	map_it = funcTable->table.find(rightIdent);
	std::string return_slot_right = "";
	if(map_it != funcTable->table.end())
	{
		//found entry in func scope
		return_slot_right += "$";
		return_slot_right += std::to_string(funcTable->table.at(rightIdent)->slot);
	}
	else
	{
		return_slot_right = rightIdent;
	}

	std::string rightLocation = return_slot_right;

	std::string rightRef = "";

	ThreeAC * branch_stmt = new ThreeAC();

	if( (this->cond_node_left->Type == ASTNodeType::VAR_REF) && (this->cond_node_right->Type == ASTNodeType::VAR_REF) )
	{
		ThreeAC putVarInReg = ThreeAC();
		if(isINTType){
			putVarInReg.Fill("STOREI", rightLocation, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			putVarInReg.Fill("STOREF", rightLocation, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}

		rightRef += putVarInReg.result;
		IR.push_back(putVarInReg);

		putVarInReg.Clear();
	}else{
		rightRef += rightLocation;
	}

	//std::cout << "Left tmp: " << leftLocation << "\t" << "Right tmp: " << rightLocation << std::endl;

	if(funcTable->getTypeFromID(leftIdent) == "INT")
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				branch_stmt->Fill("LEI", leftLocation, rightRef, else_start);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTI", leftLocation, rightRef, else_start);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEI", leftLocation, rightRef, else_start);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTI", leftLocation, rightRef, else_start);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQI", leftLocation, rightRef, else_start);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEI", leftLocation, rightRef, else_start);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
	}
	else if(funcTable->getTypeFromID(leftIdent) == "FLOAT")
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				branch_stmt->Fill("LEF", leftLocation, rightRef, else_start);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTF", leftLocation, rightRef, else_start);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEF", leftLocation, rightRef, else_start);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTF", leftLocation, rightRef, else_start);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQF", leftLocation, rightRef, else_start);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEF", leftLocation, rightRef, else_start);
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
			availableTemp = 0;
			//std::cout << "if stmts->TO_IR()" << std::endl;
			stmt->TO_IR(funcTable);
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
			else_node->TO_IR(funcTable);
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

std::string ElseNode::TO_IR(SymbolTable * funcTable){
	//std::cout << "ElseNode->TO_IR()" << std::endl;
	//std::cout << stmt_nodes.size() << std::endl;
	
	for(auto stmt : this->stmt_nodes){
		if(stmt)
		{
			availableTemp = 0;
			//std::cout << "else stmt->TO_IR()" << std::endl;
			stmt->TO_IR(funcTable);
		}
	}

	return "";
}

std::string WhileNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	//std::cout << "in WhileNode->TO_IR()" << std::endl;
	std::string while_start = "WHILE_START_" + std::to_string(this->blockID);
	std::string while_end = "WHILE_END_" + std::to_string(this->blockID);

	toInsert.Fill("LABEL", while_start, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	//std::cout << std::to_string(this->blockID) << std::endl;

	std::string leftIdent = this->cond_node_left->TO_IR(funcTable);
	std::string rightIdent = this->cond_node_right->TO_IR(funcTable);
	std::string rightRef = "";

	ThreeAC * branch_stmt = new ThreeAC();
	//SymbolTable * stackTop = ststack.top();

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it = funcTable->table.find(leftIdent);
	std::string return_slot_left = "";
	if(map_it != funcTable->table.end())
	{
		//found entry in func scope
		return_slot_left += "$";
		return_slot_left += std::to_string(funcTable->table.at(leftIdent)->slot);
	}
	else
	{
		return_slot_left += leftIdent;
	}

	map_it = funcTable->table.find(rightIdent);
	std::string return_slot_right = "";
	if(map_it != funcTable->table.end())
	{
		//found entry in func scope
		return_slot_right += "$";
		return_slot_right += std::to_string(funcTable->table.at(rightIdent)->slot);
	}
	else
	{
		return_slot_right = rightIdent;
	}

	if( /*(this->cond_node_left->Type == ASTNodeType::VAR_REF) &&*/ (this->cond_node_right->Type == ASTNodeType::VAR_REF) )
	{
		ThreeAC putVarInReg = ThreeAC();
		if(isINTType){
			putVarInReg.Fill("STOREI", return_slot_right, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			putVarInReg.Fill("STOREF", return_slot_right, "", "!T"+std::to_string(availableTemp));
			availableTemp++;
		}

		rightRef = putVarInReg.result;
		IR.push_back(putVarInReg);

		putVarInReg.Clear();
	}else{
		rightRef = return_slot_right;
	}

	if(funcTable->getTypeFromID(leftIdent) == "SHIT")
	{
		if(funcTable->getTypeFromID(rightIdent) == "INT")
		{
			switch(jtype)
			{
				case JumpType::G_T:	
					
					branch_stmt->Fill("LEI", return_slot_left, rightRef, while_end);
					break;
				case JumpType::G_E:
					branch_stmt->Fill("LTI", return_slot_left, rightRef, while_end);
					break;
				case JumpType::L_T:
					branch_stmt->Fill("GEI", return_slot_left, rightRef, while_end);
					break;
				case JumpType::L_E:
					branch_stmt->Fill("GTI", return_slot_left, rightRef, while_end);
					break;
				case JumpType::N_E:
					branch_stmt->Fill("EQI", return_slot_left, rightRef, while_end);
					break;
				case JumpType::E_Q:
					branch_stmt->Fill("NEI", return_slot_left, rightRef, while_end);
					break;
				default:
					std::cout << "There's some branching error here\n";
			}
		}else{
			switch(jtype)
		{
			case JumpType::G_T:	
				branch_stmt->Fill("LEF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEF", return_slot_left, rightRef, while_end);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
		}
	}
	else if(funcTable->getTypeFromID(leftIdent) == "INT")
	{
		switch(jtype)
		{
			case JumpType::G_T:	
				
				branch_stmt->Fill("LEI", return_slot_left, rightRef, while_end);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTI", return_slot_left, rightRef, while_end);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEI", return_slot_left, rightRef, while_end);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTI", return_slot_left, rightRef, while_end);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQI", return_slot_left, rightRef, while_end);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEI", return_slot_left, rightRef, while_end);
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
				branch_stmt->Fill("LEF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::G_E:
				branch_stmt->Fill("LTF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::L_T:
				branch_stmt->Fill("GEF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::L_E:
				branch_stmt->Fill("GTF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::N_E:
				branch_stmt->Fill("EQF", return_slot_left, rightRef, while_end);
				break;
			case JumpType::E_Q:
				branch_stmt->Fill("NEF", return_slot_left, rightRef, while_end);
				break;
			default:
				std::cout << "There's some branching error here\n";
		}
	}

	IR.push_back(*branch_stmt);

	for(auto stmt : stmt_nodes){
		if(stmt)
		{
			availableTemp = 0;
			//std::cout << "while stmt->TO_IR()" << std::endl;
			stmt->TO_IR(funcTable);
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

std::string WriteNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	ThreeAC currWrite = ThreeAC();

	int isString = 0;

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it; 
	std::string write_slot;

	for(std::list<std::string>::const_iterator i = this->ident_list->begin(); i != this->ident_list->end(); i++)	
	{
		write_slot = "";
		//std::cout << ";\t" << *i << std::endl;
		//std::cout << ";\t" << funcTable->getTypeFromID(*i) << std::endl;

		if(funcTable->getTypeFromID(*i) == "STRING")
		{
			isString = 1;
		}else{
			isString = 0;
		}

		if(funcTable->getTypeFromID(*i) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}

		map_it = funcTable->table.find(*i);
		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			write_slot += "$";
			write_slot += std::to_string(funcTable->table.at(*i)->slot);
		}else{
			write_slot += *i;
		}

		if(isString){
			currWrite.Fill("WRITES", write_slot, "", "");
		}else if(isINTType){
			currWrite.Fill("WRITEI", write_slot, "", "");
		}else{
			currWrite.Fill("WRITEF", write_slot, "", "");
		}
		IR.push_back(currWrite);
		currWrite.Clear();
	}

	return "";
}

std::string ReadNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	ThreeAC currRead = ThreeAC();

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it; 
	std::string read_slot;

	for(std::list<std::string>::const_iterator j = this->ident_list2->begin(); j != this->ident_list2->end(); j++)	
	{
		if(funcTable->getTypeFromID(*j) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}

		map_it = funcTable->table.find(*j);

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			read_slot += "$";
			read_slot += std::to_string(funcTable->table.at(*j)->slot);
		}else{
			read_slot += *j;
		}

		if(isINTType){
			currRead.Fill("READI", "", "", read_slot);
		}else{
			currRead.Fill("READF", "", "", read_slot);
		}
		IR.push_back(currRead);
		read_slot = "";
		currRead.Clear();
	}

	return "";
}

std::string AddExprNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);

	std::string leftTmpy = this->Left->TO_IR(funcTable);
	std::string rightTmpy = this->Right->TO_IR(funcTable);

	ThreeAC newAdd = ThreeAC();

	//SymbolTable * stackTop = ststack.top();

	if(this->Left->Type == ASTNodeType::VAR_REF)
	{
		if(funcTable->getTypeFromID( this->Left->TO_IR(funcTable)) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if(this->Right->Type == ASTNodeType::VAR_REF)
	{
		if(funcTable->getTypeFromID( this->Right->TO_IR(funcTable)) == "INT")
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

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it; 
	std::string left_slot = leftTmpy;
	std::string right_slot = rightTmpy;

	if(this->Left->Type == ASTNodeType::VAR_REF){
		map_it = funcTable->table.find(leftTmpy);
		left_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			left_slot += "$";
			left_slot += std::to_string(funcTable->table.at(leftTmpy)->slot);
		}
		else
		{
			left_slot += leftTmpy;
		}
	}

	if(this->Right->Type == ASTNodeType::VAR_REF){
		map_it = funcTable->table.find(rightTmpy);
		right_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			right_slot += "$";
			right_slot += std::to_string(funcTable->table.at(rightTmpy)->slot);
		}
		else
		{
			right_slot += rightTmpy;
		}
	}

	if(this->add_op == "+")
	{
		if(isINTType){
			newAdd.Fill("ADDI", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newAdd.Fill("ADDF", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}else{
		if(isINTType){
			newAdd.Fill("SUBI", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newAdd.Fill("SUBF", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}

	IR.push_back(newAdd);
	//newAdd.Clear();

	//this->printTree();
	return newAdd.result;
}

std::string MulExprNode::TO_IR(SymbolTable * funcTable){
	//printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
	std::string leftTmpry = this->Left->TO_IR(funcTable);
	std::string rightTmpry = this->Right->TO_IR(funcTable);

	ThreeAC newMult = ThreeAC();

	//SymbolTable * stackTop = ststack.top();

	if(this->Left->Type == ASTNodeType::VAR_REF)
	{
		if(funcTable->getTypeFromID( this->Left->TO_IR(funcTable)) == "INT")
		{
			isINTType = 1;
		}else{
			isINTType = 0;
		}
	}
	else if(this->Right->Type == ASTNodeType::VAR_REF)
	{
		if(funcTable->getTypeFromID( this->Right->TO_IR(funcTable)) == "INT")
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

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it; 
	std::string left_slot = leftTmpry;
	std::string right_slot = rightTmpry;

	if(this->Left->Type == ASTNodeType::VAR_REF){
		map_it = funcTable->table.find(leftTmpry);
		left_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			left_slot += "$";
			left_slot += std::to_string(funcTable->table.at(leftTmpry)->slot);
		}
		else
		{
			left_slot += leftTmpry;
		}
	}

	if(this->Right->Type == ASTNodeType::VAR_REF){
		map_it = funcTable->table.find(rightTmpry);
		right_slot = "";

		if(map_it != funcTable->table.end())
		{
			//found entry in func scope
			right_slot += "$";
			right_slot += std::to_string(funcTable->table.at(rightTmpry)->slot);
		}
		else
		{
			right_slot += rightTmpry;
		}
	}

	if(this->mul_op == "*")
	{
		if(isINTType){
			newMult.Fill("MULI", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newMult.Fill("MULF", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}else{
		if(isINTType){
			newMult.Fill("DIVI", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}else{
			newMult.Fill("DIVF", left_slot, right_slot, "!T"+std::to_string(availableTemp));
			availableTemp++;
		}
	}

	IR.push_back(newMult);

	return newMult.result;
}

std::string LiteralNode::TO_IR(SymbolTable * funcTable){
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

std::string VarRefNode::TO_IR(SymbolTable * funcTable){
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
	/*typename std::map<std::string, SymbolTableEntry *>::iterator map_it = funcTable->table.find(this->ident);
	std::string return_slot = "";
	if(map_it != funcTable->table.end())
	{
		//found entry in func scope
		return_slot += "$";
		return_slot += std::to_string(funcTable->table.at(this->ident)->slot);
		return return_slot;
	}*/

	return this->ident;
}