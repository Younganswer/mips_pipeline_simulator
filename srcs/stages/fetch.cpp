#include "pipelines.hpp"
#include "info.hpp"

// fetch IFID pipeline

bool	fetch(Info &info) {
	info.ifid.set_instruction(info.instructions[info.instructionCount]);
	info.ifid.set_pc(info.ifid.get_instruction().get_pc());
	info.ifid.set_id(info.ifid.get_instruction().get_id());
	info.instructionCount++;
	return (true);
}