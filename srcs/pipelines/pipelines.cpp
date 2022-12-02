#include "../../incs/pipelines.hpp"
#include <iostream>

IFID::IFID(void) {}
IFID::~IFID(void) {}

// IFID getter
ui	IFID::get_pc(void) { return (this->pc); }

// IFID setter
void	IFID::set_pc(ui pc) { this->pc = pc; }

IDEX::IDEX(void) {}
IDEX::~IDEX(void) {}

// IDEX getter
ui	IDEX::get_alu_op(void) { return (this->aluOp); }
ui	IDEX::get_alu_src(void) { return (this->aluSrc); }
ui	IDEX::get_reg_dst(void) { return (this->regDst); }
ui	IDEX::get_mem_write(void) { return (this->memWrite); }
ui	IDEX::get_mem_read(void) { return (this->memRead); }
ui	IDEX::get_branch(void) { return (this->branch); }
ui	IDEX::get_reg_write(void) { return (this->regWrite); }
ui	IDEX::get_mem_to_reg(void) { return (this->memToReg); }
ui	IDEX::get_read_data1(void) { return (this->readData1); }
ui	IDEX::get_read_data2(void) { return (this->readData2); }
ui	IDEX::get_extend_imm(void) { return (this->extendImm); }
ui	IDEX::get_rs(void) { return (this->rs); }
ui	IDEX::get_rt(void) { return (this->rt); }
ui	IDEX::get_rd(void) { return (this->rd); }

// IDEX setter
void	IDEX::set_alu_op(ui aluOp) { this->aluOp = aluOp; }
void	IDEX::set_alu_src(ui aluSrc) { this->aluSrc = aluSrc; }
void	IDEX::set_reg_dst(ui regDst) { this->regDst = regDst; }
void	IDEX::set_mem_write(ui memWrite) { this->memWrite = memWrite; }
void	IDEX::set_mem_read(ui memRead) { this->memRead = memRead; }
void	IDEX::set_branch(ui branch) { this->branch = branch; }
void	IDEX::set_reg_write(ui regWrite) { this->regWrite = regWrite; }
void	IDEX::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; }
void	IDEX::set_read_data_1(ui readData1) { this->readData1 = readData1; }
void	IDEX::set_read_data_2(ui readData2) { this->readData2 = readData2; }
void	IDEX::set_extend_imm(ui extendImm) { this->extendImm = extendImm; }
void	IDEX::set_rs(ui rs) { this->rs = rs; }
void	IDEX::set_rt(ui rt) { this->rt = rt; }
void	IDEX::set_rd(ui rd) { this->rd = rd; }

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

//MEMWB constructor and destructor
MEMWB::MEMWB(void) {}
MEMWB::~MEMWB(void) {}

// MEMWB getter
ui	MEMWB::get_reg_write(void) { return (this->regWrite); }
ui	MEMWB::get_mem_to_reg(void) { return (this->memToReg); }
ui	MEMWB::get_read_data(void) { return (this->readData); }
ui	MEMWB::get_alu_result(void) { return (this->aluResult); }

// MEMWB setter
void	MEMWB::set_reg_write(ui regWrite) { this->regWrite = regWrite; }
void	MEMWB::set_mem_to_reg(ui memToReg) { this->memToReg = memToReg; }
void	MEMWB::set_read_data(ui readData) { this->readData = readData; }
void	MEMWB::set_alu_result(ui aluResult) { this->aluResult = aluResult; }
