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
		unsigned int	_pc;
		unsigned int	_id;
		int				_rs;
		int				_rt;
		int				_rd;
		int				_imm;
		int				_shamt;
		int				_funct;
		int				_opcode;
		int				_result;
		Format			_format;
		Status			_status;
		string			_asm;

	public:
		Instruction(void);
		Instruction(const string &_asm);
		~Instruction(void);

		// Getters
		int		getId(void);
		int		getPc(void);
		int		getRs(void);
		int		getRt(void);
		int		getRd(void);
		int		getImm(void);
		int		getShamt(void);
		int		getFunct(void);
		int		getOpcode(void);
		int		getResult(void);
		Format	getFormat(void);
		Status	getStatus(void);
		string	getAsm(void);
};

#endif