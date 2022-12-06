#include "pipelines.hpp"
#include "info.hpp"

// decode info.IDEX pipeline
bool	decode(Info &info) {
	Instruction	instruction = info.ifid.get_instruction();

	info.idex.set_instruction(instruction);
	if (info.ifid.get_instruction().get_format() == R) {
		ui	opcode = info.ifid.get_instruction().get_opcode();
		ui	funct = info.ifid.get_instruction().get_funct();

		info.idex.set_alu_op(info.idex.calc_alu_op(opcode, funct));
		info.idex.set_alu_src(info.idex.get_alu_op());
		info.idex.set_reg_dst(1); // rd field is destination
		info.idex.set_mem_write(0); // write data input
		info.idex.set_mem_read(0); // 
		info.idex.set_branch(0);
		info.idex.set_reg_write(1);
		info.idex.set_mem_to_reg(0); // input comes from data memory -> 1
		info.idex.set_read_data_1(info.registerValues[info.ifid.get_instruction().get_rs()]);
		info.idex.set_read_data_2(info.registerValues[info.ifid.get_instruction().get_rt()]);
		info.idex.set_extend_imm(0);
		info.idex.set_rs(info.ifid.get_instruction().get_rs());
		info.idex.set_rt(info.ifid.get_instruction().get_rt());
		info.idex.set_rd(info.ifid.get_instruction().get_rd());
	}
	// decode on I format
	else if (info.ifid.get_instruction().get_format() == I) {
		info.idex.set_alu_op(0);
		info.idex.set_alu_src(1);
		info.idex.set_reg_dst(0); // rd field is destination		
		if (instruction.get_opcode() == 0x23) { // lw
			info.idex.set_mem_read(1);
			info.idex.set_mem_write(0);
		}
		else if (instruction.get_opcode() == 0x2b) { // sw
			info.idex.set_mem_read(0);
			info.idex.set_mem_write(1);
		}
		else {
			info.idex.set_mem_read(0);
			info.idex.set_mem_write(0);
		}
		// branch
		if (instruction.get_opcode() == 0x4 || instruction.get_opcode() == 0x5) {
			info.idex.set_branch(1);
		}
		else {
			info.idex.set_branch(0);
		}
		// regwrite
		if (instruction.get_opcode() == 0x23 || instruction.get_opcode() == 0x2b) {
			info.idex.set_reg_write(0);
		}
		else {
			info.idex.set_reg_write(1);
		}
		// mem to reg
		if (instruction.get_opcode() == 0x23) {
			info.idex.set_mem_to_reg(1);
		}
		else {
			info.idex.set_mem_to_reg(0);
		}
		info.idex.set_read_data_1(info.registerValues[info.ifid.get_instruction().get_rs()]);
		info.idex.set_read_data_2(info.registerValues[info.ifid.get_instruction().get_rt()]);
		info.idex.set_extend_imm(info.ifid.get_instruction().get_imm());
		info.idex.set_rs(info.ifid.get_instruction().get_rs());
		info.idex.set_rt(info.ifid.get_instruction().get_rt());
		info.idex.set_rd(info.ifid.get_instruction().get_rd());
		info.idex.set_instruction(info.ifid.get_instruction());
	}
	// decode in J format
	else if (info.ifid.get_instruction().get_format() == J) {
		info.idex.set_alu_op(0);
		info.idex.set_alu_src(0);
		info.idex.set_reg_dst(0);
		info.idex.set_mem_write(0);
		info.idex.set_mem_read(0);
		info.idex.set_branch(1);
		info.idex.set_reg_write(0);
		info.idex.set_mem_to_reg(0);
		info.idex.set_read_data_1(info.ifid.get_instruction().get_rs());
		info.idex.set_read_data_2(info.ifid.get_instruction().get_rt());
		info.idex.set_extend_imm(info.ifid.get_instruction().get_imm());
		info.idex.set_rs(0);
		info.idex.set_rt(0);
		info.idex.set_rd(0);
	}
	(void) info;
	return (true);
}