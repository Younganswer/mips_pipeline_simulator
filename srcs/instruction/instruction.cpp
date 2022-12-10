#include "../../incs/instruction.hpp"
#include <iostream>

Instruction::Instruction(void) {
	this->asmString = string();
	this->pc = 0;
	this->id = 0;
	this->rs = 0;
	this->rt = 0;
	this->rd = 0;
	this->imm = 0;
	this->shamt = 0;
	this->funct = 0;
	this->opcode = 0;
	this->result = 0;
	this->format = R;
	this->status = IF;
}

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
ui		Instruction::get_id(void) const { return this->id; }
ui		Instruction::get_pc(void) const { return this->pc; }
int		Instruction::get_rs(void) const { return this->rs; }
int		Instruction::get_rt(void) const { return this->rt; }
int		Instruction::get_rd(void) const { return this->rd; }
int		Instruction::get_imm(void) const { return this->imm; }
int		Instruction::get_shamt(void) const { return this->shamt; }
int		Instruction::get_funct(void) const { return this->funct; }
int		Instruction::get_opcode(void) const { return this->opcode; }
int		Instruction::get_result(void) const { return this->result; }
Format	Instruction::get_format(void) const { return this->format; }
Status	Instruction::get_status(void) const { return this->status; }
string	Instruction::get_asm_string(void) const { return this->asmString; }

// Setter
bool	Instruction::set_pc(ui pc) { this->pc = pc; return (true); }
bool	Instruction::set_status(Status status) { this->status = status; return (true); }