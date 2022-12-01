#include "../../incs/draw_contents.hpp"

bool	draw_if_id(const Info &info);
bool	draw_id_ex(const Info &info);
bool	draw_ex_mem(const Info &info);
bool	draw_mem_wb(const Info &info);

bool	draw_if_id(const Info &info) {
	(void) info;

	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "IF/ID", (Vector2) { -2420, -570 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw pipeline sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{-2500, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline sector ---------------------------------------------------------------------------

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

	// draw instruction ----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Instruction", Vector2{-2480, 300}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, 340}, 30.0f, 2.0f, BLACK);

		// draw instruction value ------------------------------------------------------------------------
			// TODO: Get instruction value from info
			DrawTextEx(GetFontDefault(), "0x12345678", Vector2{-2430, 340}, 30.0f, 2.0f, BLACK);
		// draw instruction value ------------------------------------------------------------------------

	// draw instruction ----------------------------------------------------------------------------------

	return (true);
}

bool	draw_id_ex(const Info &info) {
	(void) info;

	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "ID/EX", (Vector2) { 180, -1170 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -1100, 300, 200}, 5.0f, BLUE);
		DrawRectangle(100, -1100, 300, 200, Fade(BLUE, 0.2f));
		DrawRectangleLinesEx(Rectangle{100, -900, 300, 200}, 5.0f, BLUE);
		DrawRectangle(100, -900, 300, 200, Fade(BLUE, 0.2f));
		DrawRectangleLinesEx(Rectangle{100, -700, 300, 200}, 5.0f, BLUE);
		DrawRectangle(100, -700, 300, 200, Fade(BLUE, 0.2f));
	// draw signal sector -----------------------------------------------------------------------------

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

	// draw pipeline sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline sector ---------------------------------------------------------------------------

	// draw rs -------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rs value", Vector2{120, -240}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, -200}, 30.0f, 2.0f, BLACK);

		// draw rs value ---------------------------------------------------------------------------------
			// TODO: Get rs value from info
			DrawTextEx(GetFontDefault(), "0x00000001", Vector2{170, -200}, 30.0f, 2.0f, BLACK);
		// draw rs value ---------------------------------------------------------------------------------
	// draw rs -------------------------------------------------------------------------------------------

	// draw rt -------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rt value", Vector2{120, 100}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 140}, 30.0f, 2.0f, BLACK);

		// draw rt value ---------------------------------------------------------------------------------
			// TODO: Get rt value from info
			DrawTextEx(GetFontDefault(), "0x00000002", Vector2{170, 140}, 30.0f, 2.0f, BLACK);
		// draw rt value ---------------------------------------------------------------------------------
	// draw rt -------------------------------------------------------------------------------------------

	// draw sign extended immediate ----------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Sign extended", Vector2{120, 460}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "immediate value", Vector2{120, 500}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 540}, 30.0f, 2.0f, BLACK);

		// draw sign extended immediate value ------------------------------------------------------------
			// TODO: Get sign extended immediate value from info
			DrawTextEx(GetFontDefault(), "0xfffffabc", Vector2{170, 540}, 30.0f, 2.0f, BLACK);
		// draw sign extended immediate value ------------------------------------------------------------
	// draw sign extended immediate ----------------------------------------------------------------------

	// draw rs address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rs", Vector2{120, 860}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 900}, 30.0f, 2.0f, BLACK);

		// draw rs address value -------------------------------------------------------------------------
			// TODO: Get rs address value from info
			DrawTextEx(GetFontDefault(), "$10", Vector2{170, 900}, 30.0f, 2.0f, BLACK);
		// draw rs address value -------------------------------------------------------------------------
	// draw rs address -----------------------------------------------------------------------------------

	// draw rt address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rt", Vector2{120, 980}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1020}, 30.0f, 2.0f, BLACK);

		// draw rt address value -------------------------------------------------------------------------
			// TODO: Get rt address value from info
			DrawTextEx(GetFontDefault(), "$11", Vector2{170, 1020}, 30.0f, 2.0f, BLACK);
		// draw rt address value -------------------------------------------------------------------------
	// draw rt address -----------------------------------------------------------------------------------

	// draw rd address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rd", Vector2{120, 1100}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1140}, 30.0f, 2.0f, BLACK);

		// draw rd address value -------------------------------------------------------------------------
			// TODO: Get rd address value from info
			DrawTextEx(GetFontDefault(), "$12", Vector2{170, 1140}, 30.0f, 2.0f, BLACK);
		// draw rd address value -------------------------------------------------------------------------
	// draw rd address -----------------------------------------------------------------------------------

	// TODO: Draw something that idw
	return (true);
}

bool	draw_ex_mem(const Info &info) {
	(void) info;

	// draw text that indicate the current pipeline stage ------------------------------------------------
		DrawTextEx(GetFontDefault(), "EX/MEM", Vector2{1850, -970}, 50.0f, 2.0f, BLACK);
	// draw text that indicate the current pipeline stage ------------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{1800, -900, 300, 200}, 5.0f, BLUE);
		DrawRectangle(1800, -900, 300, 200, Fade(BLUE, 0.2f));
		DrawRectangleLinesEx(Rectangle{1800, -700, 300, 200}, 5.0f, BLUE);
		DrawRectangle(1800, -700, 300, 200, Fade(BLUE, 0.2f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Write back", Vector2{1820, -880}, 40.0f, 2.0f, BLUE);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, -820}, 40.0f, 2.0f, BLUE);

		// draw memory write signal value ----------------------------------------------------------------
			// TODO: Get memory write signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{1880, -825}, 50.0f, 2.0f, BLUE);
		// draw memory write signal value ----------------------------------------------------------------

		DrawTextEx(GetFontDefault(), "Memory read", Vector2{1820, -680}, 40.0f, 2.0f, BLUE);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, -620}, 40.0f, 2.0f, BLUE);

		// draw memory read signal value -----------------------------------------------------------------
			// TODO: Get memory read signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{1880, -625}, 50.0f, 2.0f, BLUE);
		// draw memory read signal value -----------------------------------------------------------------
	// draw signal ---------------------------------------------------------------------------------------

	// draw pipeline sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{1800, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline sector ---------------------------------------------------------------------------

	// draw ALU result -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "ALU result", Vector2{1820, 0}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, 40}, 30.0f, 2.0f, BLACK);

		// draw ALU result value ------------------------------------------------------------------------
			// TODO: Get ALU result value from info
			DrawTextEx(GetFontDefault(), "0x00000003", Vector2{1880, 40}, 30.0f, 2.0f, BLACK);
		// draw ALU result value ------------------------------------------------------------------------
	// draw ALU result -----------------------------------------------------------------------------------

	// draw sign extended immediate ----------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Sign extended", Vector2{1820, 460}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "immediate value", Vector2{1820, 500}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, 540}, 30.0f, 2.0f, BLACK);

		// draw sign extended immediate value ------------------------------------------------------------
			// TODO: Get sign extended immediate value from info
			DrawTextEx(GetFontDefault(), "0xfffffabc", Vector2{1880, 540}, 30.0f, 2.0f, BLACK);
		// draw sign extended immediate value ------------------------------------------------------------
	// draw sign extended immediate ----------------------------------------------------------------------

	// TODO: Draw something that idw
	return (true);
}

bool	draw_mem_wb(const Info &info) {
	(void) info;

	// draw text that indicate the current pipeline stage ------------------------------------------------
		DrawTextEx(GetFontDefault(), "MEM/WB", Vector2{3340, -770}, 50.0f, 2.0f, BLACK);
	// draw text that indicate the current pipeline stage ------------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{3300, -700, 300, 200}, 5.0f, BLUE);
		DrawRectangle(3300, -700, 300, 200, Fade(BLUE, 0.2f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Write back", Vector2{3320, -680}, 40.0f, 2.0f, BLUE);
		DrawTextEx(GetFontDefault(), "=>", Vector2{3340, -620}, 40.0f, 2.0f, BLUE);

		// draw memory write signal value ----------------------------------------------------------------
			// TODO: Get memory write signal value from info
			DrawTextEx(GetFontDefault(), "True", Vector2{3380, -625}, 50.0f, 2.0f, BLUE);
		// draw memory write signal value ----------------------------------------------------------------
	// draw signal ---------------------------------------------------------------------------------------

	// draw pipeline sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{3300, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline sector ---------------------------------------------------------------------------

	// draw data read from memory ------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Data read", Vector2{3320, 0}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "from memory", Vector2{3320, 40}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{3340, 80}, 30.0f, 2.0f, BLACK);

		// draw data read from memory value --------------------------------------------------------------
			// TODO: Get data read from memory value from info
			DrawTextEx(GetFontDefault(), "0x87654321", Vector2{3380, 80}, 30.0f, 2.0f, BLACK);
		// draw data read from memory value --------------------------------------------------------------
	// draw data read from memory ------------------------------------------------------------------------

	// draw ALU result -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "ALU result", Vector2{3320, 800}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{3340, 840}, 30.0f, 2.0f, BLACK);

		// draw ALU result value ------------------------------------------------------------------------
			// TODO: Get ALU result value from info
			DrawTextEx(GetFontDefault(), "0x00000003", Vector2{3380, 840}, 30.0f, 2.0f, BLACK);
		// draw ALU result value ------------------------------------------------------------------------
	// draw ALU result -----------------------------------------------------------------------------------
	return (true);
}