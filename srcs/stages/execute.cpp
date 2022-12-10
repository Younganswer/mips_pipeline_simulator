#include "../../incs/stages.hpp"
#include <iostream>

ui	calc_alu_control(ui aluOp, ui funct);

bool	execute(Info &info) {
	Instruction	instruction = info.idex.get_instruction();
	instruction.set_status(EX);
	info.exmem.set_instruction(instruction);

	// set control signal in EX/MEM pipeline register -------------------------------------------------------------
		info.exmem.set_mem_read(info.idex.get_mem_read());
		info.exmem.set_mem_write(info.idex.get_mem_write());
		info.exmem.set_mem_to_reg(info.idex.get_mem_to_reg());
		info.exmem.set_reg_write(info.idex.get_reg_write());
	// set control signal in EX/MEM pipeline register -------------------------------------------------------------

	// set forwarding unit ------------------------------------------------------------------------------------------
		info.forward.set_ex_rs(info.idex.get_rs());
		info.forward.set_ex_rt(info.idex.get_rt());
	// set forwarding unit ------------------------------------------------------------------------------------------

	// select read data value from mux ------------------------------------------------------------------------
		ui	readData1 = 0;
		if (info.forward.forward_a() == 0b00) {
			readData1 = info.idex.get_read_data1();
		} else if (info.forward.forward_a() == 0b10) {
			readData1 = info.exmem.get_alu_result();
		} else if (info.forward.forward_a() == 0b01) {
			readData1 = info.memwb.get_alu_result();
		}
		ui	readData2 = 0;
		if (info.forward.forward_b() == 0b00) {
			readData2 = info.idex.get_read_data2();
		} else if (info.forward.forward_b() == 0b10) {
			readData2 = info.exmem.get_alu_result();
		} else if (info.forward.forward_b() == 0b01) {
			readData2 = info.memwb.get_alu_result();
		}
	// select read data value from mux ------------------------------------------------------------------------

	// set ALU src -------------------------------------------------------------------------------------------
		ui	aluInputA = readData1;
		ui	aluInputB = (info.idex.get_alu_src()) ? info.idex.get_extend_imm() : readData2;
	// set ALU src -------------------------------------------------------------------------------------------

	// get alu control -------------------------------------------------------------------------------------------
		ui	aluControl = calc_alu_control(info.idex.get_alu_op(), info.idex.get_instruction().get_funct());
	// get alu control -------------------------------------------------------------------------------------------

	// calculate ALU result by ALU control signal ----------------------------------------------------------------
		ui	aluResult = 0;
		if (aluControl == 0b0010) { // ADD
			aluResult = aluInputA + aluInputB;
		} else if (aluControl == 0b0110) { // SUB
			aluResult = aluInputA - aluInputB;
		} else if (aluControl == 0b0000) { // AND
			aluResult = aluInputA & aluInputB;
		} else if (aluControl == 0b0001) { // OR
			aluResult = aluInputA | aluInputB;
		} else if (aluControl == 0b0111) { // SLT
			aluResult = aluInputA < aluInputB;
		}
	// calculate ALU result by ALU control signal ----------------------------------------------------------------

	// set register destination -----------------------------------------------------------------------------------
		ui	regDst = 0;
		if (info.idex.get_reg_dst() == 0) {
			regDst = info.idex.get_rt();
		} else if (info.idex.get_reg_dst() == 1) {
			regDst = info.idex.get_rd();
		}
	// set register destination -----------------------------------------------------------------------------------

	// set EX/MEM pipeline register values ------------------------------------------------------------------
		info.exmem.set_alu_result(aluResult);
		info.exmem.set_write_data(readData2);
		info.exmem.set_write_register(regDst);
	// set EX/MEM pipeline register values ------------------------------------------------------------------

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