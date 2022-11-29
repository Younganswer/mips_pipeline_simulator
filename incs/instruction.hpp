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
		int		get_id(void);
		int		get_pc(void);
		int		get_rs(void);
		int		get_rt(void);
		int		get_rd(void);
		int		get_imm(void);
		int		get_shamt(void);
		int		get_funct(void);
		int		get_opcode(void);
		int		get_result(void);
		Format	get_format(void);
		Status	get_status(void);
		string	get_asm_string(void);
};

#endif