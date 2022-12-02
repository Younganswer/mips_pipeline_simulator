#include "../../incs/pipeline.hpp"
#include <iostream>

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

// EXMEM getter
ui	EXMEM::get_m(void) { return (this->m); }
ui	EXMEM::get_add_result(void) { return (this->addResult); }
ui	EXMEM::get_zero_flag(void) { return (this->zeroFlag); }
ui	EXMEM::get_alu_result(void) { return (this->aluResult); }
ui	EXMEM::get_read_data_2(void) { return (this->readData2); }
ui	EXMEM::get_extend_imm(void) { return (this->extendImm); }
ui	EXMEM::get_write_data(void) { return (this->writeData); }

// MEMWB getter
ui	MEMWB::get_wb(void) { return (this->wb); }
ui	MEMWB::get_alu_result(void) { return (this->aluResult); }
ui	MEMWB::get_read_data(void) { return (this->readData); }
