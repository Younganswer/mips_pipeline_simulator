#include "../../incs/render.hpp"
#include "../../incs/shape.hpp"

bool	render_contents(Info &info) {
	// draw operations ------------------------------------------------------------------
		render_write_back(info);
		render_memory_access(info);
		render_execute(info);
		render_instruction_decode(info);
		render_instruction_fetch(info);
	// draw operations ------------------------------------------------------------------

	// draw pipeline --------------------------------------------------------------------
		render_mem_wb(info);
		render_ex_mem(info);
		render_id_ex(info);
		render_if_id(info);
	// draw pipeline --------------------------------------------------------------------

	// draw units -----------------------------------------------------------------------
		render_units(info);
	// draw units -----------------------------------------------------------------------
	return (true);
}