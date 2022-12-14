#include "../../incs/forward.hpp"
#include <iostream>

using namespace std;

Forward::Forward(void) {
	this->idOpcode = 0;
	this->deRs = 0;
	this->deRt = 0;

	this->exRs = 0;
	this->exRt = 0;

	this->memRw = false;
	this->memRd = 0;
	this->dataFromMem = 0;
	
	this->wbRw = false;
	this->wbRd = 0;
	this->dataFromWb = 0;
}

Forward::~Forward(void) {}

// Getter
ui		Forward::get_id_opcode(void) const { return this->idOpcode; }
int		Forward::get_de_rs(void) const { return this->deRs; }
int		Forward::get_de_rt(void) const { return this->deRt; }

int		Forward::get_ex_rs(void) const { return this->exRs; }
int		Forward::get_ex_rt(void) const { return this->exRt; }

bool	Forward::get_mem_rw(void) const { return this->memRw; }
int		Forward::get_mem_rd(void) const { return this->memRd; }

bool	Forward::get_wb_rw(void) const { return this->wbRw; }
int		Forward::get_wb_rd(void) const { return this->wbRd; }

ui		Forward::get_data_from_mem(void) const { return this->dataFromMem; }
ui		Forward::get_data_from_wb(void) const { return this->dataFromWb; }

// Setter
void	Forward::set_id_opcode(ui idOpcode) { this->idOpcode = idOpcode; }
void	Forward::set_de_rs(int deRs) { this->deRs = deRs; }
void	Forward::set_de_rt(int deRt) { this->deRt = deRt; }

void	Forward::set_ex_rs(int exRs) { this->exRs = exRs; }
void	Forward::set_ex_rt(int exRt) { this->exRt = exRt; }

void	Forward::set_mem_rw(bool memRw) { this->memRw = memRw; }
void	Forward::set_mem_rd(int memRd) { this->memRd = memRd; }

void	Forward::set_wb_rw(bool wbRw) { this->wbRw = wbRw; }
void	Forward::set_wb_rd(int wbRd) { this->wbRd = wbRd; }

void	Forward::set_data_from_mem(ui dataFromMem) { this->dataFromMem = dataFromMem; }
void	Forward::set_data_from_wb(ui dataFromWb) { this->dataFromWb = dataFromWb; }

// Utils
int		Forward::forward_a(void) const {
	int	ret = 0b00;
	if ((this->exRs == this->memRd) && this->memRw) { // mem-forward
		ret = 0b10;
	} else if ((this->exRs == this->wbRd) && this->wbRw) { // wb-forward
		ret = 0b01;
	}
	return (ret);
}

int		Forward::forward_b(void) const { // mem-forward
	int	ret = 0b00;
	if ((this->exRt == this->memRd) && this->memRw) { // mem-forward
		ret = 0b10;
	} else if ((this->exRt == this->wbRd) && this->wbRw) { // wb-forward
		ret = 0b01;
	}
	return (ret);
}

bool	Forward::forward_c(void) const {
	return (this->deRs == this->memRd && this->memRw && this->idOpcode == 0x04);
}

bool	Forward::forward_d(void) const {
	return (this->deRt == this->memRd && this->memRw && this->idOpcode == 0x04);
}