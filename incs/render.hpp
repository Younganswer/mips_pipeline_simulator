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

template <typename I> std::string n2hexstr(I w, size_t hex_len = sizeof(I)<<1) {
    static const char* digits = "0123456789abcdef";
    std::string rc(hex_len,'0');
    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4) {
        rc[i] = digits[(w>>j) & 0x0f];
    }
    rc = string("0x") + rc;
    return (rc);
}

#endif