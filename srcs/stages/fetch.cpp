#include "pipelines.hpp"
#include "info.hpp"

// fetch IFID pipeline

void	fetch(Info &info) {
	static ui	pcCount = 0;

	info.ifid.set_pc(info.instructions[pcCount].get_pc() + 4);
	info.ifid.set_instruction(info.instructions[pcCount++]);
}


