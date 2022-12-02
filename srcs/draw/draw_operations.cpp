#include "../../incs/draw_contents.hpp"
#include "../../incs/shape.hpp"

bool	draw_instruction_fetch(const Info &info);
bool	draw_instruction_decode(const Info &info);
bool	draw_execute(const Info &info);
bool	draw_memory_access(const Info &info);
bool	draw_write_back(const Info &info);

bool	draw_instruction_fetch(const Info &info) {
	// draw instruction memory sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -3100, -100, 500, 1000 }, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Address", Vector2{ -3050, 90 }, 70.0f, 1.0f, BLACK);
			DrawTextEx(GetFontDefault(), "Instruction", Vector2{ -3030, 340 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "memory", Vector2{ -2970, 440 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------

		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(-3400, 120, -3100, 120, BLACK);
			DrawCircle(-3250, 120, 10.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	// draw instruction memory sector ---------------------------------------------------------------------------

	// draw alu sector ---------------------------------------------------------------------------------------------
		draw_trapezoid(-2816, -450, 120);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "+", Vector2{ -2722, -362 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------

		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(-2900, -260, -2816, -260, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "4", Vector2{ -2960, -288 }, 70.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------

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