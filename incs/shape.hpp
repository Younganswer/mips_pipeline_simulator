#ifndef SHAPE_HPP
# define SHAPE_HPP

# include "info.hpp"
# include "../raylib/src/raylib.h"

# define ARROW_LENGTH 10

bool	draw_left_arrow(int startPosX, int startPosY, int endPosX, int endPosY);
bool	draw_right_arrow(int startPosX, int startPosY, int endPosX, int endPosY);
bool	draw_up_arrow(int startPosX, int startPosY, int endPosX, int endPosY);
bool	draw_down_arrow(int startPosX, int startPosY, int endPosX, int endPosY);

#endif