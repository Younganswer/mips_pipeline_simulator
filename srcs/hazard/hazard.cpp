#include "../../incs/hazard.hpp"
#include "../../incs/stages.hpp"
#include <iostream>

Hazard::Hazard(void) {
	this->idOpcode = 0;
	this->idRs = 0;
	this->idRt = 0;
	
	this->exFormat = R;
	this->exMemRead = false;
	this->exRegWrite = false;
	this->exRd = 0;
	this->exRt = 0;
	
	this->memMemRead = 0;
	this->memRegWrite = false;
	this->memWriteRegister = 0;
	this->isJumped = false;
	this->isBranched = false;
}

Hazard::~Hazard(void) {}

bool	Hazard::lw_data_hazard(void) const {
	return (this->exMemRead && (this->idRs == this->exRt || this->idRt == this->exRt));
}

bool	Hazard::branch_stall(void) const {
	if (this->idOpcode != 0x04) { // not branch
		return (false);
	}

	bool	exRet=false, memRet=false;
	
	// execute check ----------------------------
	if ((this->exFormat == R && this->exRegWrite == true && (this->idRs == this->exRd || this->idRt == this->exRd)) || 
		(this->exFormat == I && this->exRegWrite == true && (this->idRs == this->exRt || this->idRt == this->exRt))) {
		exRet = true;
	}
	// execute check ----------------------------

	// memory check ----------------------------
	if (this->memMemRead == true && this->memRegWrite == true && (this->idRs == this->memWriteRegister || this->idRt == this->memWriteRegister)) {
		memRet = true;
	}
	// memory check ----------------------------
	
	return (exRet || memRet);
}

// Getters
int		Hazard::get_id_opcode(void) const { return this->idOpcode; }
int		Hazard::get_id_rs(void) const { return this->idRs; }
int		Hazard::get_id_rt(void) const { return this->idRt; }

int		Hazard::get_ex_format(void) const { return this->exFormat; }
bool	Hazard::get_ex_mem_read(void) const { return this->exMemRead; }
bool	Hazard::get_ex_reg_write(void) const { return this->exRegWrite; }
int		Hazard::get_ex_rd(void) const { return this->exRd; }
int		Hazard::get_ex_rt(void) const { return this->exRt; }

int		Hazard::get_mem_mem_read(void) const { return this->memMemRead; }
bool	Hazard::get_mem_reg_write(void) const { return this->memRegWrite; }
int		Hazard::get_mem_rt(void) const { return this->memWriteRegister; }
bool	Hazard::get_is_jumped(void) const { return this->isJumped; }
bool	Hazard::get_is_branched(void) const { return this->isBranched; }

// Setters
bool	Hazard::set_id_opcode(int id_opcode) { this->idOpcode = id_opcode; return (true); }
bool	Hazard::set_id_rs(int id_rs) { this->idRs = id_rs; return (true); }
bool	Hazard::set_id_rt(int id_rt) { this->idRt = id_rt; return (true); }

bool	Hazard::set_ex_format(int ex_format) { this->exFormat = ex_format; return (true); }
bool	Hazard::set_ex_mem_read(bool mem_read) { this->exMemRead = mem_read; return (true); }
bool	Hazard::set_ex_reg_write(bool ex_reg_write) { this->exRegWrite = ex_reg_write; return (true); }
bool	Hazard::set_ex_rd(int ex_rd) { this->exRd = ex_rd; return (true); }
bool	Hazard::set_ex_rt(int ex_rt) { this->exRt = ex_rt; return (true); }

bool	Hazard::set_mem_mem_read(int mem_opcode) { this->memMemRead = mem_opcode; return (true); }
bool	Hazard::set_mem_reg_write(bool mem_reg_write) { this->memRegWrite = mem_reg_write; return (true); }
bool	Hazard::set_mem_rt(int mem_rt) { this->memWriteRegister = mem_rt; return (true); }
bool	Hazard::set_is_jumped(bool is_jumped) { this->isJumped = is_jumped; return (true); }
bool	Hazard::set_is_branched(bool is_branched) { this->isBranched = is_branched; return (true); }

// Utils
bool	Hazard::if_flush(void) const { return (isJumped == true || isBranched == true); } // check jump and branch hazard
bool	Hazard::pc_write(void) const { return ((lw_data_hazard() == false) && (branch_stall() == false)); } // check lw hazard
bool	Hazard::instruction_fetch(void) const { return ((lw_data_hazard() == false) && (branch_stall() == false)); } // check lw hazard
ui		Hazard::control_mux_select_bit(void) const { return (((lw_data_hazard() == true) || (branch_stall() == true)) ? 1 : 0); } // check lw hazard