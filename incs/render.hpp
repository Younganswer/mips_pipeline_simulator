#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "info.hpp"
# include "../libs/raylib/src/raylib.h"

// render.cpp
bool	render(Info &info);

// draw_camera_sight.cpp
bool	draw_camera_sight(Info &info);

// draw_window.cpp
bool	draw_window(Info &info);

#endif