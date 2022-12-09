#include "../../incs/stages.hpp"
#include "../../incs/info.hpp"

bool	fetch(Info &info) {
	// End of instructions
	if (info.instructionIndex == info.instructions.size()) {
		info.ifid.set_instruction(Instruction());
		info.ifid.set_pc(0);
		info.ifid.set_instruction_hex(0);
		return (true);
	}
	info.instructionIndex += info.pcMuxinput[info.pcMuxselect];
	info.ifid.set_instruction(info.instructions[info.instructionIndex]);
	info.ifid.get_instruction().set_status(IF);
	info.ifid.set_pc(info.ifid.get_instruction().get_pc() + 4);
	info.ifid.set_instruction_hex(info.ifid.get_instruction().get_id());
	if (info.hazard.pc_write() == true) {
		info.pcMuxinput[0] = 1;
	} else {
		info.pcMuxinput[0] = 0;
	}
	return (true);
}
