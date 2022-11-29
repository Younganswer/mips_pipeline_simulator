#include "../../incs/forward.hpp"

Forward::Forward(void) {
	this->exRs = 0;
	this->exRt = 0;
	this->memRd = 0;
	this->wbRd = 0;
	this->memWb = false;
	this->wbWb = false;
}

Forward::~Forward(void) {}

// Getter
int		Forward::get_ex_rs(void) const { return this->exRs; }
int		Forward::get_ex_rt(void) const { return this->exRt; }
int		Forward::get_mem_rd(void) const { return this->memRd; }
int		Forward::get_wb_rd(void) const { return this->wbRd; }
bool	Forward::get_mem_wb(void) const { return this->memWb; }
bool	Forward::get_wb_wb(void) const { return this->wbWb; }

// Setter
void	Forward::set_ex_rs(int exRs) { this->exRs = exRs; }
void	Forward::set_ex_rt(int exRt) { this->exRt = exRt; }
void	Forward::set_mem_rd(int memRd) { this->memRd = memRd; }
void	Forward::set_wb_rd(int wbRd) { this->wbRd = wbRd; }
void	Forward::set_mem_wb(bool memWb) { this->memWb = memWb; }
void	Forward::set_wb_wb(bool wbWb) { this->wbWb = wbWb; }

// Utils
int		Forward::forward_a(void) const {
	if (this->exRs == this->wbRd && this->wbWb) {
		return (2);
	} else if (this->exRs == this->memRd && this->memWb) {
		return (1);
	}
	return (0);
}

int		Forward::forward_b(void) const {
	if (this->exRt == this->wbRd && this->wbWb) {
		return (2);
	} else if (this->exRt == this->memRd && this->memWb) {
		return (1);
	}
	return (0);
}