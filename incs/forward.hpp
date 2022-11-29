#ifndef FORWARD_HPP
#define FORWARD_HPP

class Forward {
	private:
		int		exRs;
		int		exRt;
		int		memRd;
		int		wbRd;
		bool	memWb;
		bool	wbWb;

	public:
		Forward(void);
		~Forward(void);

		// Getter
		int		get_ex_rs(void) const;
		int		get_ex_rt(void) const;
		int		get_mem_rd(void) const;
		int		get_wb_rd(void) const;
		bool	get_mem_wb(void) const;
		bool	get_wb_wb(void) const;

		// Setter
		void	set_ex_rs(int exRs);
		void	set_ex_rt(int exRt);
		void	set_mem_rd(int memRd);
		void	set_wb_rd(int wbRd);
		void	set_mem_wb(bool memWb);
		void	set_wb_wb(bool wbWb);

		// Utils
		int		forward_a(void) const;
		int		forward_b(void) const;
};

#endif