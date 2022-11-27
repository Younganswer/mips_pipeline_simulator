#ifndef FORWARD_HPP
#define FORWARD_HPP

class Forward {
	private:
		int		_ex_rs;
		int		_ex_rt;
		int		_mem_rd;
		int		_wb_rd;
		bool	_mem_wb;
		bool	_wb_wb;

	public:
		Forward(void);
		~Forward(void);

		// Getter
		int		getExRs(void) const;
		int		getExRt(void) const;
		int		getMemRd(void) const;
		int		getWbRd(void) const;
		bool	getMemWb(void) const;
		bool	getWbWb(void) const;

		// Setter
		void	setExRs(int ex_rs);
		void	setExRt(int ex_rt);
		void	setMemRd(int mem_rd);
		void	setWbRd(int wb_rd);
		void	setMemWb(bool mem_wb);
		void	setWbWb(bool wb_wb);

		// Utils
		int		forwardA(void) const;
		int		forwardB(void) const;
};

#endif