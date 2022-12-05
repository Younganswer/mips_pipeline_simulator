#ifndef PIPELINE_HPP
# define PIPELINE_HPP

# define ui unsigned int

# include "instruction.hpp"

// declare AluOp enum
typedef enum _ALUOP {
	ALUOP_LW = 0,
	ALUOP_SW,
	ALUOP_BEQ,
	ALUOP_JUMP,
	ALUOP_ADD,
	ALUOP_SUB,
	ALUOP_AND,
	ALUOP_OR,
	ALUOP_SLT,
}	ALUOP;

typedef enum _FUNCTYPE {
	FUNCTYPE_ADD = 0x20,
	FUNCTYPE_SUB = 0x22,
	FUNCTYPE_AND = 0x24,
	FUNCTYPE_OR = 0x25,
	FUNCTYPE_SLT = 0x2a
}	FUNCTYPE;

class IFID {
	private:
		ui			pc;
		ui			id;
		Instruction	instruction;

	public:
		IFID(void);
		~IFID(void);

		// getter
		ui			get_pc(void) const;
		ui			get_id(void) const;

		Instruction	get_instruction(void);
		Instruction	&get_instruction(void) const;

		// setter
		bool	set_pc(ui pc);
		bool	set_id(ui id);
		bool	set_instruction(const Instruction &instruction);
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
		Instruction	instruction;

	public:
		IDEX(void);
		~IDEX(void);

		// getter
		ui	get_alu_op(void) const;
		ui	get_alu_src(void) const;
		ui	get_reg_dst(void) const;
		ui	get_mem_write(void) const;
		ui	get_mem_read(void) const;
		ui	get_branch(void) const;
		ui	get_reg_write(void) const;
		ui	get_mem_to_reg(void) const;
		ui	get_read_data1(void) const;
		ui	get_read_data2(void) const;
		ui	get_extend_imm(void) const;
		ui	get_rs(void) const;
		ui	get_rt(void) const;
		ui	get_rd(void) const;
		Instruction	get_instruction(void);

		// setter
		bool	set_alu_op(ui aluOp);
		bool	set_alu_src(ui aluSrc);
		bool	set_reg_dst(ui regDst);
		bool	set_mem_write(ui memWrite);
		bool	set_mem_read(ui memRead);
		bool	set_branch(ui branch);
		bool	set_reg_write(ui regWrite);
		bool	set_mem_to_reg(ui memToReg);
		bool	set_pc(ui pc);
		bool	set_read_data_1(ui readData1);
		bool	set_read_data_2(ui readData2);
		bool	set_extend_imm(ui extendImm);
		bool	set_rs(ui rs);
		bool	set_rt(ui rt);
		bool	set_rd(ui rd);
		bool	set_instruction(const Instruction &instruction);

		// calculate ALUOP by opcode and funct
		ui	calc_alu_op(ui opcode, ui funct);
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
		Instruction	instruction;

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
		Instruction	get_instruction(void);

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
		void	set_instruction(const Instruction &instruction);
};

class MEMWB {
	private:
		ui	regWrite;
		ui	memToReg;
		ui	readData;
		ui	aluResult;
		Instruction	instruction;

	public:
		MEMWB(void);
		~MEMWB(void);
		
		// getter
		ui	get_reg_write(void);
		ui	get_mem_to_reg(void);
		ui	get_read_data(void);
		ui	get_alu_result(void);
		Instruction	get_instruction(void);

		// setter
		void	set_reg_write(ui regWrite);
		void	set_mem_to_reg(ui memToReg);
		void	set_read_data(ui readData);
		void	set_alu_result(ui aluResult);
		void	set_instruction(const Instruction &instruction);
};

#endif
