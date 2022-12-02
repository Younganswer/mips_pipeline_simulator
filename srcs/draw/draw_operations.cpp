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
		draw_trapezoid(-2916, -450, 120);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "+", Vector2{ -2822, -362 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------

		// draw lines -------------------------------------------------------------------------------------------------
			DrawLineEx(Vector2{ -3250, 120 }, Vector2{ -3250, -400 }, 5.0f, BLACK);
			draw_right_arrow(-3250, -400, -2916, -400, BLACK);
			draw_right_arrow(-3000, -260, -2916, -260, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "4", Vector2{ -3060, -288 }, 70.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
	// draw alu sector ---------------------------------------------------------------------------------------------

	// draw pc sector -----------------------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -3580, -80, 180, 400 }, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "PC", Vector2{ -3532, 90 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(-3750, 120, -3580, 120, BLACK);
			draw_down_arrow(-3490, -1600, -3490, -80, BLACK);
			DrawLineEx(Vector2{ -3490, -1600 }, Vector2{ -1600, -1600 }, 5.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	// draw pc sector -----------------------------------------------------------------------------------------------

	// draw mux sector ----------------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ -3850, -30, 100, 300 }, 0.5f, 0, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "M", Vector2{ -3825, 10 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "U", Vector2{ -3822, 90 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "X", Vector2{ -3822, 170 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_down_arrow(-3800, -200, -3800, -30, BLACK);
			draw_right_arrow(-4000, 70, -3850, 70, BLACK);
			DrawLineEx(Vector2{ -4000, 70 }, Vector2{ -4000, -800 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -4000, -800 }, Vector2{ -2635, -800 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -2635, -800 }, Vector2{ -2635, -330 }, 5.0f, BLACK);
			DrawCircle(-2635, -330, 10.0f, BLACK);
			
			// TODO: draw extra lines
			draw_right_arrow(-4100, 170, -3850, 170, BLACK);
			DrawLineEx(Vector2{ -4100, 170 }, Vector2{ -4100, -1300 }, 5.0f, BLACK);
			// TODO: draw extra lines
		// draw lines -------------------------------------------------------------------------------------------------
	// draw mux sector ----------------------------------------------------------------------------------------------

	// draw and gate sector -----------------------------------------------------------------------------------------
		draw_circle_sector_lines_ex(-3800, -300, 100, -90, 90, 0, 5.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
			draw_down_arrow(-3850, -1200, -3850, -300, BLACK);
			draw_down_arrow(-3750, -500, -3750, -300, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	// draw and gate sector -----------------------------------------------------------------------------------------

	// draw Branch sector -------------------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -3800, -650, 250, 150 }, 5.0f, BLUE);
		DrawRectangle(-3800, -650, 250, 150, Fade(BLUE, 0.2f));
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "ID/EX", Vector2{ -3735, -612 }, 40.0f, 3.0f, BLUE);
			DrawTextEx(GetFontDefault(), "Branch", Vector2{ -3745, -568 }, 40.0f, 3.0f, BLUE);
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