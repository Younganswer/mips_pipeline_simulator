#include "../../incs/stages.hpp"
#include "../../incs/info.hpp"
#include <iostream>

bool	fetch(Info &info) {
	// End of instructions
	info.instructionIndex += info.pcMuxinput[info.pcMuxselect];
	if (info.instructionIndex == info.instructions.size()) {
		info.ifid.set_instruction(Instruction());
		info.ifid.set_pc(0);
		info.ifid.set_instruction_hex(0);
		info.pcMuxinput[0] = info.pcMuxinput[1] = info.pcMuxinput[2] = 0;
		info.pcMuxselect = 0;
		return (true);
	}
	cout << info.instructions.size() << endl;
	cout << info.instructionIndex << endl;
	cout << info.instructions[info.instructionIndex].get_asm_string() << endl;
	info.ifid.set_instruction(info.instructions[info.instructionIndex]);
	info.ifid.get_instruction().set_status(IF);
	info.ifid.set_pc(info.ifid.get_instruction().get_pc() + 4);
	info.ifid.set_instruction_hex(info.ifid.get_instruction().get_id());
	info.pcMuxinput[0] = 1;
	// if (info.hazard.pc_write() == true) {
		// info.pcMuxinput[0] = 1;
	// } else {
		// info.pcMuxinput[0] = 0;
	// }
	return (true);
}
