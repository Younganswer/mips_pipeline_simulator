#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <string>

using namespace std;

typedef enum _Format {
	R = 0,
	I = 1,
	J = 2,
}	Format;

typedef enum _Status {
	IF	= 0,
	ID	= 1,
	EX	= 2,
	MEM	= 3,
	WB	= 4
}	Status;

typedef enum _R_FUNCT {
	AND = 0x24,
	OR = 0x25,
	ADD = 0x20,
	SUB = 0x22,
	SLT = 0x2a,
}	R_FUNCT;

class Instruction {
	private:
		unsigned int	pc;
		unsigned int	id;
		int				rs;
		int				rt;
		int				rd;
		int				imm;
		int				shamt;
		int				funct;
		int				opcode;
		int				result;
		Format			format;
		Status			status;
		string			asmString;

	public:
		Instruction(void);
		Instruction(const string &asmString);
		~Instruction(void);

		// Getters
		int		get_id(void) const;
		int		get_pc(void) const;
		int		get_rs(void) const;
		int		get_rt(void) const;
		int		get_rd(void) const;
		int		get_imm(void) const;
		int		get_shamt(void) const;
		int		get_funct(void) const;
		int		get_opcode(void) const;
		int		get_result(void) const;
		Format	get_format(void) const;
		Status	get_status(void) const;
		string	get_asm_string(void) const;
};

#endif