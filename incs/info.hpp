#ifndef INFO_HPP
# define INFO_HPP

# include "../raylib/src/raylib.h"
# include "camera.hpp"
# include "button.hpp"

using namespace std;

typedef enum _ScreenSize {
	screenWidth		= 192*6,
	screenHeight	= 108*6
}	ScreenSize;

class Info {
	private:
		Camera2D	camera;
		Button		button;
		Mouse		mouse;
		vector<Instruction>	pipeline;
		vector<Instruction>	all_instructions;
};

#endif