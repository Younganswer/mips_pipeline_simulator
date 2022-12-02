#include "../../incs/draw_contents.hpp"

bool	draw_instruction_fetch(const Info &info);
bool	draw_instruction_decode(const Info &info);
bool	draw_execute(const Info &info);
bool	draw_memory_access(const Info &info);
bool	draw_write_back(const Info &info);

bool	draw_instruction_fetch(const Info &info) {
	// draw instruction memory sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -3100, -150, 500, 1000 }, 5.0f, BLACK);
	// draw instruction memory sector ---------------------------------------------------------------------------

	// draw text --------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Instruction", Vector2{ -3030, 240 }, 70.0f, 3.0f, BLACK);
		DrawTextEx(GetFontDefault(), "memory", Vector2{ -2970, 340 }, 70.0f, 3.0f, BLACK);
	// draw text --------------------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	draw_instruction_decode(const Info &info) {
	(void) info;
	return (true);
}

bool	draw_execute(const Info &info) {
	(void) info;
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