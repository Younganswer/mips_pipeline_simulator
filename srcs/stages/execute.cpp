#include "../../incs/stages.hpp"
#include <iostream>
bool	execute(Info &info) {
	// set control signal in EX/MEM pipeline register -------------------------------------------------------------
		info.exmem.set_mem_read(info.idex.get_mem_read());
		info.exmem.set_mem_write(info.idex.get_mem_write());
		info.exmem.set_mem_to_reg(info.idex.get_mem_to_reg());
		info.exmem.set_reg_write(info.idex.get_reg_write());
	// set control signal in EX/MEM pipeline register -------------------------------------------------------------

	// TODO: select rs value in mux - is it forwarded or not? -----------------------------------------------------
	// TODO: select rt value in mux - is it forwarded or not? -----------------------------------------------------
	// TODO: select ALU Source value in mux - is it rt value or immediated value? ---------------------------------
	// TODO: Calculate ALU result ---------------------------------------------------------------------------------
	// TODO: select register destination - is it rd or rt? --------------------------------------------------------
	// TODO: set EX/MEM pipeline register values ------------------------------------------------------------------
	(void) info;
	return (true);
}