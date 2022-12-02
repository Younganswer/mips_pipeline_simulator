#ifndef PIPELINE_HPP
# define PIPELINE_HPP

# define ui unsigned int

# include "instruction.hpp"

class IFID {
	private:
		ui				pc;
		Instruction		instruction;

	public:
		IFID(void);
		~IFID(void);

		// getter
		ui		get_pc(void);

		// setter
		void	set_pc(ui pc);
};

class IDEX {
	private:
		ui	aluOp;
		ui	aluSrc;
		ui	regDst;
		ui	memWrite;
		ui	memRead;
		ui	branch;
		ui	regWrite;
		ui	memToReg;
		ui	readData1;
		ui	readData2;
		ui	extendImm;
		ui	rs;
		ui	rt; // 2번 쓰일 예정.
		ui	rd;

	public:
		IDEX(void);
		~IDEX(void);

		// getter
		ui	get_alu_op(void);
		ui	get_alu_src(void);
		ui	get_reg_dst(void);
		ui	get_mem_write(void);
		ui	get_mem_read(void);
		ui	get_branch(void);
		ui	get_reg_write(void);
		ui	get_mem_to_reg(void);
		ui	get_read_data1(void);
		ui	get_read_data2(void);
		ui	get_extend_imm(void);
		ui	get_rs(void);
		ui	get_rt(void);
		ui	get_rd(void);

		// setter
		void	set_alu_op(ui aluOp);
		void	set_alu_src(ui aluSrc);
		void	set_reg_dst(ui regDst);
		void	set_mem_write(ui memWrite);
		void	set_mem_read(ui memRead);
		void	set_branch(ui branch);
		void	set_reg_write(ui regWrite);
		void	set_mem_to_reg(ui memToReg);
		void	set_pc(ui pc);
		void	set_read_data_1(ui readData1);
		void	set_read_data_2(ui readData2);
		void	set_extend_imm(ui extendImm);
		void	set_rs(ui rs);
		void	set_rt(ui rt);
		void	set_rd(ui rd);
};

class EXMEM {
	private:
		ui	memWrite;
		ui	memRead;
		ui	branch;
		ui	regWrite;
		ui	memToReg;
		ui	addResult;
		ui	zeroFlag;
		ui	aluResult;
		ui	readData2;
		ui	extendImm;
		ui	writeData;

	public:
		EXMEM(void);
		~EXMEM(void);

		// getter
		ui	get_mem_write(void);
		ui	get_mem_read(void);
		ui	get_branch(void);
		ui	get_reg_write(void);
		ui	get_mem_to_reg(void);
		ui	get_add_result(void);
		ui	get_zero_flag(void);
		ui	get_alu_result(void);
		ui	get_read_data_2(void);
		ui	get_extend_imm(void);
		ui	get_write_data(void);

		// setter
		void	set_mem_write(ui memWrite);
		void	set_mem_read(ui memRead);
		void	set_branch(ui branch);
		void	set_reg_write(ui regWrite);
		void	set_mem_to_reg(ui memToReg);
		void	set_add_result(ui addResult);
		void	set_zero_flag(ui zeroFlag);
		void	set_alu_result(ui aluResult);
		void	set_read_data_2(ui readData2);
		void	set_extend_imm(ui extendImm);
		void	set_write_data(ui writeData);
};

class MEMWB {
	private:
		ui	regWrite;
		ui	memToReg;
		ui	readData;
		ui	aluResult;

	public:
		MEMWB(void);
		~MEMWB(void);
		
		// getter
		ui	get_reg_write(void);
		ui	get_mem_to_reg(void);
		ui	get_read_data(void);
		ui	get_alu_result(void);

		// setter
		void	set_reg_write(ui regWrite);
		void	set_mem_to_reg(ui memToReg);
		void	set_read_data(ui readData);
		void	set_alu_result(ui aluResult);
};

#endif
