#include "../../incs/stages.hpp"
#include "../../incs/pipelines.hpp"
#include "../../incs/info.hpp"

ui	extend_sign(ui imm);
ui	calc_alu_op(ui opcode);

bool	decode(Info &info) {
	Instruction	instruction = info.ifid.get_instruction();
	instruction.set_status(ID);
	info.idex.set_instruction(instruction);

	// IF/ID pipe is empty
	if (instruction.get_pc() == 0) {
		// set all values to 0
		info.idex.set_alu_op(0);
		info.idex.set_alu_src(0);
		info.idex.set_reg_dst(0);
		info.idex.set_mem_read(0);
		info.idex.set_mem_write(0);
		info.idex.set_mem_to_reg(0);
		info.idex.set_reg_write(0);
		info.idex.set_read_data_1(0);
		info.idex.set_read_data_2(0);
		info.idex.set_extend_imm(0);
		info.idex.set_rs(0);
		info.idex.set_rt(0);
		info.idex.set_rd(0);
		return (true);
	}

	if (instruction.get_format() == R) {
		// set signal values -------------------------------------------------------------------------------------------
			info.idex.set_alu_op(calc_alu_op(instruction.get_opcode()));
			info.idex.set_alu_src(0); // mux flag 0: ReadData2 is source of alu
			info.idex.set_reg_dst(1); // mux flag 1: rd is destination
			info.idex.set_mem_read(0); // False: R format doesn't use memory
			info.idex.set_mem_write(0); // False: R format doesn't use memory
			info.idex.set_mem_to_reg(0); // False: input comes from ALU result -> 1
			info.idex.set_reg_write(1); // True: rd is destination
		// set signal values -------------------------------------------------------------------------------------------

		// set register values -----------------------------------------------------------------------------------------
			info.idex.set_read_data_1(info.registerValues[instruction.get_rs()]);
			info.idex.set_read_data_2(info.registerValues[instruction.get_rt()]);
			info.idex.set_extend_imm(extend_sign(instruction.get_imm()));
			info.idex.set_rs(instruction.get_rs());
			info.idex.set_rt(instruction.get_rt());
			info.idex.set_rd(instruction.get_rd());
		// set register values -----------------------------------------------------------------------------------------
	} else if (instruction.get_format() == I) {
		// set signal values -------------------------------------------------------------------------------------------
			info.idex.set_alu_op(calc_alu_op(instruction.get_opcode()));
			info.idex.set_alu_src(1); // mux flag 1: imm is source of alu
			info.idex.set_reg_dst(0); // mux flag 0: rt is destination
			if (instruction.get_opcode() == 0x23) { // lw
				info.idex.set_mem_read(1); // True: lw reads memory
				info.idex.set_mem_write(0); // False: lw doesn't write memory
				info.idex.set_mem_to_reg(1); // True: input comes from memory
				info.idex.set_reg_write(1); // True: rt is destination
			} else if (instruction.get_opcode() == 0x2b) { // sw
				info.idex.set_mem_read(0); // False: sw doesn't read memory
				info.idex.set_mem_write(1); // True: sw writes memory
				info.idex.set_mem_to_reg(0); // False: input comes from ALU result
				info.idex.set_reg_write(0); // False: sw doesn't write register
			} else { // TODO: set values in slt, beq
				info.idex.set_mem_read(0);
				info.idex.set_mem_write(0);
				info.idex.set_mem_to_reg(0);
				info.idex.set_reg_write(1);
			}
		// set signal values -------------------------------------------------------------------------------------------

		// set register values -----------------------------------------------------------------------------------------
			info.idex.set_read_data_1(info.registerValues[instruction.get_rs()]);
			info.idex.set_read_data_2(info.registerValues[instruction.get_rt()]);
			info.idex.set_extend_imm(extend_sign(instruction.get_imm()));
			info.idex.set_rs(instruction.get_rs());
			info.idex.set_rt(instruction.get_rt());
			info.idex.set_rd(instruction.get_rd());
		// set register values -----------------------------------------------------------------------------------------
	} else if (info.ifid.get_instruction().get_format() == J) {
		// TODO: handle j format
		// set signal values -------------------------------------------------------------------------------------------
			info.idex.set_alu_op(0);
			info.idex.set_alu_src(0);
			info.idex.set_reg_dst(0);
			info.idex.set_mem_read(0);
			info.idex.set_mem_write(0);
			info.idex.set_mem_to_reg(0);
			info.idex.set_reg_write(0);
		// set signal values -------------------------------------------------------------------------------------------

		// set register values -----------------------------------------------------------------------------------------
			info.idex.set_read_data_1(info.registerValues[instruction.get_rs()]);
			info.idex.set_read_data_2(info.registerValues[instruction.get_rt()]);
			info.idex.set_extend_imm(extend_sign(instruction.get_imm()));
			info.idex.set_rs(instruction.get_rs());
			info.idex.set_rt(instruction.get_rt());
			info.idex.set_rd(instruction.get_rd());
		// set register values -----------------------------------------------------------------------------------------
	}
	isBranched = true;
	(void) info;
	return (true);
}

ui	extend_sign(ui imm) {
	if (imm & 0x8000) {
		imm |= 0xffff0000;
	}
	return (imm);
}

ui	calc_alu_op(ui opcode) {
	ui	ret = -1;

	if (opcode == 0x23 || opcode == 0x2b) {
		ret = 0b00;
	} else if (opcode == 0x04) {
		ret = 0b01;
	} else if (opcode == 0) {
		ret = 0b10;
	}
	return (ret);
}



// TODO: Create control unit and initialize branch signal
// branch in control unit
// if (instruction.get_opcode() == 0x4 || instruction.get_opcode() == 0x5) {
	// info.idex.set_branch(1);
// }
// else {
	// info.idex.set_branch(0);
// }