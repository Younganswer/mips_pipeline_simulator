#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "info.hpp"
# include "../libs/raylib/src/raylib.h"

// render.cpp
bool	render(Info &info);

// render_camera_sight.cpp
bool	render_camera_sight(Info &info);

// render_data.cpp
bool	render_data(Info &info);

// render_contents.cpp
bool	render_contents(const Info &info);

// render_operations.cpp
bool	render_instruction_fetch(const Info &info);
bool	render_instruction_decode(const Info &info);
bool	render_execute(const Info &info);
bool	render_memory_access(const Info &info);
bool	render_write_back(const Info &info);

// render_pipeline.cpp
bool	render_if_id(const Info &info);
bool	render_id_ex(const Info &info);
bool	render_ex_mem(const Info &info);
bool	render_mem_wb(const Info &info);

// render_units.cpp
bool	render_units(const Info &info);

#endif