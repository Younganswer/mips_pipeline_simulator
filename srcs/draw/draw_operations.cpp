#include "../../incs/draw_contents.hpp"

bool	draw_instruction_fetch(const Info &info);
bool	draw_instruction_decode(const Info &info);
bool	draw_execute(const Info &info);
bool	draw_memory_access(const Info &info);
bool	draw_write_back(const Info &info);

bool	draw_instruction_fetch(const Info &info) {
	(void) info;
	return (true);
}

bool	draw_instruction_decode(const Info &info) {
	(void) info;
	// draw hazard unit ----------------------------------------------------------------------------------------
		draw_hazard_unit(info);
	// draw hazard unit ----------------------------------------------------------------------------------------
	return (true);
}

bool	draw_execute(const Info &info) {
	(void) info;
	// draw forwarding unit ------------------------------------------------------------------------------------
		draw_forwarding_unit(info);
	// draw forwarding unit ------------------------------------------------------------------------------------
	return (true);
}

bool	draw_memory_access(const Info &info) {
	(void) info;
	return (true);
}

bool	draw_write_back(const Info &info) {
	(void) info;
	return (true);
}