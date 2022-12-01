#ifndef PIPELINE_HPP
# define PIPELINE_HPP
# include "../../incs/instruction.hpp"


class IFID
{
	private:
		unsigned int	pc;
		Instruction		instruction;

		//getter
		unsigned int	get_pc(void);
};

class IDEX
{
	private:
		unsigned int	wb;
		unsigned int	m;
		unsigned int	ex;
		unsigned int	pc;
		unsigned int	read_data_1;
		unsigned int	read_data_2;
		unsigned int	extend_imm;
		unsigned int	rs;
		unsigned int	rt; // 2번 쓰일 예정.
		unsigned int	rd;

		public:
			IDEX(void);
			~IDEX(void);
			// getter
			unsigned int	get_wb(void);
			unsigned int	get_m(void);
			unsigned int	get_ex(void);
			unsigned int	get_pc(void);
			unsigned int	get_read_data_1(void);
			unsigned int	get_read_data_2(void);
			unsigned int	get_extend_imm(void);
			unsigned int	get_rs(void);
			unsigned int	get_rt(void);
};

class EXMEM
{
	private:
		unsigned int	wb;
		unsigned int	m;
		unsigned int	add_result;
		unsigned int	zero_flag;
		unsigned int	alu_result;
		unsigned int	read_data_2;
		unsigned int	extend_imm;
		unsigned int	write_data;

		//getter
		unsigned int	get_wb(void);
		unsigned int	get_m(void);
		unsigned int	get_add_result(void);
		unsigned int	get_zero_flag(void);
		unsigned int	get_alu_result(void);
		unsigned int	get_read_data_2(void);
		unsigned int	get_extend_imm(void);
		unsigned int	get_write_data(void);
};

class MEMWB
{
	private:
		unsigned int	wb;
		unsigned int	read_data;
		unsigned int	alu_result;

	//getter
	unsigned int	get_wb(void);
	unsigned int	get_read_data(void);
	unsigned int	get_alu_result(void);
};

#endif