#include "../../incs/hazard.hpp"
#include "../../incs/stages.hpp"

Hazard::Hazard(void) {
	this->memRead = false;
	this->idRs = 0;
	this->idRt = 0;
	this->exRd = 0;
}

Hazard::~Hazard(void) {}

// Getters
bool	Hazard::get_mem_read(void) { return this->memRead; }
int		Hazard::get_id_rs(void) { return this->idRs; }
int		Hazard::get_id_rt(void) { return this->idRt; }
int		Hazard::get_ex_rd(void) { return this->exRd; }

// Setters
void	Hazard::set_mem_read(bool mem_read) { this->memRead = mem_read; }
void	Hazard::set_id_rs(int id_rs) { this->idRs = id_rs; }
void	Hazard::set_id_rt(int id_rt) { this->idRt = id_rt; }
void	Hazard::set_ex_rd(int ex_rd) { this->exRd = ex_rd; }

// Utils
bool	Hazard::pc_write(void) const { return (((this->memRead && (this->idRs == this->exRd || this->idRt == this->exRd)) == false) || isBranched == false); } // check lw hazard and branch hazard
bool	Hazard::instruction_fetch(void) const { return ((this->memRead && (this->idRs == this->exRd || this->idRt == this->exRd)) == false); }