#include "../../incs/instruction.hpp"
#include <iostream>

Instruction::Instruction(void) {}

Instruction::Instruction(const string &asmString) {
	this->asmString = string(asmString.substr(0, 23));
	this->pc = stoul(this->asmString.substr(1, 10), nullptr, 16); // hex string to unsigned long
	this->id = stoul(this->asmString.substr(13, 10), nullptr, 16); // hex string to unsigned long
	this->rs = (this->id >> 21) & 0x1F;
	this->rt = (this->id >> 16) & 0x1F;
	this->rd = (this->id >> 11) & 0x1F;
	this->imm = this->id & 0xFFFF;
	this->shamt = (this->id >> 6) & 0x1F;
	this->funct = this->id & 0x3F;
	this->opcode = this->id >> 26;
	if (this->opcode == 0) {
		this->format = R;
	} else if (this->opcode == 2 || this->opcode == 3) {
		this->format = J;
	} else {
		this->format = I;
	}
	this->result = 0;
	this->status = IF;
}

Instruction::~Instruction(void) {}

// Getter
int		Instruction::get_id(void) { return this->id; }
int		Instruction::get_pc(void) { return this->pc; }
int		Instruction::get_rs(void) { return this->rs; }
int		Instruction::get_rt(void) { return this->rt; }
int		Instruction::get_rd(void) { return this->rd; }
int		Instruction::get_imm(void) { return this->imm; }
int		Instruction::get_shamt(void) { return this->shamt; }
int		Instruction::get_funct(void) { return this->funct; }
int		Instruction::get_opcode(void) { return this->opcode; }
int		Instruction::get_result(void) { return this->result; }
Format	Instruction::get_format(void) { return this->format; }
Status	Instruction::get_status(void) { return this->status; }
string	Instruction::get_asm_string(void) { return this->asmString; }