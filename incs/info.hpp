#ifndef INFO_HPP
# define INFO_HPP

# define ui unsigned int

# include "../libs/raylib/src/raylib.h"
# include "button.hpp"
# include "camera.hpp"
# include "instruction.hpp"
# include <vector>

# ifndef SIZE_FACTOR
#  define SIZE_FACTOR 8
# endif

using namespace std;

typedef enum _ScreenSize {
	screenWidth		= 192*SIZE_FACTOR,
	screenHeight	= 108*SIZE_FACTOR
}	ScreenSize;

typedef enum _Register {
	r0 = 0,
	at,
	v0, v1,
	a0, a1, a2, a3,
	t0, t1, t2, t3, t4, t5, t6, t7,
	s0, s1, s2, s3, s4, s5, s6, s7,
	t8, t9,
	k0, k1,
	gp,
	sp,
	s8,
	ra,
}	Register;

const static string	register_text[32] = {
	"$r0", "$at",
	"$v0", "$v1",
	"$a0", "$a1", "$a2", "$a3",
	"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
	"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
	"$t8", "$t9",
	"$k0", "$k1",
	"$gp",
	"$sp",
	"$s8",
	"$ra"
};

typedef struct	_Memory {
	ui	address;
	ui	value;
}	Memory;

class Info {
	public:
		// Camera
		Camera2D			camera;
		// Button for next cycle
		Button				button;
		// Instructions
		vector<Instruction>	instructions;
		// Registers
		ui					registerValues[32];
		// Stack
		vector<ui>			st;
		// Memory
		vector<Memory>		mem;

		Info(void);
		Info(const char *textSegment, const char *dataSegment);
		~Info(void);
};

#endif