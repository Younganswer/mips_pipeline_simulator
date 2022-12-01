#include "../../incs/draw_contents.hpp"

bool	draw_if_id(const Info &info);
bool	draw_id_ex(const Info &info);
bool	draw_id_ex_signal(const Info &info);
bool	draw_ex_mem(const Info &info);
bool	draw_ex_mem_signal(const Info &info);
bool	draw_mem_wb(const Info &info);
bool	draw_mem_wb_signal(const Info &info);

bool	draw_if_id(const Info &info) {
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

	(void) info;
	return (true);
}

bool	draw_id_ex(const Info &info) {
	// draw id/ex signal -------------------------------------------------------------------------------
		draw_id_ex_signal(info);
	// draw id/ex signal -------------------------------------------------------------------------------

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
	(void) info;
	return (true);
}

bool	draw_ex_mem(const Info &info) {
	// draw ex/mem signal ------------------------------------------------------------------------------
		draw_ex_mem_signal(info);
	// draw ex/mem signal ------------------------------------------------------------------------------

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
	(void) info;
	return (true);
}

bool	draw_mem_wb(const Info &info) {
	// draw mem/wb signal ------------------------------------------------------------------------------
		draw_mem_wb_signal(info);
	// draw mem/wb signal ------------------------------------------------------------------------------

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
	(void) info;
	return (true);
}

