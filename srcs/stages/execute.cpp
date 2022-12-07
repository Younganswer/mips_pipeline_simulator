#include "../../incs/stages.hpp"
#include <iostream>
bool	execute(Info &info) {
	cout << "execute" << '\n';
	// set control signal in EX/MEM pipeline register
	info.exmem.set_mem_to_reg(info.idex.get_mem_to_reg());
	info.exmem.set_reg_write(info.idex.get_reg_write());
	info.exmem.set_mem_read(info.idex.get_mem_read());
	



	(void) info;
	return (true);
}