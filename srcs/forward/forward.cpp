#include "../../incs/forward.hpp"

Forward::Forward(void) {
	this->exRs = 0;
	this->exRt = 0;
	this->memRd = 0;
	this->wbRd = 0;
	this->memRw = false;
	this->wbRw = false;
}

Forward::~Forward(void) {}

// Getter
int		Forward::get_ex_rs(void) const { return this->exRs; }
int		Forward::get_ex_rt(void) const { return this->exRt; }
int		Forward::get_mem_rd(void) const { return this->memRd; }
int		Forward::get_wb_rd(void) const { return this->wbRd; }
bool	Forward::get_mem_rw(void) const { return this->memRw; }
bool	Forward::get_wb_rw(void) const { return this->wbRw; }

// Setter
void	Forward::set_ex_rs(int exRs) { this->exRs = exRs; }
void	Forward::set_ex_rt(int exRt) { this->exRt = exRt; }
void	Forward::set_mem_rd(int memRd) { this->memRd = memRd; }
void	Forward::set_wb_rd(int wbRd) { this->wbRd = wbRd; }
void	Forward::set_mem_rw(bool memRw) { this->memRw = memRw; }
void	Forward::set_wb_rw(bool wbRw) { this->wbRw = wbRw; }

// Utils

int		Forward::forward_a(void) const {
	if (this->exRs == this->wbRd && this->wbRw) {
		return (2);
	} else if (this->exRs == this->memRd && this->memRw) {
		return (1);
	}
	return (0);
}

int		Forward::forward_b(void) const {
	if (this->exRt == this->wbRd && this->wbRw) {
		return (2);
	} else if (this->exRt == this->memRd && this->memRw) {
		return (1);
	}
	return (0);
}