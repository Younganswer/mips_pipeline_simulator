#ifndef HAZARD_HPP
# define HAZARD_HPP

# define ui unsigned int

// Hazard detection unit
class Hazard {
	private:
		bool	memRead;
		int		idRs;
		int		idRt;
		int		exRt;
		bool	isJumped;
		bool	isBranched;

		bool	lw_data_hazard(void) const;

	public:
		Hazard(void);
		~Hazard(void);

		// Getters
		bool	get_mem_read(void) const;
		int		get_id_rs(void) const;
		int		get_id_rt(void) const;
		int		get_ex_rt(void) const;
		bool	get_is_jumped(void) const;
		bool	get_is_branched(void) const;
		
		// Setters
		bool	set_mem_read(bool memRead);
		bool	set_id_rs(int idRs);
		bool	set_id_rt(int idRt);
		bool	set_ex_rt(int exRt);
		bool	set_is_jumped(bool isJumped);
		bool	set_is_branched(bool isBranched);

		// Utils
		bool	if_flush(void) const; // Jump, Branch hazard: if flush -> true
		bool	pc_write(void) const; // Load-use hazard: pc write -> false
		bool	instruction_fetch(void) const; // Load-use hazard: instruction fetch -> false
		ui		control_mux_select_bit(void) const; // Load-use hazard: control mux select bit -> 1
};

#endif