bool	draw_id_ex_signal(const Info &info) {
	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "ID/EX", (Vector2) { 180, -1620 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -1560, 300, 1060}, 5.0f, Fade(BLUE, 0.4f));
		DrawRectangle(100, -1560, 300, 1060, Fade(BLUE, 0.1f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------

		// draw ALU Opcode sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -1540, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -1540, 260, 110, Fade(BLUE, 0.15f));
			// draw ALU Opcode signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ALUOp", Vector2{135, -1525}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -1480}, 40.0f, 2.0f, BLUE);
				// draw ALU Opcode signal value --------------------------------------------------------
					// TODO: Get ALU Opcode signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -1480}, 40.0f, 2.0f, BLUE);
				// draw ALU Opcode signal value --------------------------------------------------------
			// draw ALU Opcode signal ----------------------------------------------------------------
		// draw ALU Opcode sector --------------------------------------------------------------------

		// draw ALU Source sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -1410, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -1410, 260, 110, Fade(BLUE, 0.15f));
			// draw ALU Source signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ALUSrc", Vector2{135, -1395}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -1350}, 40.0f, 2.0f, BLUE);
				// draw ALU Source signal value --------------------------------------------------------
					// TODO: Get ALU Source signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -1350}, 40.0f, 2.0f, BLUE);
				// draw ALU Source signal value --------------------------------------------------------
			// draw ALU Source signal ----------------------------------------------------------------
		// draw ALU Source sector --------------------------------------------------------------------
		
		// draw Register Destination sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -1280, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -1280, 260, 110, Fade(BLUE, 0.15f));
			// draw Register Destination signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegDst", Vector2{135, -1265}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -1220}, 40.0f, 2.0f, BLUE);
				// draw Register Destination signal value --------------------------------------------------------
					// TODO: Get Register Destination signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -1220}, 40.0f, 2.0f, BLUE);
				// draw Register Destination signal value --------------------------------------------------------
			// draw Register Destination signal ----------------------------------------------------------------
		// draw Register Destination sector --------------------------------------------------------------------

		// draw Memory Write sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -1150, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -1150, 260, 110, Fade(BLUE, 0.15f));
			// draw Memory Write signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemWrite", Vector2{135, -1135}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -1090}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value --------------------------------------------------------
					// TODO: Get Memory Write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -1090}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value --------------------------------------------------------
			// draw Memory Write signal ----------------------------------------------------------------
		// draw Memory Write sector --------------------------------------------------------------------

		// draw Memory Read sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -1020, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -1020, 260, 110, Fade(BLUE, 0.15f));
			// draw Memory Read signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemRead", Vector2{135, -1005}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -960}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value --------------------------------------------------------
					// TODO: Get Memory Read signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -960}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value --------------------------------------------------------
			// draw Memory Read signal ----------------------------------------------------------------
		// draw Memory Read sector --------------------------------------------------------------------

		// draw Branch sector ---------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -890, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -890, 260, 110, Fade(BLUE, 0.15f));
			// draw Branch signal -------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "Branch", Vector2{135, -875}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -830}, 40.0f, 2.0f, BLUE);
				// draw Branch signal value ----------------------------------------------------------------
					// TODO: Get Branch signal value from info
					DrawTextEx(GetFontDefault(), "False", Vector2{200, -830}, 40.0f, 2.0f, BLUE);
				// draw Branch signal value ----------------------------------------------------------------
			// draw Branch signal -------------------------------------------------------------------------
		// draw Branch sector ---------------------------------------------------------------------------

		// draw Register write sector -----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -760, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -760, 260, 110, Fade(BLUE, 0.15f));
			// draw Register write signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{135, -745}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -700}, 40.0f, 2.0f, BLUE);
				// draw Register write signal value --------------------------------------------------------
					// TODO: Get Register write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -700}, 40.0f, 2.0f, BLUE);
				// draw Register write signal value --------------------------------------------------------
			// draw Register write signal ----------------------------------------------------------------
		// draw Register write sector -----------------------------------------------------------------

		// draw Memory to register sector ----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{120, -630, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(120, -630, 260, 110, Fade(BLUE, 0.15f));
			// draw Memory to register signal ---------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{135, -615}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{160, -570}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value -----------------------------------------------------
					// TODO: Get Memory to register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{200, -570}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value -----------------------------------------------------
			// draw Memory to register signal ---------------------------------------------------------------
		// draw Memory to register sector ----------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	draw_ex_mem_signal(const Info &info) {
	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "EX/MEM", (Vector2) { 1850, -1230 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{1800, -1170, 300, 670}, 5.0f, Fade(BLUE, 0.4f));
		DrawRectangle(1800, -1170, 300, 670, Fade(BLUE, 0.1f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		
		// draw Memory Write sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1820, -1150, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1820, -1150, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2{ 380, -1095 }, Vector2 { 1820, -1095 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Memory Write signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemWrite", Vector2{1835, -1135}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1860, -1090}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value --------------------------------------------------------
					// TODO: Get Memory Write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1900, -1090}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value --------------------------------------------------------
			// draw Memory Write signal ----------------------------------------------------------------

		// draw Memory Write sector --------------------------------------------------------------------

		// draw Memory Read sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1820, -1020, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1820, -1020, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2{ 380, -965 }, Vector2 { 1820, -965 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Memory Read signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemRead", Vector2{1835, -1005}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1860, -960}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value --------------------------------------------------------	
					// TODO: Get Memory Read signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1900, -960}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value --------------------------------------------------------
			// draw Memory Read signal ----------------------------------------------------------------
		// draw Memory Read sector --------------------------------------------------------------------
	
		// draw Branch sector -----------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1820, -890, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1820, -890, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2{ 380, -835 }, Vector2 { 1820, -835 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Branch signal -------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "Branch", Vector2{1835, -875}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1860, -830}, 40.0f, 2.0f, BLUE);
				// draw Branch signal value ----------------------------------------------------------------
					// TODO: Get Branch signal value from info
					DrawTextEx(GetFontDefault(), "Flase", Vector2{1900, -830}, 40.0f, 2.0f, BLUE);
				// draw Branch signal value ----------------------------------------------------------------
			// draw Branch signal -------------------------------------------------------------------------
		// draw Branch sector -----------------------------------------------------------------------

		// draw Register Write sector ----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1820, -760, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1820, -760, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2{ 380, -705 }, Vector2 { 1820, -705 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Register write signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{1835, -745}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1860, -700}, 40.0f, 2.0f, BLUE);
				// draw Register write signal value --------------------------------------------------------
					// TODO: Get Register write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1900, -700}, 40.0f, 2.0f, BLUE);
				// draw Register write signal value --------------------------------------------------------
			// draw Register write signal ----------------------------------------------------------------
		// draw Register Write sector ----------------------------------------------------------------

		// draw Memory to Register sector -------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1820, -630, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1820, -630, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2{ 380, -575 }, Vector2 { 1820, -575 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Memory to register signal ---------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{1835, -615}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1860, -570}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value -----------------------------------------------------
					// TODO: Get Memory to register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1900, -570}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value -----------------------------------------------------
			// draw Memory to register signal ---------------------------------------------------------------
		// draw Memory to Register sector -------------------------------------------------------------
	
	// draw signal ---------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	draw_mem_wb_signal(const Info &info) {
	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "MEM/WB", Vector2{3340, -840}, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{3300, -780, 300, 280}, 5.0f, Fade(BLUE, 0.8f));
		DrawRectangle(3300, -780, 300, 280, Fade(BLUE, 0.1f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		
		// draw Register Write sector ----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{3320, -760, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(3320, -760, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2 { 2080, -705 }, Vector2 { 3320, -705 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Register write signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{3335, -745}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{3360, -700}, 40.0f, 2.0f, BLUE);
				// draw Register write signal value --------------------------------------------------------
					// TODO: Get Register write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{3400, -700}, 40.0f, 2.0f, BLUE);
				// draw Register write signal value --------------------------------------------------------
			// draw Register write signal ----------------------------------------------------------------
		// draw Register Write sector ----------------------------------------------------------------

		// draw Memory To Register sector -------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{3320, -630, 260, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(3320, -630, 260, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2 { 2080, -575 }, Vector2 { 3320, -575 }, 5.0f, Fade(BLUE, 0.8f));
			// draw Memory to register signal ---------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{3335, -615}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{3360, -570}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value -----------------------------------------------------
					//TODO: Get Memory to register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{3400, -570}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value -----------------------------------------------------
			// draw Memory to register signal ---------------------------------------------------------------
		// draw Memory To Register sector -------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------

	(void) info;
	return (true);
}
//3300, -500, 300, 2000