#ifndef HAZARD_HPP
# define HAZARD_HPP

// Hazard detection unit
class Hazard {
	private:
		bool	memRead;
		int		idRs;
		int		idRt;
		int		exRd;

	public:
		Hazard(void);
		~Hazard(void);

		// Getters
		bool	get_mem_read(void);
		int		get_id_rs(void);
		int		get_id_rt(void);
		int		get_ex_rd(void);
		
		// Setters
		void	set_mem_read(bool memRead);
		void	set_id_rs(int idRs);
		void	set_id_rt(int idRt);
		void	set_ex_rd(int exRd);

		// Utils
		bool	pc_write(void) const;
		bool	instruction_fetch(void) const;
};

#endif