#include "../../incs/pipelines.hpp"
#include <iostream>

// IFID pipeline
IFID::IFID(void) { this->pc = 0; this->instructionHex = 0; this->instruction = Instruction(); }
IFID::~IFID(void) {}

// IFID getter
ui			IFID::get_pc(void) const { return (this->pc); }
ui			IFID::get_instruction_hex(void) const { return (this->instructionHex); }
Instruction	IFID::get_instruction(void) { return (this->instruction); }

// IFID setter
bool	IFID::set_pc(ui pc) { this->pc = pc; return (true); }
bool	IFID::set_instruction_hex(ui instructionHex) { this->instructionHex = instructionHex; return (true); }
bool	IFID::set_instruction(const Instruction &instruction) { this->instruction = instruction; return (true); }


// IDEX pipeline
IDEX::IDEX(void) { this->aluOp = 0; this->aluSrc = 0; this->regDst = 0; this->memRead = false; this->memWrite = false; this->regWrite = false; this->memToReg = 0; this->readData1 = 0; this->readData2 = 0; this->extendImm = 0; this->rs = 0; this->rt = 0; this->rd = 0; this->instruction = Instruction(); }
IDEX::~IDEX(void) {}

// IDEX getter
ui			IDEX::get_alu_op(void) const { return (this->aluOp); }
ui			IDEX::get_alu_src(void) const { return (this->aluSrc); }
ui			IDEX::get_reg_dst(void) const { return (this->regDst); }
bool		IDEX::get_mem_write(void) const { return (this->memWrite); }
bool		IDEX::get_mem_read(void) const { return (this->memRead); }
bool		IDEX::get_reg_write(void) const { return (this->regWrite); }
ui			IDEX::get_mem_to_reg(void) const { return (this->memToReg); }
ui			IDEX::get_read_data1(void) const { return (this->readData1); }
ui			IDEX::get_read_data2(void) const { return (this->readData2); }
ui			IDEX::get_extend_imm(void) const { return (this->extendImm); }
ui			IDEX::get_rs(void) const { return (this->rs); }
ui			IDEX::get_rt(void) const { return (this->rt); }
ui			IDEX::get_rd(void) const { return (this->rd); }
Instruction	IDEX::get_instruction(void) { return (this->instruction); }

// IDEX setter
bool	IDEX::set_alu_op(ui aluOp) { this->aluOp = aluOp; return (true); }
bool	IDEX::set_alu_src(ui aluSrc) { this->aluSrc = aluSrc; return (true); }
bool	IDEX::set_reg_dst(ui regDst) { this->regDst = regDst; return (true); }
bool	IDEX::set_mem_write(bool memWrite) { this->memWrite = memWrite; return (true); }
bool	IDEX::set_mem_read(bool memRead) { this->memRead = memRead; return (true); }
bool	IDEX::set_reg_write(bool regWrite) { this->regWrite = regWrite; return (true); }
bool	IDEX::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; return (true); }
bool	IDEX::set_read_data_1(ui readData1) { this->readData1 = readData1; return (true); }
bool	IDEX::set_read_data_2(ui readData2) { this->readData2 = readData2; return (true); }
bool	IDEX::set_extend_imm(ui extendImm) { this->extendImm = extendImm; return (true); }
bool	IDEX::set_rs(ui rs) { this->rs = rs; return (true); }
bool	IDEX::set_rt(ui rt) { this->rt = rt; return (true); }
bool	IDEX::set_rd(ui rd) { this->rd = rd; return (true); }
bool	IDEX::set_instruction(const Instruction &instruction) { this->instruction = instruction; return (true); }


// EXMEM pipeline
EXMEM::EXMEM(void) { this->memRead = false; this->memWrite = false; this->regWrite = false; this->memToReg = 0; this->aluResult = 0; this->writeData = 0; this->writeRegister = 0; this->instruction = Instruction(); }
EXMEM::~EXMEM(void) {}

// EXMEM getter
bool		EXMEM::get_mem_read(void) const { return (this->memRead); }
bool		EXMEM::get_mem_write(void) const { return (this->memWrite); }
bool		EXMEM::get_reg_write(void) const { return (this->regWrite); }
ui			EXMEM::get_mem_to_reg(void) const { return (this->memToReg); }
ui			EXMEM::get_alu_result(void) const { return (this->aluResult); }
ui			EXMEM::get_write_data(void) const { return (this->writeData); }
ui			EXMEM::get_write_register(void) const { return (this->writeRegister); }
Instruction	EXMEM::get_instruction(void) const { return (this->instruction); }

// EXMEM setter
bool	EXMEM::set_mem_read(bool memRead) { this->memRead = memRead; return (true); }
bool	EXMEM::set_mem_write(bool memWrite) { this->memWrite = memWrite; return (true); }
bool	EXMEM::set_reg_write(bool regWrite) { this->regWrite = regWrite; return (true); }
bool	EXMEM::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; return (true); }
bool	EXMEM::set_alu_result(ui aluResult) { this->aluResult = aluResult; return (true); }
bool	EXMEM::set_write_data(ui writeData) { this->writeData = writeData; return (true); }
bool	EXMEM::set_write_register(ui writeRegister) { this->writeRegister = writeRegister; return (true); }
bool	EXMEM::set_instruction(const Instruction &instruction) { this->instruction = instruction; return (true); }


// MEMWB pipeline
MEMWB::MEMWB(void) { this->regWrite = false; this->memToReg = 0; this->dataRead = 0; this->aluResult = 0; this->writeRegister = 0; this->instruction = Instruction(); }
MEMWB::~MEMWB(void) {}

// MEMWB getter
bool		MEMWB::get_reg_write(void) const { return (this->regWrite); }
ui			MEMWB::get_mem_to_reg(void) const { return (this->memToReg); }
ui			MEMWB::get_data_read(void) const { return (this->dataRead); }
ui			MEMWB::get_alu_result(void) const { return (this->aluResult); }
ui			MEMWB::get_write_register(void) const { return (this->writeRegister); }
Instruction	MEMWB::get_instruction(void) const { return (this->instruction); }

// MEMWB setter
bool	MEMWB::set_reg_write(bool regWrite) { this->regWrite = regWrite; return (true); }
bool	MEMWB::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; return (true); }
bool	MEMWB::set_data_read(ui dataRead) { this->dataRead = dataRead; return (true); }
bool	MEMWB::set_alu_result(ui aluResult) { this->aluResult = aluResult; return (true); }
bool	MEMWB::set_write_register(ui writeRegister) { this->writeRegister = writeRegister; return (true); }
bool	MEMWB::set_instruction(const Instruction &instruction) { this->instruction = instruction; return (true); }