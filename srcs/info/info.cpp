#include <memory.h>
#include <fstream>
#include "../../incs/info.hpp"

Info::Info(void) {}

Info::Info(const char *textSegment, const char *dataSegment) {
	// Initialize camera
	init_camera(this->camera);

	// Initialize instructions
	ifstream	asmFile(textSegment);
	string		asmLine;
	getline(asmFile, asmLine); // Skip first line
	getline(asmFile, asmLine); // Skip second line
	while (getline(asmFile, asmLine)) {
		instructions.push_back(Instruction(asmLine));
	}
	asmFile.close();

	(void) dataSegment;
	// // Initialize data
	// ifstream	dataFile(dataSegment);
	// string		dataLine;
	// while (getline(dataFile, dataLine)) {
	// 	data.push_back(stoul(dataLine, nullptr, 16));
	// }
	// dataFile.close();
}

Info::~Info(void) {}