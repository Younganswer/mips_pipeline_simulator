#include "../../incs/render.hpp"
#include "../../incs/shape.hpp"

bool	render_contents(const Info &info) {
	// draw operations ------------------------------------------------------------------
		render_instruction_fetch(info);
		render_instruction_decode(info);
		render_execute(info);
		render_memory_access(info);
		render_write_back(info);
	// draw operations ------------------------------------------------------------------

	// draw pipeline --------------------------------------------------------------------
		render_if_id(info);
		render_id_ex(info);
		render_ex_mem(info);
		render_mem_wb(info);
	// draw pipeline --------------------------------------------------------------------

	// draw units -----------------------------------------------------------------------
		render_units(info);
	// draw units -----------------------------------------------------------------------
	return (true);
}