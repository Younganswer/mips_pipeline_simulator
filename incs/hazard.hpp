#ifndef HAZARD_HPP
# define HAZARD_HPP

# define ui unsigned int

// Hazard detection unit
class Hazard {
	private:
		int		idOpcode;
		int		idRs;
		int		idRt;
		
		int		exFormat; // to check destination register
		bool	exMemRead; // to check lw data hazard
		bool	exRegWrite; // to check source register is written
		int		exRd; // source of destination register
		int		exRt; // source of destination register
		
		int		memMemRead; // to check lw data hazard
		bool	memRegWrite; // to check source register is written
		int		memWriteRegister; // source of destination register

		bool	isJumped;
		bool	isBranched;

		bool	lw_data_hazard(void) const;

	public:
		Hazard(void);
		~Hazard(void);

		// Getters
		int		get_id_opcode(void) const;
		int		get_id_rs(void) const;
		int		get_id_rt(void) const;

		int		get_ex_format(void) const;
		bool	get_ex_mem_read(void) const;
		bool	get_ex_reg_write(void) const;
		int		get_ex_rd(void) const;
		int		get_ex_rt(void) const;

		int		get_mem_mem_read(void) const;
		bool	get_mem_reg_write(void) const;
		int		get_mem_rt(void) const;

		bool	get_is_jumped(void) const;
		bool	get_is_branched(void) const;
		
		// Setters
		bool	set_id_opcode(int idOpcode);
		bool	set_id_rs(int idRs);
		bool	set_id_rt(int idRt);

		bool	set_ex_format(int exFormat);
		bool	set_ex_mem_read(bool exMemRead);
		bool	set_ex_reg_write(bool exRegWrite);
		bool	set_ex_rd(int exRd);
		bool	set_ex_rt(int exRt);

		bool	set_mem_mem_read(int memMemRead);
		bool	set_mem_reg_write(bool memRegWrite);
		bool	set_mem_rt(int memRt);

		bool	set_is_jumped(bool isJumped);
		bool	set_is_branched(bool isBranched);

		// Utils
		bool	if_flush(void) const; // Jump, Branch hazard: if flush -> true
		bool	pc_write(void) const; // Load-use hazard: pc write -> false
		bool	instruction_fetch(void) const; // Load-use hazard: instruction fetch -> false
		ui		control_mux_select_bit(void) const; // Load-use hazard: control mux select bit -> 1
		bool	branch_stall(void) const;
};

#endif