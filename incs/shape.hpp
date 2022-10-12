#ifndef SHAPE_HPP
# define SHAPE_HPP

# include "info.hpp"
# include "../raylib/src/raylib.h"

# define ARROW_LENGTH 20

// draw_arrow.cpp
bool	draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY);
bool	draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY);
bool	draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY);
bool	draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY);

// draw_mux.cpp
bool	draw_mux_0_1(int posX, int posY);
bool	draw_mux_1_0(int posX, int posY);
bool	DrawEllipseLinesEx(int posX, int posY);

#endif