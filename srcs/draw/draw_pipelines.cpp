#include "../../incs/draw_contents.hpp"

bool	draw_if_id(const Info &info);
bool	draw_id_ex(const Info &info);
bool	draw_ex_mem(const Info &info);
bool	draw_mem_wb(const Info &info);

bool	draw_if_id(const Info &info) {
	(void) info;

	// draw text that indicates the pipeline stage -------------------------------------------------------
		DrawTextEx(GetFontDefault(), "IF/ID", (Vector2) { -2420, -570 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the pipeline stage -------------------------------------------------------

	// draw pipeline rectangle ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{-2500, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline rectangle ---------------------------------------------------------------------------

	// draw instruction write signal ---------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Instruction write", Vector2{-2480, -480}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, -440}, 30.0f, 2.0f, BLACK);

		// draw signal -----------------------------------------------------------------------------------
			// TODO: Get signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{-2430, -440}, 30.0f, 2.0f, BLACK);
		// draw signal -----------------------------------------------------------------------------------

	// draw instruction write signal ---------------------------------------------------------------------

	// draw program counter ------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Program counter", Vector2{-2480, -360}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, -320}, 30.0f, 2.0f, BLACK);

		// draw pc value ---------------------------------------------------------------------------------
			// TODO: Get pc value from info
			DrawTextEx(GetFontDefault(), "0x00400024", Vector2{-2430, -320}, 30.0f, 2.0f, BLACK);
		// draw pc value ---------------------------------------------------------------------------------

	// draw program counter ------------------------------------------------------------------------------

	// draw instruction -------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Instruction", Vector2{-2480, 300}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, 340}, 30.0f, 2.0f, BLACK);

		// draw instruction value -------------------------------------------------------------------------
			// TODO: Get instruction value from info
			DrawTextEx(GetFontDefault(), "0x12345678", Vector2{-2430, 340}, 30.0f, 2.0f, BLACK);
		// draw instruction value -------------------------------------------------------------------------

	// draw instruction -------------------------------------------------------------------------------

	return (true);
}

bool	draw_id_ex(const Info &info) {
	(void) info;

	// draw text that indicates the pipeline stage -------------------------------------------------------
		DrawTextEx(GetFontDefault(), "ID/EX", (Vector2) { 180, -1170 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the pipeline stage -------------------------------------------------------

	// draw signal rectangle -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -1100, 300, 200}, 5.0f, BLUE);
		DrawRectangleLinesEx(Rectangle{100, -900, 300, 200}, 5.0f, BLUE);
		DrawRectangleLinesEx(Rectangle{100, -700, 300, 200}, 5.0f, BLUE);
	// draw signal rectangle -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Write back", Vector2{120, -1080}, 40.0f, 2.0f, BLUE);
		DrawTextEx(GetFontDefault(), "=>", Vector2{140, -1020}, 40.0f, 2.0f, BLUE);
		// draw write back signal value ------------------------------------------------------------------
			// TODO: Get write back signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{180, -1025}, 50.0f, 2.0f, BLUE);
		// draw write back signal value ------------------------------------------------------------------

		DrawTextEx(GetFontDefault(), "Memory Read", Vector2{120, -880}, 40.0f, 2.0f, BLUE);
		DrawTextEx(GetFontDefault(), "=>", Vector2{140, -820}, 40.0f, 2.0f, BLUE);
		// draw memory read signal value -----------------------------------------------------------------
			// TODO: Get memory read signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{180, -825}, 50.0f, 2.0f, BLUE);
		// draw memory read signal value -----------------------------------------------------------------

		DrawTextEx(GetFontDefault(), "Execute", Vector2{120, -680}, 40.0f, 2.0f, BLUE);
		DrawTextEx(GetFontDefault(), "=>", Vector2{140, -620}, 40.0f, 2.0f, BLUE);
		// draw execute signal value ---------------------------------------------------------------------
			// TODO: Get execute signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{180, -625}, 50.0f, 2.0f, BLUE);
		// draw execute signal value ---------------------------------------------------------------------
	// draw signal ---------------------------------------------------------------------------------------

	// draw pipeline rectangle ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline rectangle ---------------------------------------------------------------------------
	return (true);
}

bool	draw_ex_mem(const Info &info) {
	(void) info;
	DrawRectangleLinesEx(Rectangle{1800, -500, 300, 2000}, 5.0f, BLACK);
	return (true);
}

bool	draw_mem_wb(const Info &info) {
	DrawRectangleLinesEx(Rectangle{3300, -500, 300, 2000}, 5.0f, BLACK);
	(void) info;
	return (true);
}