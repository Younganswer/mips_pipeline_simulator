#ifndef HAZARD_HPP
# define HAZARD_HPP

// Hazard detection unit
class Hazard {
	private:
		bool	_mem_read;
		int		_id_rs;
		int		_id_rt;
		int		_ex_rd;

	public:
		Hazard(void);
		~Hazard(void);

		// Getters
		bool	getMemRead(void);
		int		getIdRs(void);
		int		getIdRt(void);
		int		getExRd(void);
		
		// Setters
		void	setMemRead(bool mem_read);
		void	setIdRs(int id_rs);
		void	setIdRt(int id_rt);
		void	setExRd(int ex_rd);

		// Utils
		bool	pcWrite(void) const;
		bool	instructionFetch(void) const;
};

#endif