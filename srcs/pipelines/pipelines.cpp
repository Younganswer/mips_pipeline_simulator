#include "../../incs/pipelines.hpp"
#include <iostream>

IFID::IFID(void) {}
IFID::~IFID(void) {}

// IFID getter
ui	IFID::get_pc(void) { return (this->pc); }

// IDEX getter
ui	IDEX::get_ex(void) { return (this->ex); }
ui	IDEX::get_pc(void) { return (this->pc); }
ui	IDEX::get_read_data_1(void) { return (this->readData1); }
ui	IDEX::get_read_data_2(void) { return (this->readData2); }
ui	IDEX::get_extend_imm(void) { return (this->extendImm); }
ui	IDEX::get_rs(void) { return (this->rs); }
ui	IDEX::get_rt(void) { return (this->rt); }
ui	IDEX::get_rd(void) { return (this->rd); }

// IDEX setter
void	IDEX::set_ex(ui ex) { this->ex = ex; }
void	IDEX::set_pc(ui pc) { this->pc = pc; }
void	IDEX::set_read_data_1(ui readData1) { this->readData1 = readData1; }
void	IDEX::set_read_data_2(ui readData2) { this->readData2 = readData2; }
void	IDEX::set_extend_imm(ui extendImm) { this->extendImm = extendImm; }
void	IDEX::set_rs(ui rs) { this->rs = rs; }
void	IDEX::set_rt(ui rt) { this->rt = rt; }
void	IDEX::set_rd(ui rd) { this->rd = rd; }

// EXMEM getter
ui	EXMEM::get_m(void) { return (this->m); }
ui	EXMEM::get_add_result(void) { return (this->addResult); }
ui	EXMEM::get_zero_flag(void) { return (this->zeroFlag); }
ui	EXMEM::get_alu_result(void) { return (this->aluResult); }
ui	EXMEM::get_read_data_2(void) { return (this->readData2); }
ui	EXMEM::get_extend_imm(void) { return (this->extendImm); }
ui	EXMEM::get_write_data(void) { return (this->writeData); }

// EXMEM setter
void	EXMEM::set_m(ui m) { this->m = m; }
void	EXMEM::set_add_result(ui addResult) { this->addResult = addResult; }
void	EXMEM::set_zero_flag(ui zeroFlag) { this->zeroFlag = zeroFlag; }
void	EXMEM::set_alu_result(ui aluResult) { this->aluResult = aluResult; }
void	EXMEM::set_read_data_2(ui readData2) { this->readData2 = readData2; }
void	EXMEM::set_extend_imm(ui extendImm) { this->extendImm = extendImm; }
void	EXMEM::set_write_data(ui writeData) { this->writeData = writeData; }

// MEMWB getter 
ui	MEMWB::get_wb(void) { return (this->wb); }
ui	MEMWB::get_alu_result(void) { return (this->aluResult); }
ui	MEMWB::get_read_data(void) { return (this->readData); }

// MEMWB setter
void	MEMWB::set_wb(ui wb) { this->wb = wb; }
void	MEMWB::set_alu_result(ui aluResult) { this->aluResult = aluResult; }
void	MEMWB::set_read_data(ui readData) { this->readData = readData; }