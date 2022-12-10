#include "../../incs/hazard.hpp"
#include "../../incs/stages.hpp"
#include <iostream>

Hazard::Hazard(void) {
	this->memRead = false;
	this->idRs = 0;
	this->idRt = 0;
	this->exRt = 0;
	this->isJumped = false;
	this->isBranched = false;
}

Hazard::~Hazard(void) {}

bool	Hazard::lw_data_hazard(void) const {
	bool	ret = this->memRead && (this->idRs == this->exRt || this->idRt == this->exRt);
	cout << "memRead: " << this->memRead << ", idRs: " << this->idRs << ", idRt: " << this->idRt << ", exRt: " << this->exRt << '\n';
	cout << "LW data hazard: " << ((ret) ? "True" : "False") << '\n';
	return (ret);
}

// Getters
bool	Hazard::get_mem_read(void) const { return this->memRead; }
int		Hazard::get_id_rs(void) const { return this->idRs; }
int		Hazard::get_id_rt(void) const { return this->idRt; }
int		Hazard::get_ex_rt(void) const { return this->exRt; }
bool	Hazard::get_is_jumped(void) const { return this->isJumped; }
bool	Hazard::get_is_branched(void) const { return this->isBranched; }

// Setters
bool	Hazard::set_mem_read(bool mem_read) { this->memRead = mem_read; return (true); }
bool	Hazard::set_id_rs(int id_rs) { this->idRs = id_rs; return (true); }
bool	Hazard::set_id_rt(int id_rt) { this->idRt = id_rt; return (true); }
bool	Hazard::set_ex_rt(int ex_rt) { this->exRt = ex_rt; return (true); }
bool	Hazard::set_is_jumped(bool is_jumped) { this->isJumped = is_jumped; return (true); }
bool	Hazard::set_is_branched(bool is_branched) { this->isBranched = is_branched; return (true); }

// Utils
bool	Hazard::if_flush(void) const { return (isJumped == true || isBranched == true); } // check jump and branch hazard
bool	Hazard::pc_write(void) const { return (lw_data_hazard() == false); } // check lw hazard
bool	Hazard::instruction_fetch(void) const { return (lw_data_hazard() == false); } // check lw hazard
ui		Hazard::control_mux_select_bit(void) const { return ((lw_data_hazard() == true) ? 1 : 0); } // check lw hazard