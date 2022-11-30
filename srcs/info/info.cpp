#include <memory.h>
#include <fstream>
#include "../../incs/info.hpp"
#include <iostream>

template <typename I> std::string n2hexstr(I w, size_t hex_len = sizeof(I)<<1);

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

	{
		// check memory
		for (size_t i=0; i<mem.size(); i++) {
			cout << "[0x" << n2hexstr(mem[i].address, 8) << "] 0x" << n2hexstr(mem[i].value, 8) << '\n';
		}
	}

	// Initialize registers
	memset(registerValues, 0, sizeof(registerValues));
	// global pointer
	registerValues[gp] = 0x10008000;
	// stack pointer
	registerValues[sp] = 0x7ffffe40;
}

Info::~Info(void) {}

template <typename I> std::string n2hexstr(I w, size_t hex_len) {
    static const char* digits = "0123456789abcdef";
    std::string rc(hex_len,'0');
    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
        rc[i] = digits[(w>>j) & 0x0f];
    return rc;
}