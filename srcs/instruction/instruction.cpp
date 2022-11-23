#include "../../incs/instruction.hpp"
#include <iostream>

Instruction::Instruction(void) {}

Instruction::Instruction(const string &_asm) {
	this->_asm = string(_asm.substr(0, 23));
	_pc = stoul(this->_asm.substr(1, 10), nullptr, 16); // hex string to unsigned long
	_id = stoul(this->_asm.substr(13, 10), nullptr, 16); // hex string to unsigned long
	_rs = (_id >> 21) & 0x1F;
	_rt = (_id >> 16) & 0x1F;
	_rd = (_id >> 11) & 0x1F;
	_imm = _id & 0xFFFF;
	_shamt = (_id >> 6) & 0x1F;
	_funct = _id & 0x3F;
	_opcode = _id >> 26;
	if (_opcode == 0) {
		_format = R;
	} else if (_opcode == 2 || _opcode == 3) {
		_format = J;
	} else {
		_format = I;
	}
	_result = 0;
	_status = IF;
}

Instruction::~Instruction(void) {}

// Getter
int		Instruction::getId(void) { return this->_id; }
int		Instruction::getPc(void) { return this->_pc; }
int		Instruction::getRs(void) { return this->_rs; }
int		Instruction::getRt(void) { return this->_rt; }
int		Instruction::getRd(void) { return this->_rd; }
int		Instruction::getImm(void) { return this->_imm; }
int		Instruction::getShamt(void) { return this->_shamt; }
int		Instruction::getFunct(void) { return this->_funct; }
int		Instruction::getOpcode(void) { return this->_opcode; }
int		Instruction::getResult(void) { return this->_result; }
Format	Instruction::getFormat(void) { return this->_format; }
Status	Instruction::getStatus(void) { return this->_status; }
string	Instruction::getAsm(void) { return this->_asm; }