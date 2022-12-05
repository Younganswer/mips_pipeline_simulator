#include "pipelines.hpp"
#include "info.hpp"

// decode info.IDEX pipeline
bool	decode(Info &info) {

	// ui	opcode = info.ifid.get_instruction().get_opcode();
	// ui	funct = info.ifid.get_instruction().get_funct();
	// // decode on R format
	// if (info.ifid.get_instruction().get_format() == R) {
	// 	info.idex.set_alu_op(info.idex.calc_alu_op(opcode, funct));
	// 	info.idex.set_alu_src(info.idex.get_alu_op());
	// 	info.idex.set_reg_dst(info.ifid.get_instruction().get_rt());
	// 	info.idex.set_mem_write(0);
	// 	info.idex.set_mem_read(0);
	// 	info.idex.set_branch(0);
	// 	info.idex.set_reg_write(1);
	// 	info.idex.set_mem_to_reg(0);
	// 	info.idex.set_read_data_1(info.registerValues[info.ifid.get_instruction().get_rs()]);
	// 	info.idex.set_read_data_2(info.registerValues[info.ifid.get_instruction().get_rt()]);
	// 	info.idex.set_extend_imm(0);
	// 	info.idex.set_rs(info.ifid.get_instruction().get_rs());
	// 	info.idex.set_rt(info.ifid.get_instruction().get_rt());
	// 	info.idex.set_rd(info.ifid.get_instruction().get_rd());
	// }
	// // decode on I format
	// else if (info.ifid.get_instruction().get_format() == I) {
	// 	info.idex.set_alu_op(0);
	// 	info.idex.set_alu_src(1);
	// 	info.idex.set_reg_dst(0);
	// 	info.idex.set_mem_write(0);
	// 	info.idex.set_mem_read(0);
	// 	info.idex.set_branch(0);
	// 	info.idex.set_reg_write(1);
	// 	info.idex.set_mem_to_reg(0);
	// 	info.idex.set_read_data_1(info.registerValues[info.ifid.get_instruction().get_rs()]);
	// 	info.idex.set_read_data_2(info.registerValues[info.ifid.get_instruction().get_rt()]);
	// 	info.idex.set_extend_imm(info.ifid.get_instruction().get_imm());
	// 	info.idex.set_rs(info.ifid.get_instruction().get_rs());
	// 	info.idex.set_rt(info.ifid.get_instruction().get_rt());
	// 	info.idex.set_rd(info.ifid.get_instruction().get_rd());
	// }
	// // decode in J format
	// else if (info.ifid.get_instruction().get_format() == J) {
	// 	info.idex.set_alu_op(0);
	// 	info.idex.set_alu_src(0);
	// 	info.idex.set_reg_dst(0);
	// 	info.idex.set_mem_write(0);
	// 	info.idex.set_mem_read(0);
	// 	info.idex.set_branch(0);
	// 	info.idex.set_reg_write(0);
	// 	info.idex.set_mem_to_reg(0);
	// 	info.idex.set_read_data_1(info.ifid.get_instruction().get_rs());
	// 	info.idex.set_read_data_2(info.ifid.get_instruction().get_rt());
	// 	info.idex.set_extend_imm(info.ifid.get_instruction().get_imm());
	// 	info.idex.set_rs(0);
	// 	info.idex.set_rt(0);
	// 	info.idex.set_rd(0);
	// }
	(void) info;
	return (true);
}