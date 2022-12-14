#ifndef FORWARD_HPP
#define FORWARD_HPP

#define ui unsigned int

class Forward {
	private:
		ui		idOpcode;
		int		deRs;
		int		deRt;
		
		int		exRs;
		int		exRt;
		
		bool	memRw;
		int		memRd;
		
		bool	wbRw;
		int		wbRd;
		
		ui		dataFromMem;
		ui		dataFromWb;

	public:
		Forward(void);
		~Forward(void);

		// Getter
		ui		get_id_opcode(void) const;
		int		get_de_rs(void) const;
		int		get_de_rt(void) const;

		int		get_ex_rs(void) const;
		int		get_ex_rt(void) const;
		
		bool	get_mem_rw(void) const;
		int		get_mem_rd(void) const;
		
		bool	get_wb_rw(void) const;
		int		get_wb_rd(void) const;
		
		ui		get_data_from_mem(void) const;
		ui		get_data_from_wb(void) const;

		// Setter
		void	set_id_opcode(ui idOpcode);
		void	set_de_rs(int deRs);
		void	set_de_rt(int deRt);
		
		void	set_ex_rs(int exRs);
		void	set_ex_rt(int exRt);

		void	set_mem_rw(bool memRw);
		void	set_mem_rd(int memRd);
		
		void	set_wb_rw(bool wbRw);
		void	set_wb_rd(int wbRd);
		
		void	set_data_from_mem(ui dataFromMem);
		void	set_data_from_wb(ui dataFromWb);

		// Utils
		int		forward_a(void) const;
		int		forward_b(void) const;
		bool	forward_c(void) const;
		bool	forward_d(void) const;
};

#endif