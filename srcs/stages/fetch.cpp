#include "pipelines.hpp"
#include "info.hpp"

// fetch IFID pipeline

void	fetch(IFID &ifid, const Info &info) {
	static ui	pcCount = 0;

	ifid.set_pc(info.instructions[pcCount].get_pc() + 4);
	ifid.set_instruction(info.instructions[pcCount++]);
}


