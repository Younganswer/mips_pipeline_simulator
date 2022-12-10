#include "../../incs/stages.hpp"
#include "../../incs/info.hpp"
#include <iostream>

bool	fetch(Info &info) {
	info.pcMuxInput[0] = 1;

	// End of instructions
	if (info.instructionIndex == info.instructions.size()) {
		info.ifid.set_instruction(Instruction());
		info.ifid.set_pc(0);
		info.ifid.set_instruction_hex(0);
		info.currentPc = 0;
		info.pcMuxInput[0] = info.pcMuxInput[1] = info.pcMuxInput[2] = 0;
		info.pcMuxSelect = 0;
		return (true);
	}

	// check Load-use hazard ---------------------------------------------------------------------------------------
		if (info.hazard.instruction_fetch() == true) {
			Instruction instruction = info.instructions[info.instructionIndex];
			info.currentPc = instruction.get_pc();
			instruction.set_status(IF);
			info.ifid.set_instruction(instruction);
			info.ifid.set_pc(info.currentPc + 4);
			info.ifid.set_instruction_hex(info.ifid.get_instruction().get_id());
		}
		// get next pc
		if (info.hazard.pc_write() == true) {
			info.instructionIndex += info.pcMuxInput[info.pcMuxSelect];
		}
	// check Load-use hazard ---------------------------------------------------------------------------------------

	// check Jump, Branch hazard -----------------------------------------------------------------------------------
		if (info.hazard.if_flush() == true) {
			info.ifid.set_instruction_hex(0);
			info.ifid.set_instruction(Instruction());
		}
	// check Jump, Branch hazard -----------------------------------------------------------------------------------
	return (true);
}
