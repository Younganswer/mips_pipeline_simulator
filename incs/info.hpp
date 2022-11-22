#ifndef INFO_HPP
# define INFO_HPP

# include "../raylib/src/raylib.h"
# include "button.hpp"
# include "camera.hpp"
# include "instruction.hpp"

# include <vector>

using namespace std;

typedef enum _ScreenSize {
	screenWidth		= 192*6,
	screenHeight	= 108*6
}	ScreenSize;

class Info {
	public:
		Camera2D			camera;
		Button				button;
		vector<Instruction>	instructions;

		Info(void);
		Info(const char *textSegment, const char *dataSegment);
		~Info(void);
};

#endif