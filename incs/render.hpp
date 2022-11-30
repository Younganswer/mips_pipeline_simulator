#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "info.hpp"
# include "../libs/raylib/src/raylib.h"

// render.cpp
bool	render(Info &info);

// render_camera_sight.cpp
bool	render_camera_sight(Info &info);

// render_data
bool	render_data(Info &info);

#endif