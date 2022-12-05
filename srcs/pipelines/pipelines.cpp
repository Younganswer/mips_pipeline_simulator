#include "../../incs/pipelines.hpp"
#include <iostream>

IFID::IFID(void) { this->pc = 0; this->id = 0; this->instruction = Instruction(); }
IFID::~IFID(void) {}

// IFID getter
ui			IFID::get_pc(void) const { return (this->pc); }
ui			IFID::get_id(void) const { return (this->id); }
Instruction	IFID::get_instruction(void) { return (this->instruction); }

// IFID setter
bool	IFID::set_pc(ui pc) { this->pc = pc; return (true); }
bool	IFID::set_id(ui id) { this->id = id; return (true); }
bool	IFID::set_instruction(const Instruction &instruction) { this->instruction = instruction; return (true); }

IDEX::IDEX(void) {}
IDEX::~IDEX(void) {}

// IDEX getter
ui	IDEX::get_alu_op(void) const { return (this->aluOp); }
ui	IDEX::get_alu_src(void) const { return (this->aluSrc); }
ui	IDEX::get_reg_dst(void) const { return (this->regDst); }
ui	IDEX::get_mem_write(void) const { return (this->memWrite); }
ui	IDEX::get_mem_read(void) const { return (this->memRead); }
ui	IDEX::get_branch(void) const { return (this->branch); }
ui	IDEX::get_reg_write(void) const { return (this->regWrite); }
ui	IDEX::get_mem_to_reg(void) const { return (this->memToReg); }
ui	IDEX::get_read_data1(void) const { return (this->readData1); }
ui	IDEX::get_read_data2(void) const { return (this->readData2); }
ui	IDEX::get_extend_imm(void) const { return (this->extendImm); }
ui	IDEX::get_rs(void) const { return (this->rs); }
ui	IDEX::get_rt(void) const { return (this->rt); }
ui	IDEX::get_rd(void) const { return (this->rd); }
Instruction	IDEX::get_instruction(void) { return (this->instruction); }

// IDEX setter
bool	IDEX::set_alu_op(ui aluOp) { this->aluOp = aluOp; return (true); }
bool	IDEX::set_alu_src(ui aluSrc) { this->aluSrc = aluSrc; return (true); }
bool	IDEX::set_reg_dst(ui regDst) { this->regDst = regDst; return (true); }
bool	IDEX::set_mem_write(ui memWrite) { this->memWrite = memWrite; return (true); }
bool	IDEX::set_mem_read(ui memRead) { this->memRead = memRead; return (true); }
bool	IDEX::set_branch(ui branch) { this->branch = branch; return (true); }
bool	IDEX::set_reg_write(ui regWrite) { this->regWrite = regWrite; return (true); }
bool	IDEX::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; return (true); }
bool	IDEX::set_read_data_1(ui readData1) { this->readData1 = readData1; return (true); }
bool	IDEX::set_read_data_2(ui readData2) { this->readData2 = readData2; return (true); }
bool	IDEX::set_extend_imm(ui extendImm) { this->extendImm = extendImm; return (true); }
bool	IDEX::set_rs(ui rs) { this->rs = rs; return (true); }
bool	IDEX::set_rt(ui rt) { this->rt = rt; return (true); }
bool	IDEX::set_rd(ui rd) { this->rd = rd; return (true); }
bool	IDEX::set_instruction(const Instruction &instruction) { this->instruction = instruction; return (true); }

//calculate ALUop by opcode and funct
ui	IDEX::calc_alu_op(ui opcode, ui funct) {
	if (opcode == 0) {
		if (funct == FUNCTYPE_ADD)
			return (ALUOP_ADD);
		else if (funct == FUNCTYPE_SUB)
			return (ALUOP_SUB);
		else if (funct == FUNCTYPE_AND)
			return (ALUOP_AND);
		else if (funct == FUNCTYPE_OR)
			return (ALUOP_OR);
		else if (funct == FUNCTYPE_SLT)
			return (ALUOP_SLT);
	}
	else if (opcode == 2)
		return (ALUOP_JUMP);
	else if (opcode == 4)
		return (ALUOP_BEQ);
	else if (opcode == 35)
		return (ALUOP_LW);
	else if (opcode == 43)
		return (ALUOP_SW);
	return (-1);
}

EXMEM::EXMEM(void) {}
EXMEM::~EXMEM(void) {}

// EXMEM getter
ui	EXMEM::get_mem_write(void) { return (this->memWrite); }
ui	EXMEM::get_mem_read(void) { return (this->memRead); }
ui	EXMEM::get_branch(void) { return (this->branch); }
ui	EXMEM::get_reg_write(void) { return (this->regWrite); }
ui	EXMEM::get_mem_to_reg(void) { return (this->memToReg); }
ui	EXMEM::get_add_result(void) { return (this->addResult); }
ui	EXMEM::get_zero_flag(void) { return (this->zeroFlag); }
ui	EXMEM::get_alu_result(void) { return (this->aluResult); }
ui	EXMEM::get_read_data_2(void) { return (this->readData2); }
ui	EXMEM::get_extend_imm(void) { return (this->extendImm); }
ui	EXMEM::get_write_data(void) { return (this->writeData); }
Instruction	EXMEM::get_instruction(void) { return (this->instruction); }

// EXMEM setter
void	EXMEM::set_mem_write(ui memWrite) { this->memWrite = memWrite; }
void	EXMEM::set_mem_read(ui memRead) { this->memRead = memRead; }
void	EXMEM::set_branch(ui branch) { this->branch = branch; }
void	EXMEM::set_reg_write(ui regWrite) { this->regWrite = regWrite; }
void	EXMEM::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; }
void	EXMEM::set_add_result(ui addResult) { this->addResult = addResult; }
void	EXMEM::set_zero_flag(ui zeroFlag) { this->zeroFlag = zeroFlag; }
void	EXMEM::set_alu_result(ui aluResult) { this->aluResult = aluResult; }
void	EXMEM::set_read_data_2(ui readData2) { this->readData2 = readData2; }
void	EXMEM::set_extend_imm(ui extendImm) { this->extendImm = extendImm; }
void	EXMEM::set_write_data(ui writeData) { this->writeData = writeData; }
void	EXMEM::set_instruction(const Instruction &instruction) { this->instruction = instruction; }

//MEMWB constructor and destructor
MEMWB::MEMWB(void) {}
MEMWB::~MEMWB(void) {}

// MEMWB getter
ui	MEMWB::get_reg_write(void) { return (this->regWrite); }
ui	MEMWB::get_mem_to_reg(void) { return (this->memToReg); }
ui	MEMWB::get_read_data(void) { return (this->readData); }
ui	MEMWB::get_alu_result(void) { return (this->aluResult); }
Instruction	MEMWB::get_instruction(void) { return (this->instruction); }

// MEMWB setter
void	MEMWB::set_reg_write(ui regWrite) { this->regWrite = regWrite; }
void	MEMWB::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; }
void	MEMWB::set_read_data(ui readData) { this->readData = readData; }
void	MEMWB::set_alu_result(ui aluResult) { this->aluResult = aluResult; }
void	MEMWB::set_instruction(const Instruction &instruction) { this->instruction = instruction; }
