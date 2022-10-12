#include "../../incs/info.hpp"
#include <memory.h>

Instruction::Instruction(void) {
	status			= IF;
	program_counter	= 0;
	binary_code		= 0;
	instruction		= string();
	return;
}

Instruction::~Instruction(void) {
	return;
}

bool	Info::read_instructions(void) {
	string	str;
	while (getline(cin, str)) {
		all_instructions.push_back(Instruction());
		Instruction	&cur = all_instructions.back();
		cur.instruction = str.c_str();
	}
	return (true);
}

Info::Info(void) {
	init_camera(camera);
	mouse_clicked = 0;
	pipeline.clear();
	read_instructions();
	return;
}

Info::~Info(void) {
	return;
}