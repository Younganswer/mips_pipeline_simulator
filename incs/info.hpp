#ifndef INFO_HPP
# define INFO_HPP

# include <iostream>
# include <stddef.h>
# include <vector>
# include <string>
# include "../raylib/src/raylib.h"
# include "camera.hpp"

using namespace std;

typedef enum _ScreenSize {
	screenWidth		= 1920,
	screenHeight	= 1080
}	ScreenSize;

typedef enum _Status {
	IF	= 0,
	ID	= 1,
	EX	= 2,
	MEM	= 3,
	WB	= 4
}	Status;

class Instruction {
public:
	Status			status;
	unsigned int	program_counter;
	unsigned int	binary_code;
	string			instruction;

	Instruction(void);
	~Instruction(void);
};

class Info {
private:
	bool	read_instructions(void);

public:
	// GUI
	Camera2D			camera;
	size_t				mouse_clicked;
	
	// Back
	vector<Instruction>	pipeline;
	vector<Instruction>	all_instructions;

	Info(void);
	~Info(void);
};

#endif