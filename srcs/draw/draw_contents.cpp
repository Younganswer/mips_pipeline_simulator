#include "../../incs/draw_contents.hpp"
#include "../../incs/shape.hpp"

bool	draw_contents(const Info &info) {
	// draw operations ------------------------------------------------------------------
		draw_instruction_fetch(info);
		draw_instruction_decode(info);
		draw_execute(info);
		draw_memory_access(info);
		draw_write_back(info);
	// draw operations ------------------------------------------------------------------

	// draw pipeline --------------------------------------------------------------------
		draw_if_id(info);
		draw_id_ex(info);
		draw_ex_mem(info);
		draw_mem_wb(info);
	// draw pipeline --------------------------------------------------------------------
	return (true);
}