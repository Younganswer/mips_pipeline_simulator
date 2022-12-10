#include "../../incs/forward.hpp"
#include <iostream>

using namespace std;

Forward::Forward(void) {
	this->exRs = 0;
	this->exRt = 0;
	this->memRd = 0;
	this->wbRd = 0;
	this->deRs = 0;
	this->deRt = 0;
	this->memRw = false;
	this->wbRw = false;
}

Forward::~Forward(void) {}

// Getter
int		Forward::get_ex_rs(void) const { return this->exRs; }
int		Forward::get_ex_rt(void) const { return this->exRt; }
int		Forward::get_mem_rd(void) const { return this->memRd; }
int		Forward::get_wb_rd(void) const { return this->wbRd; }
ui		Forward::get_id_opcode(void) const { return this->idOpcode; }
int		Forward::get_de_rs(void) const { return this->deRs; }
int		Forward::get_de_rt(void) const { return this->deRt; }
bool	Forward::get_mem_rw(void) const { return this->memRw; }
bool	Forward::get_wb_rw(void) const { return this->wbRw; }

// Setter
void	Forward::set_ex_rs(int exRs) { this->exRs = exRs; }
void	Forward::set_ex_rt(int exRt) { this->exRt = exRt; }
void	Forward::set_mem_rd(int memRd) { this->memRd = memRd; }
void	Forward::set_wb_rd(int wbRd) { this->wbRd = wbRd; }
void	Forward::set_de_rs(int deRs) { this->deRs = deRs; }
void	Forward::set_de_rt(int deRt) { this->deRt = deRt; }
void	Forward::set_id_opcode(ui idOpcode) { this->idOpcode = idOpcode; }
void	Forward::set_mem_rw(bool memRw) { this->memRw = memRw; }
void	Forward::set_wb_rw(bool wbRw) { this->wbRw = wbRw; }

// Utils

int		Forward::forward_a(void) const {
	if (this->exRs == this->memRd && this->memRw) {
		return (0b10);
	} else if (this->exRs == this->wbRd && this->wbRw) {
		return (0b01);
	}
	return (0b00);
}

int		Forward::forward_b(void) const {
	cout << "exRt: " << this->exRt << ", memRd: " << this->memRd << ", memRw: " << this->memRw << ", wbRd: " << this->wbRd << ", wbRw: " << this->wbRw << endl;
	if (this->exRt == this->memRd && this->memRw) {
		return (0b10);
	} else if (this->exRt == this->wbRd && this->wbRw) {
		return (0b01);
	}
	return (0b00);
}

bool	Forward::forward_c(void) const {
	if (this->deRs == this->memRd && this->memRw && this->idOpcode == 0x04) {
		return (true);
	} else
		return (false);
}

bool	Forward::forward_d(void) const {
	cout << "deRt: " << this->deRt << ", memRd: " << this->memRd << ", memRw: " << this->memRw << ", wbRd: " << this->wbRd << ", wbRw: " << this->wbRw << "\n";
	if (this->deRt == this->memRd && this->memRw && this->idOpcode == 0x04) {
		return (true);
	} else
		return (false);
}