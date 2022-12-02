#ifndef SHAPE_HPP
# define SHAPE_HPP

# include "info.hpp"
# include "../libs/raylib/src/raylib.h"

# define ARROW_LENGTH 20

// draw_arrow.cpp
bool	draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
bool	draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
bool	draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
bool	draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);

// draw_circle_sector_lines_ex.cpp
bool	draw_circle_sector_lines_ex(float centerX, float centerY, float radius, float startAngle, float endAngle, int segments, float thick, Color color);

// draw_mux.cpp
bool	draw_mux_0_1(int posX, int posY, Color color);
bool	draw_mux_1_0(int posX, int posY, Color color);
bool	DrawEllipseLinesEx(int posX, int posY, Color color);

// draw_dot.cpp
bool	draw_dot(int posX, int posY, Color color);

// draw_trapezoid.cpp
bool	draw_trapezoid(float posX, float posY, float size);

#endif