#include <memory.h>
#include "../../incs/info.hpp"
#include "camera.hpp"
#include "button.hpp"

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

Info::Info(void) {
	init_camera(camera);
	init_button(button);
	mouse.x = mouse.y = 0;
	pipeline.clear();
	return;
}

Info::~Info(void) {
	return;
}

bool	Info::read_file(FILE *textSegment, FILE *dataSegment) {
	// read text segment
	char	*line = NULL;
	char	hex[11];
	size_t	len = 0;
	ssize_t	read;
	
	(void) dataSegment;
	read = getline(&line, &len, textSegment);
	read = getline(&line, &len, textSegment);
	
	while ((read = getline(&line, &len, textSegment)) != -1) {
		Instruction	instruction;
		for (size_t i=0; i<11; i++) {
			hex[i] = line[i+1];
		}
		hex[10] = '\0';
		instruction.instruction = string("[") + string(hex) + string("] ");
		instruction.program_counter = (unsigned int)strtol(hex, NULL, 16);
		for (size_t i=0; i<11; i++) {
			hex[i] = line[i+13];
		}
		hex[10] = '\0';
		instruction.instruction += string("[") + string(hex) + string("]");
		instruction.binary_code = (unsigned int)strtol(hex, NULL, 16);
		pipeline.push_back(instruction);
		all_instructions.push_back(instruction);
	}
	return (true);
}