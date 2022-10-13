#ifndef INFO_HPP
# define INFO_HPP

# include <iostream>
# include <stddef.h>
# include <vector>
# include <string>
# include "../raylib/src/raylib.h"

using namespace std;

typedef enum _ScreenSize {
	screenWidth		= 192*6,
	screenHeight	= 108*6
}	ScreenSize;

typedef enum _Status {
	IF	= 0,
	ID	= 1,
	EX	= 2,
	MEM	= 3,
	WB	= 4
}	Status;

typedef enum _ButtonState {
	NORMAL		= 0,
	MOUSE_HOVER	= 1,
	PRESSED		= 2
}	ButtonState;

typedef struct _Button {
	Texture2D	button;
	Rectangle	btnBounds;
	Rectangle	sourceRec;
	ButtonState	state;
	bool		btnAction;
	int			btnClicked;
}	Button;

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
	Camera2D	camera;
	Button		button;
	Vector2		mouse;

	// Back
	vector<Instruction>	pipeline;
	vector<Instruction>	all_instructions;

	Info(void);
	~Info(void);
};

#endif