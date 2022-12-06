#include "../../incs/stages.hpp"
#include "../../incs/info.hpp"

bool	fetch(Info &info) {
	if (info.instructionIndex == info.instructions.size()) {
		info.ifid.set_instruction(Instruction());
		info.ifid.set_pc(0);
		info.ifid.set_id(0);
		return (true);
	}

	info.ifid.set_instruction(info.instructions[info.instructionIndex]);
	info.ifid.get_instruction().set_status(IF);
	info.ifid.set_pc(info.ifid.get_instruction().get_pc() + 4);
	info.ifid.set_id(info.ifid.get_instruction().get_id());
	info.instructionIndex++;
	return (true);
}