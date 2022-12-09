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
	// check forwarding ------------------------------------------------------------------------------------------
		// set forwarding values in EX/MEM pipeline register -------------------------------------------------------
		info.forward.set_wb_rd(info.memwb.get_instruction().get_rd());
		info.forward.set_wb_rw(info.memwb.get_reg_write());
		info.forward.set_mem_rd(info.exmem.get_instruction().get_rd());
		info.forward.set_ex_rs(info.idex.get_instruction().get_rs());
		info.forward.set_ex_rt(info.idex.get_instruction().get_rt());
		// set forwarding values in EX/MEM pipeline register -------------------------------------------------------

	// TODO: select read data 2 value in mux - is it forwarded or not? -----------------------------------------------------
	ui	aluInputa = 0;
	if (info.forward.forward_a() == 0) {
		aluInputa = info.idex.get_read_data1();
	} else if (info.forward.forward_a() == 1) {
		aluInputa = info.exmem.get_alu_result();
	} else if (info.forward.forward_a() == 2) {
		aluInputa = info.memwb.get_alu_result();
	}
	ui	aluInputb = 0;
	if (info.forward.forward_b() == 0) {
		aluInputb = info.idex.get_read_data2();
	} else if (info.forward.forward_b() == 1) {
		aluInputb = info.exmem.get_alu_result();
	} else if (info.forward.forward_b() == 2) {
		aluInputb = info.memwb.get_alu_result();
	}
	// calculate alu control
	ui	aluControl = calc_alu_control(info.idex.get_alu_op(), info.idex.get_instruction().get_funct());
	// calculate ALU result by ALU control signal ----------------------------------------------------------------
	ui	aluResult = 0;
	if (aluControl == 0b0010) { // ADD
		aluResult = aluInputa + aluInputb;
	} else if (aluControl == 0b0110) { // SUB
		aluResult = aluInputa - aluInputb;
	} else if (aluControl == 0b0000) { // AND
		aluResult = aluInputa & aluInputb;
	} else if (aluControl == 0b0001) { // OR
		aluResult = aluInputa | aluInputb;
	} else if (aluControl == 0b0111) { // SLT
		aluResult = aluInputa < aluInputb;
	}
	(void)aluResult;
	// calculate ALU result by ALU control signal ----------------------------------------------------------------
	// TODO: select rt value in mux - is it forwarded or not? -----------------------------------------------------
	// TODO: select ALU Source value in mux - is it rt value or immediated value? ---------------------------------
	// TODO: Calculate ALU result ---------------------------------------------------------------------------------
	// TODO: select register destination - is it rd or rt? --------------------------------------------------------
	ui	regDst = 0;
	if (info.idex.get_reg_dst() == 0)
		regDst = info.idex.get_rt();
	else if (info.idex.get_reg_dst() == 1)
		regDst = info.idex.get_rd();
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