#include "pipelines.hpp"
#include "info.hpp"

// decode IDEX pipeline
void	decode(IDEX &idex, IFID &ifid, const Info &info) {
	// decode on R format
	if (ifid.get_instruction().get_format() == R) {
		idex.set_alu_op(2);
		idex.set_alu_src(0);
		idex.set_reg_dst(1);
		idex.set_mem_write(0);
		idex.set_mem_read(0);
		idex.set_branch(0);
		idex.set_reg_write(1);
		idex.set_mem_to_reg(0);
		idex.set_read_data_1(info.registerValues[ifid.get_instruction().get_rs()]);
		idex.set_read_data_2(info.registerValues[ifid.get_instruction().get_rt()]);
		idex.set_extend_imm(0);
		idex.set_rs(ifid.get_instruction().get_rs());
		idex.set_rt(ifid.get_instruction().get_rt());
		idex.set_rd(ifid.get_instruction().get_rd());
	}
	// decode on I format
	else if (ifid.get_instruction().get_format() == I) {
		idex.set_alu_op(0);
		idex.set_alu_src(1);
		idex.set_reg_dst(0);
		idex.set_mem_write(0);
		idex.set_mem_read(0);
		idex.set_branch(0);
		idex.set_reg_write(1);
		idex.set_mem_to_reg(0);
		idex.set_read_data_1(info.registerValues[ifid.get_instruction().get_rs()]);
		idex.set_read_data_2(info.registerValues[ifid.get_instruction().get_rt()]);
		idex.set_extend_imm(ifid.get_instruction().get_imm());
		idex.set_rs(ifid.get_instruction().get_rs());
		idex.set_rt(ifid.get_instruction().get_rt());
		idex.set_rd(ifid.get_instruction().get_rd());
	}
	// decode in J format
	else if (ifid.get_instruction().get_format() == J) {
		idex.set_alu_op(0);
		idex.set_alu_src(0);
		idex.set_reg_dst(0);
		idex.set_mem_write(0);
		idex.set_mem_read(0);
		idex.set_branch(0);
		idex.set_reg_write(0);
		idex.set_mem_to_reg(0);
		idex.set_read_data_1(0);
		idex.set_read_data_2(0);
		idex.set_extend_imm(ifid.get_instruction().get_imm());
		idex.set_rs(0);
		idex.set_rt(0);
		idex.set_rd(0);
	}
}