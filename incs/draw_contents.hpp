#ifndef DRAW_CONTENTS_HPP
# define DRAW_CONTENTS_HPP

# include "info.hpp"

// draw_contents.cpp
bool	draw_contents(const Info &info);

// draw_operations.cpp
bool	draw_instruction_fetch(const Info &info);
bool	draw_instruction_decode(const Info &info);
bool	draw_execute(const Info &info);
bool	draw_memory_access(const Info &info);
bool	draw_write_back(const Info &info);

// draw_pipeline.cpp
bool	draw_if_id(const Info &info);
bool	draw_id_ex(const Info &info);
bool	draw_ex_mem(const Info &info);
bool	draw_mem_wb(const Info &info);

// draw_hazard_unit.cpp
bool	draw_hazard_unit(const Info &info);

// draw_forwarding_unit.cpp
bool	draw_forwarding_unit(const Info &info);

#endif