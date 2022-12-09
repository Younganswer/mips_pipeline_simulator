#include "../../incs/stages.hpp"
#include <iostream>

ui	calc_alu_control(ui aluOp, ui funct);

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

ui	calc_alu_control(ui alu_op, ui funct) {
	ui	ret = -1;

	if (alu_op == 0) { // lw, sw
		ret = 0b0010; // ADD
	} else if (alu_op == 1) { // BEQ
		ret = 0b0110; // SUB
	} else if (alu_op == 2) { // R-format
		if (funct == 0x20) { // ADD
			ret = 0b0010;
		} else if (funct == 0x22) { // SUB
			ret = 0b0110;
		} else if (funct == 0x24) { // AND
			ret = 0b0000;
		} else if (funct == 0x25) { // OR
			ret = 0b0001;
		} else if (funct == 0x2a) { // SLT
			ret = 0b0111;
		}
	}
	return (ret);
}