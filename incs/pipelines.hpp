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
		ui			aluOp;
		ui			aluSrc;
		ui			regDst;
		bool		memRead;
		bool		memWrite;
		bool		memToReg;
		bool		regWrite;
		ui			readData1;
		ui			readData2;
		ui			extendImm;
		ui			rs;
		ui			rt; // 2번 쓰일 예정.
		ui			rd;
		Instruction	instruction;

	public:
		IDEX(void);
		~IDEX(void);

		// getter
		ui			get_alu_op(void) const;
		ui			get_alu_src(void) const;
		ui			get_reg_dst(void) const;
		bool		get_mem_read(void) const;
		bool		get_mem_write(void) const;
		bool		get_mem_to_reg(void) const;
		bool		get_reg_write(void) const;
		ui			get_read_data1(void) const;
		ui			get_read_data2(void) const;
		ui			get_extend_imm(void) const;
		ui			get_rs(void) const;
		ui			get_rt(void) const;
		ui			get_rd(void) const;
		Instruction	get_instruction(void);

		// setter
		bool	set_alu_op(ui aluOp);
		bool	set_alu_src(ui aluSrc);
		bool	set_reg_dst(ui regDst);
		bool	set_mem_write(bool memWrite);
		bool	set_mem_read(bool memRead);
		bool	set_reg_write(bool regWrite);
		bool	set_mem_to_reg(bool memToReg);
		bool	set_pc(ui pc);
		bool	set_read_data_1(ui readData1);
		bool	set_read_data_2(ui readData2);
		bool	set_extend_imm(ui extendImm);
		bool	set_rs(ui rs);
		bool	set_rt(ui rt);
		bool	set_rd(ui rd);
		bool	set_instruction(const Instruction &instruction);
};

class EXMEM {
	private:
		bool		memRead;
		bool		memWrite;
		bool		memToReg;
		bool		regWrite;
		ui			addResult;
		ui			zeroFlag;
		ui			aluResult;
		ui			readData2;
		ui			extendImm;
		ui			writeData;
		Instruction	instruction;

	public:
		EXMEM(void);
		~EXMEM(void);

		// getter
		bool		get_mem_read(void) const;
		bool		get_mem_write(void) const;
		bool		get_mem_to_reg(void) const;
		bool		get_reg_write(void) const;
		ui			get_add_result(void) const;
		ui			get_zero_flag(void) const;
		ui			get_alu_result(void) const;
		ui			get_read_data_2(void) const;
		ui			get_extend_imm(void) const;
		ui			get_write_data(void) const;
		Instruction	get_instruction(void) const;

		// setter
		bool	set_mem_read(bool memRead);
		bool	set_mem_write(bool memWrite);
		bool	set_mem_to_reg(bool memToReg);
		bool	set_reg_write(bool regWrite);
		bool	set_add_result(ui addResult);
		bool	set_zero_flag(ui zeroFlag);
		bool	set_alu_result(ui aluResult);
		bool	set_read_data_2(ui readData2);
		bool	set_extend_imm(ui extendImm);
		bool	set_write_data(ui writeData);
		bool	set_instruction(const Instruction &instruction);
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
