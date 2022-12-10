#include <memory.h>
#include <fstream>
#include "../../incs/info.hpp"
#include <iostream>

template <typename I> std::string n2hexstr(I w, size_t hex_len = sizeof(I)<<1);

Info::Info(void) {
	// init_camera(this->camera);
}

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
	// Initialize data
	ifstream	dataFile(dataSegment);
	string		dataLine;
	getline(dataFile, dataLine); // Skip first line
	while (getline(dataFile, dataLine)) {
		if (dataLine[12] == '\t') {
			for (unsigned long i=0; i<(16-stoul(dataLine.substr(10, 1), nullptr, 16))/4; i++) {
				ui	address = stoul(dataLine.substr(1, 10), nullptr, 16) + i*4;
				ui	value = stoul(dataLine.substr(22+12*i, 10), nullptr, 16);
				mem.push_back({address, value});
			}
		}
	}
	dataFile.close();

	// Initialize registers
	memset(registerValues, 0, sizeof(registerValues));
	// global pointer
	registerValues[gp] = 0x10008000;
	// stack pointer
	registerValues[sp] = 0x7ffffe40;

	instructionIndex = 9;

	pcMuxInput[0] = pcMuxInput[1] = pcMuxInput[2] = 0;
	pcMuxSelect = 0;
}

Info::~Info(void) {}

void	Info::setInstructions(const char *textSegment) {
	ifstream	asmFile(textSegment);
	string		asmLine;
	getline(asmFile, asmLine); // Skip first line
	getline(asmFile, asmLine); // Skip second line
	while (getline(asmFile, asmLine)) {
		instructions.push_back(Instruction(asmLine));
	}
	asmFile.close();
}

void	Info::setMemory(const char *dataSegment) {
	ifstream	dataFile(dataSegment);
	string		dataLine;
	getline(dataFile, dataLine); // Skip first line
	while (getline(dataFile, dataLine)) {
		if (dataLine[12] == '\t') {
			for (unsigned long i=0; i<(16-stoul(dataLine.substr(10, 1), nullptr, 16))/4; i++) {
				ui	address = stoul(dataLine.substr(1, 10), nullptr, 16) + i*4;
				ui	value = stoul(dataLine.substr(22+12*i, 10), nullptr, 16);
				mem.push_back({address, value});
			}
		}
	}
	dataFile.close();
}

void	Info::setRegisterValues(void) {
	memset(registerValues, 0, sizeof(registerValues));
	// global pointer
	registerValues[gp] = 0x10008000;
	// stack pointer
	registerValues[sp] = 0x7ffffe40;
}