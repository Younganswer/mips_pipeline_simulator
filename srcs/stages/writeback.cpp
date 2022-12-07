#include "../../incs/info.hpp"
#include "../../incs/stages.hpp"
#include <iostream>

bool	writeback(Info &info) {
	// write back data -------------------------------------------------------------------------------------------------------------
		ui	src = (info.memwb.get_mem_to_reg() == 0) ? info.memwb.get_data_read() : info.memwb.get_alu_result();
		ui	dst = info.memwb.get_write_register();
		if (info.memwb.get_reg_write() == true) {
			info.registerValues[dst] = src;
		}
	// write back data -------------------------------------------------------------------------------------------------------------
	// forward data ----------------------------------------------------------------------------------------------------------------
	
	(void) info;
	return (true);
}