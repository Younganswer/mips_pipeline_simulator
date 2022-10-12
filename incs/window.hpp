#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "info.hpp"
# include "../raylib/src/raylib.h"

bool	draw_window(Info &info);
bool	draw_camera_sight(Info &info);
bool	draw_edge(void);
bool	draw_guide(void);

#endif