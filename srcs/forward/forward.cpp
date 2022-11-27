#include "../../incs/forward.hpp"

Forward::Forward(void) {
	this->_ex_rs = 0;
	this->_ex_rt = 0;
	this->_mem_rd = 0;
	this->_wb_rd = 0;
	this->_mem_wb = false;
	this->_wb_wb = false;
}

Forward::~Forward(void) {}

// Getter
int		Forward::getExRs(void) const { return this->_ex_rs; }
int		Forward::getExRt(void) const { return this->_ex_rt; }
int		Forward::getMemRd(void) const { return this->_mem_rd; }
int		Forward::getWbRd(void) const { return this->_wb_rd; }
bool	Forward::getMemWb(void) const { return this->_mem_wb; }
bool	Forward::getWbWb(void) const { return this->_wb_wb; }

// Setter
void	Forward::setExRs(int ex_rs) { this->_ex_rs = ex_rs; }
void	Forward::setExRt(int ex_rt) { this->_ex_rt = ex_rt; }
void	Forward::setMemRd(int mem_rd) { this->_mem_rd = mem_rd; }
void	Forward::setWbRd(int wb_rd) { this->_wb_rd = wb_rd; }
void	Forward::setMemWb(bool mem_wb) { this->_mem_wb = mem_wb; }
void	Forward::setWbWb(bool wb_wb) { this->_wb_wb = wb_wb; }

// Utils
int		Forward::forwardA(void) const {
	if (this->_ex_rs == this->_wb_rd && this->_wb_wb) {
		return (2);
	} else if (this->_ex_rs == this->_mem_rd && this->_mem_wb) {
		return (1);
	}
	return (0);
}

int		Forward::forwardB(void) const {
	if (this->_ex_rt == this->_wb_rd && this->_wb_wb) {
		return (2);
	} else if (this->_ex_rt == this->_mem_rd && this->_mem_wb) {
		return (1);
	}
	return (0);
}