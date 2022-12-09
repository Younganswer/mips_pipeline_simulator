#include "../../incs/info.hpp"
#include "../../incs/stages.hpp"
#include <iostream>

bool	writeback(Info &info) {
	// write back data -------------------------------------------------------------------------------------------------------------
		ui	src = (info.memwb.get_mem_to_reg() == true) ? info.memwb.get_data_read() : info.memwb.get_alu_result();
		ui	dst = info.memwb.get_write_register();
		if (info.memwb.get_reg_write() == true) {
			info.registerValues[dst] = src;
		}
	// write back data -------------------------------------------------------------------------------------------------------------
	// forward data ----------------------------------------------------------------------------------------------------------------
	// TODO : 끝났을 때 사이클 수 안늘어나게 처리하기.
	(void) info;
	return (true);
}