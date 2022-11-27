#include "../../incs/hazard.hpp"

Hazard::Hazard(void) {
	this->_mem_read = false;
	this->_id_rs = 0;
	this->_id_rt = 0;
	this->_ex_rd = 0;
}

Hazard::~Hazard(void) {}

// Getters
bool	Hazard::getMemRead(void) { return this->_mem_read; }
int		Hazard::getIdRs(void) { return this->_id_rs; }
int		Hazard::getIdRt(void) { return this->_id_rt; }
int		Hazard::getExRd(void) { return this->_ex_rd; }

// Setters
void	Hazard::setMemRead(bool mem_read) { this->_mem_read = mem_read; }
void	Hazard::setIdRs(int id_rs) { this->_id_rs = id_rs; }
void	Hazard::setIdRt(int id_rt) { this->_id_rt = id_rt; }
void	Hazard::setExRd(int ex_rd) { this->_ex_rd = ex_rd; }

// Utils
bool	Hazard::pcWrite(void) const { return ((this->_mem_read && (this->_id_rs == this->_ex_rd || this->_id_rt == this->_ex_rd)) == false); }
bool	Hazard::instructionFetch(void) const { return ((this->_mem_read && (this->_id_rs == this->_ex_rd || this->_id_rt == this->_ex_rd)) == false); }