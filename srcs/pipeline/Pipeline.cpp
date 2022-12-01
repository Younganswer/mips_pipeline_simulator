#include "../../incs/Pipeline.hpp"
#include <iostream>

//IFID getter
unsigned int	IFID::get_pc(void) { return (this->pc); }

//IDEX getter
unsigned int	IDEX::get_ex(void) { return (this->ex); }
unsigned int	IDEX::get_pc(void) { return (this->pc); }
unsigned int	IDEX::get_read_data_1(void) { return (this->read_data_1); }
unsigned int	IDEX::get_read_data_2(void) { return (this->read_data_2); }
unsigned int	IDEX::get_extend_imm(void) { return (this->extend_imm); }
unsigned int	IDEX::get_rs(void) { return (this->rs); }
unsigned int	IDEX::get_rt(void) { return (this->rt); }
unsigned int	IDEX::get_rd(void) { return (this->rd); }

//EXMEM getter
unsigned int	EXMEM::get_m(void) { return (this->m); }
unsigned int	EXMEM::get_add_result(void) { return (this->add_result); }
unsigned int	EXMEM::get_zero_flag(void) { return (this->zero_flag); }
unsigned int	EXMEM::get_alu_result(void) { return (this->alu_result); }
unsigned int	EXMEM::get_read_data_2(void) { return (this->read_data_2); }
unsigned int	EXMEM::get_extend_imm(void) { return (this->extend_imm); }
unsigned int	EXMEM::get_write_data(void) { return (this->write_data); }

//MEMWB getter
unsigned int	MEMWB::get_wb(void) { return (this->wb); }
unsigned int	MEMWB::get_alu_result(void) { return (this->alu_result); }
unsigned int	MEMWB::get_read_data(void) { return (this->read_data); }
