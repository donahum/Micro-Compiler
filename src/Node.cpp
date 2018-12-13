
#include "Node.hpp"

int currentReg = 0;
int isINTType = 0;//1 for int, 0 for float
ThreeAC toInsert;
std::vector<ThreeAC> IR;
extern std::stack<SymbolTable*> ststack; 

//vector to track what registers need to be preserved
//0 = free, 1 = preserved
std::vector<int> lockArray {0, 0, 0, 0};

void clearLockArray()
{
	for(auto &reg : lockArray)
	{
		reg = 0;
	}
}

void freeTemporary(std::string tmp)
{
	std::string returnStr = tmp;
    std::string tmpForm = "!T";

    int regIndex = -1;

    if(returnStr.find("!T") != std::string::npos)
    {
    	//this is indeed a register
        returnStr.replace(returnStr.find(tmpForm), tmpForm.length(), "");
        regIndex = std::stoi(returnStr);
        lockArray[regIndex] = 0;
    }else{
        //this is a memory location, not a register
    }
}

int generateTemporary()
{
	if(lockArray[0] == 0){
		lockArray[0] = 1;
		return 0;
	}else if(lockArray[1] == 0){
		lockArray[1] = 1;
		return 1;
	}else if(lockArray[2] == 0){
		lockArray[2] = 1;
		return 2;
	}else if(lockArray[3] == 0){
		lockArray[3] = 1;
		return 3;
	}

	return NULL;
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
	std::string funcName = this->name;

	toInsert.Fill("LABEL", "FUNC_"+funcName, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	std::string linkNum = "";
	linkNum += std::to_string(this->table->numLocals);

	toInsert.Fill("LINK", linkNum, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	for(auto stmt : *node_list){
		if(stmt)
		{
			clearLockArray();
			stmt->TO_IR(this->table);
		}
	}

	toInsert.Fill("UNLINK", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("RET", "", "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	return "";
}

std::string CallNode::TO_IR(SymbolTable * funcTable){
	ThreeAC pushParams = ThreeAC();

	std::vector<int> preserveSet {0, 0, 0, 0};

	typename std::map<std::string, SymbolTableEntry *>::iterator map_it;
	std::string var_location = "";

	//push return slot onto stack
	pushParams.Fill("PUSH", "", "", "");
	IR.push_back(pushParams);
	pushParams.Clear();

	//save registers on the stack, before the return slot, arguments, and jsr
	for(int i = 0; i < 4; i++)
	{
		//save regs that are still live
		preserveSet[i] = lockArray[i];
		if(lockArray[i] == 1)
		{
			//only push if live
			pushParams.Fill("PUSH", "!T"+std::to_string(i), "", "");
			IR.push_back(pushParams);
			pushParams.Clear();
		}
		//clear this for the next function to work with
		lockArray[i] = 0;
	}

	//push function parameters onto stack
	//for(auto expr : *node_list){
	for(std::vector<ASTNode *>::reverse_iterator expr = node_list->rbegin();	expr != node_list->rend();	++expr)
	{
		var_location = "";
		pushParams.Clear();
		std::string param = (*expr)->TO_IR(funcTable);

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

	//pop saved regs
	for(int i = 3; i >= 0; i--)
	{
		if(preserveSet[i] == 1)
		{
			pushParams.Clear();
			pushParams.Fill("POP", "", "", "!T"+std::to_string(i));
			IR.push_back(pushParams);
		}
		lockArray[i] = preserveSet[i];
		preserveSet[i] = 0;
	}

	//pop return value off stack into reg
	pushParams.Clear();
	currentReg = generateTemporary();
	std::string popped_reg = "!T"+std::to_string(currentReg);
	pushParams.Fill("POP", "", "", popped_reg);
	IR.push_back(pushParams);

	//WATCH OUT FOR THIS LINE
	clearLockArray();

	return popped_reg;
}

std::string ReturnNode::TO_IR(SymbolTable * funcTable){
	//no return value
	std::string location = this->Right->TO_IR(funcTable);
	std::string return_slot = "$";
	ThreeAC newReturn = ThreeAC();
	
	if(funcTable->scope == "main")
	{
		//don't return shit to main, it only causes issues
	}else{
		if(this->Right == NULL)
		{
			//empty return
			return "";
		}
		else if(this->Right->Type == ASTNodeType::LITERAL)
		{
			return_slot += std::to_string(funcTable->numParams + 2);	//= num params + ret pc + ret val offsets
			newReturn.Fill("STOREI", location, "", return_slot);
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

				currentReg = generateTemporary();
				temp_location += "!T"+std::to_string(currentReg);

				if(isINTType){
					newReturn.Fill("STOREI", var_location, "", temp_location);
				}else{
					newReturn.Fill("STOREF", var_location, "", temp_location);
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
			}else{
				newReturn.Fill("STOREF", temp_location, "", return_location);
			}
			IR.push_back(newReturn);
			newReturn.Clear();

			freeTemporary(temp_location);
		}
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
	ThreeAC newAssign = ThreeAC();
	std::string idKey = this->Left->TO_IR(funcTable);
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
		freeTemporary(targetTmpy);
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

		currentReg = generateTemporary();
		std::string tmp = "!T"+std::to_string(currentReg);

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
		freeTemporary(tmp);
	}else{
		std::cout << ";LockArray: " << lockArray[0] << lockArray[1] << lockArray[2] << lockArray[3] << std::endl;
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
		freeTemporary(targetTmpy);
	}
	
	return "";
}

std::string IfNode::TO_IR(SymbolTable * funcTable){
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
			currentReg = generateTemporary();
			putVarInReg.Fill("STOREI", rightLocation, "", "!T"+std::to_string(currentReg));
		}else{
			currentReg = generateTemporary();
			putVarInReg.Fill("STOREF", rightLocation, "", "!T"+std::to_string(currentReg));
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
			clearLockArray();
			stmt->TO_IR(funcTable);
		}
	}	

	toInsert.Fill("JUMP", else_end, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	toInsert.Fill("LABEL", else_start, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	if(else_node){
		else_node->TO_IR(funcTable);
	}

	toInsert.Fill("LABEL", else_end, "", "");
	IR.push_back(toInsert);
	toInsert.Clear();

	return "";
}

std::string ElseNode::TO_IR(SymbolTable * funcTable){
	//std::cout << "ElseNode->TO_IR()" << std::endl;
	//std::cout << stmt_nodes.size() << std::endl;
	
	for(auto stmt : this->stmt_nodes){
		if(stmt)
		{
			clearLockArray();
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
			currentReg = generateTemporary();
			putVarInReg.Fill("STOREI", return_slot_right, "", "!T"+std::to_string(currentReg));
		}else{
			currentReg = generateTemporary();
			putVarInReg.Fill("STOREF", return_slot_right, "", "!T"+std::to_string(currentReg));
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

	freeTemporary(return_slot_left);

	IR.push_back(*branch_stmt);

	for(auto stmt : stmt_nodes){
		if(stmt)
		{
			clearLockArray();
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
	ThreeAC newAdd = ThreeAC();
	std::string leftTmpy = this->Left->TO_IR(funcTable);

	if(this->Right->Type == ASTNodeType::CALL_EXPR)
	{
		newAdd.Fill("PUSH", leftTmpy, "", "");
		IR.push_back(newAdd);
		newAdd.Clear();
		freeTemporary(leftTmpy);
	}

	std::string rightTmpy = this->Right->TO_IR(funcTable);

	if(this->Right->Type == ASTNodeType::CALL_EXPR)
	{
		currentReg = generateTemporary();
		leftTmpy = "!T"+std::to_string(currentReg);
		newAdd.Fill("POP", "", "", leftTmpy);
	}
	
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
			//global or temp
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
			//global or temp
			right_slot += rightTmpy;
		}
	}

	if(this->add_op == "+")
	{
		if(isINTType){
			currentReg = generateTemporary();
			newAdd.Fill("ADDI", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}else{
			currentReg = generateTemporary();
			newAdd.Fill("ADDF", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}
	}else{
		if(isINTType){
			currentReg = generateTemporary();
			newAdd.Fill("SUBI", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}else{
			currentReg = generateTemporary();
			newAdd.Fill("SUBF", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}
	}

	IR.push_back(newAdd);

	freeTemporary(left_slot);
	freeTemporary(right_slot);

	return newAdd.result;
}

std::string MulExprNode::TO_IR(SymbolTable * funcTable){
	ThreeAC newMult = ThreeAC();
	std::string leftTmpry = this->Left->TO_IR(funcTable);

	if(this->Right->Type == ASTNodeType::CALL_EXPR)
	{
		newMult.Fill("PUSH", leftTmpry, "", "");
		IR.push_back(newMult);
		newMult.Clear();
		freeTemporary(leftTmpry);
	}

	std::string rightTmpry = this->Right->TO_IR(funcTable);

	if(this->Right->Type == ASTNodeType::CALL_EXPR)
	{
		currentReg = generateTemporary();
		leftTmpry = "!T"+std::to_string(currentReg);
		newMult.Fill("POP", "", "", leftTmpry);
	}

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
			currentReg = generateTemporary();
			newMult.Fill("MULI", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}else{
			currentReg = generateTemporary();
			newMult.Fill("MULF", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}
	}else{
		if(isINTType){
			currentReg = generateTemporary();
			newMult.Fill("DIVI", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}else{
			currentReg = generateTemporary();
			newMult.Fill("DIVF", left_slot, right_slot, "!T"+std::to_string(currentReg));
		}
	}

	IR.push_back(newMult);

	freeTemporary(left_slot);
	freeTemporary(right_slot);

	return newMult.result;
}

std::string LiteralNode::TO_IR(SymbolTable * funcTable){
	ThreeAC newLit = ThreeAC();
	if(this->litType == LiteralType::isINT){
		currentReg = generateTemporary();
		newLit.Fill("STOREI", this->val, "", "!T"+std::to_string(currentReg));
	}else{
		currentReg = generateTemporary();
		newLit.Fill("STOREF", this->val, "", "!T"+std::to_string(currentReg));
	}
	IR.push_back(newLit);

	return newLit.result;
}

std::string VarRefNode::TO_IR(SymbolTable * funcTable){
	return this->ident;
}