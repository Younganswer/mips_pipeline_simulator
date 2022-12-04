#include "../../incs/draw_contents.hpp"
#include "../../incs/shape.hpp"

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
		DrawTextEx(GetFontDefault(), "Instruction", Vector2{-2480, 400}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, 440}, 30.0f, 2.0f, BLACK);

		// draw instruction value ------------------------------------------------------------------------
			// TODO: Get instruction value from info
			DrawTextEx(GetFontDefault(), "0x12345678", Vector2{-2430, 440}, 30.0f, 2.0f, BLACK);
		// draw instruction value ------------------------------------------------------------------------

	// draw instruction ----------------------------------------------------------------------------------

	// draw lines ----------------------------------------------------------------------------------------
		DrawLineEx(Vector2{ -1600, -1550 }, Vector2{ -2350, -1550}, 5.0f, BLACK);
		draw_down_arrow(-2350, -1550, -2350, -600, BLACK);
		draw_right_arrow(-2770, -330, -2500, -330, BLACK);
		draw_right_arrow(-2600, 430, -2500, 430, BLACK);
	// draw lines ----------------------------------------------------------------------------------------
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
		DrawTextEx(GetFontDefault(), "rs value", Vector2{120, -105}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, -65}, 30.0f, 2.0f, BLACK);
		// draw rs value ---------------------------------------------------------------------------------
			// TODO: Get rs value from info
			DrawTextEx(GetFontDefault(), "0x00000001", Vector2{170, -65}, 30.0f, 2.0f, BLACK);
		// draw rs value ---------------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(-250, -70, 100, -70, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rs -------------------------------------------------------------------------------------------

	// draw rt -------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rt value", Vector2{120, 500}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 540}, 30.0f, 2.0f, BLACK);
		// draw rt value ---------------------------------------------------------------------------------
			// TODO: Get rt value from info
			DrawTextEx(GetFontDefault(), "0x00000002", Vector2{170, 540}, 30.0f, 2.0f, BLACK);
		// draw rt value ---------------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(-250, 535, 100, 535, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rt -------------------------------------------------------------------------------------------

	// draw sign extended immediate ----------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Sign extended", Vector2{120, 900}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "immediate value", Vector2{120, 940}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 980}, 30.0f, 2.0f, BLACK);
		// draw sign extended immediate value ------------------------------------------------------------
			// TODO: Get sign extended immediate value from info
			DrawTextEx(GetFontDefault(), "0xfffffabc", Vector2{170, 980}, 30.0f, 2.0f, BLACK);
		// draw sign extended immediate value ------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(-1300, 955, 100, 955, BLACK);
	// draw sign extended immediate ----------------------------------------------------------------------

	// draw rs address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rs", Vector2{120, 1120}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1160}, 30.0f, 2.0f, BLACK);
		// draw rs address value -------------------------------------------------------------------------
			// TODO: Get rs address value from info
			DrawTextEx(GetFontDefault(), "$10", Vector2{170, 1160}, 30.0f, 2.0f, BLACK);
		// draw rs address value -------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(-1810, -185, 10, BLACK);
			DrawLineEx(Vector2{-1810, -185}, Vector2{-1810, 1160}, 5.0f, BLACK);
			draw_right_arrow(-1810, 1160, 100, 1160, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rs address -----------------------------------------------------------------------------------

	// draw rt address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rt", Vector2{120, 1240}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1280}, 30.0f, 2.0f, BLACK);
		// draw rt address value -------------------------------------------------------------------------
			// TODO: Get rt address value from info
			DrawTextEx(GetFontDefault(), "$11", Vector2{170, 1280}, 30.0f, 2.0f, BLACK);
		// draw rt address value -------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(-1930, 25, 10, BLACK);
			DrawLineEx(Vector2{-1930, 25}, Vector2{-1930, 1280}, 5.0f, BLACK);
			draw_right_arrow(-1930, 1280, 100, 1280, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rt address -----------------------------------------------------------------------------------

	// draw rd address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rd", Vector2{120, 1360}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1400}, 30.0f, 2.0f, BLACK);
		// draw rd address value -------------------------------------------------------------------------
			// TODO: Get rd address value from info
			DrawTextEx(GetFontDefault(), "$12", Vector2{170, 1400}, 30.0f, 2.0f, BLACK);
		// draw rd address value -------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(-2050, 1400, 10, BLACK);
			draw_right_arrow(-2050, 1400, 100, 1400, BLACK);
	// draw rd address -----------------------------------------------------------------------------------

	// draw mux sector -----------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{-450, -940, 100, 450}, 1.0f, 0, 5.0f, BLACK);
		DrawLineEx(Vector2{ -1100, -1500 }, Vector2 { -400, -1500 }, 5.0f, BLACK);
		draw_down_arrow(-400, -1500, -400, -940, BLACK);
		draw_right_arrow(-1600, -855, -450, -855, BLACK);
		draw_right_arrow(-550, -580, -450, -580, BLACK);
		DrawTextEx(GetFontDefault(), "0", Vector2{-610, -610}, 70.0f, 2.0f, BLACK);
		// draw mux text --------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "M", Vector2{-423, -850}, 70.0f, 2.0f, BLACK);
			DrawTextEx(GetFontDefault(), "U", Vector2{-420, -750}, 70.0f, 2.0f, BLACK);
			DrawTextEx(GetFontDefault(), "X", Vector2{-420, -650}, 70.0f, 2.0f, BLACK);
		// draw mux text --------------------------------------------------------------------------------
	// draw mux sector -----------------------------------------------------------------------------------

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
		DrawTextEx(GetFontDefault(), "ID/EX", (Vector2) { 180, -1535 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -1470, 300, 970}, 5.0f, Fade(BLUE, 0.4f));
		DrawRectangle(100, -1470, 300, 970, Fade(BLUE, 0.1f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		// draw ALU Opcode sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -1445, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -1445, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(-30, -1390, 125, -1390, Fade(BLUE, 0.8f));
			// draw ALU Opcode signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ALUOp", Vector2{150, -1430}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -1385}, 40.0f, 2.0f, BLUE);
				// draw ALU Opcode signal value --------------------------------------------------------
					// TODO: Get ALU Opcode signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -1385}, 40.0f, 2.0f, BLUE);
				// draw ALU Opcode signal value --------------------------------------------------------
			// draw ALU Opcode signal ----------------------------------------------------------------
		// draw ALU Opcode sector --------------------------------------------------------------------
		
		// draw ALU Source sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -1310, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -1310, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(-30, -1255, 125, -1255, Fade(BLUE, 0.8f));
			DrawCircle(-30, -1255, 10.0f, Fade(BLUE, 0.8f));
			// draw ALU Source signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ALUSrc", Vector2{150, -1295}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -1250}, 40.0f, 2.0f, BLUE);
				// draw ALU Source signal value --------------------------------------------------------
					// TODO: Get ALU Source signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -1250}, 40.0f, 2.0f, BLUE);
				// draw ALU Source signal value --------------------------------------------------------
			// draw ALU Source signal ----------------------------------------------------------------
		// draw ALU Source sector --------------------------------------------------------------------

		// draw Register Destination sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -1175, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -1175, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(-30, -1120, 125, -1120, Fade(BLUE, 0.8f));
			DrawCircle(-30, -1120, 10.0f, Fade(BLUE, 0.8f));
			// draw Register Destination signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegDst", Vector2{150, -1160}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -1115}, 40.0f, 2.0f, BLUE);
				// draw Register Destination signal value --------------------------------------------------------
					// TODO: Get Register Destination signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -1115}, 40.0f, 2.0f, BLUE);
				// draw Register Destination signal value --------------------------------------------------------
			// draw Register Destination signal ----------------------------------------------------------------
		// draw Register Destination sector --------------------------------------------------------------------

		// draw Memory Read sector --------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -1040, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -1040, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(-30, -985, 125, -985, Fade(BLUE, 0.8f));
			DrawCircle(-30, -985, 10.0f, Fade(BLUE, 0.8f));
			// draw Memory Read signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemRead", Vector2{150, -1025}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -980}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value --------------------------------------------------------
					// TODO: Get Memory Read signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -980}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value --------------------------------------------------------
			// draw Memory Read signal ----------------------------------------------------------------
		// draw Memory Read sector --------------------------------------------------------------------

		// draw Memory Write sector ---------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -905, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -905, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(-30, -850, 125, -850, Fade(BLUE, 0.8f));
			DrawCircle(-30, -850, 10.0f, Fade(BLUE, 0.8f));
			// draw Memory Write signal -------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemWrite", Vector2{150, -890}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -845}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value ----------------------------------------------------------------
					// TODO: Get Memory Write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -845}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value ----------------------------------------------------------------
			// draw Memory Write signal -------------------------------------------------------------------------
		// draw Memory Write sector ---------------------------------------------------------------------------

		// draw Memory to register sector -----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -770, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -770, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(-30, -715, 125, -715, Fade(BLUE, 0.8f));
			DrawCircle(-30, -715, 10.0f, Fade(BLUE, 0.8f));
			// draw Memory to register signal ----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{150, -755}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -710}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value --------------------------------------------------------
					// TODO: Get Memory to register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -710}, 40.0f, 2.0f, BLUE);
				// draw Memory to register signal value --------------------------------------------------------
			// draw Memory to register signal ----------------------------------------------------------------
		// draw Memory to register sector -----------------------------------------------------------------

		// draw Register Write sector ----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{125, -635, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(125, -635, 250, 110, Fade(BLUE, 0.15f));
			DrawLineEx(Vector2{ -350, -580 }, Vector2{ -30, -580 }, 5.0f, Fade(BLUE, 0.8f));
			draw_right_arrow(-30, -580, 125, -580, Fade(BLUE, 0.8f));
			DrawCircle(-30, -580, 10.0f, Fade(BLUE, 0.8f));
			// draw Register Write signal ---------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{150, -620}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{175, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value -----------------------------------------------------
					// TODO: Get Memory to register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{215, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value -----------------------------------------------------
			// draw Register Write signal ---------------------------------------------------------------
		// draw Register Write sector ----------------------------------------------------------------

		DrawLineEx(Vector2{ -30, -575 }, Vector2{ -30, -1390 }, 5.0f, Fade(BLUE, 0.8f));
	// draw signal ---------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	draw_ex_mem_signal(const Info &info) {
	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "EX/MEM", (Vector2) { 1850, -1130 }, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{1800, -1065, 300, 565}, 5.0f, Fade(BLUE, 0.4f));
		DrawRectangle(1800, -1065, 300, 565, Fade(BLUE, 0.1f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		// draw Memory Read sector ---------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1825, -1040, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1825, -1040, 245, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(375, -985, 1825, -985, Fade(BLUE, 0.8f));
			// draw Memory Read signal -----------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemRead", Vector2{1850, -1025}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1875, -980}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value ---------------------------------------------------------
					// TODO: Get Memory Read signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1915, -980}, 40.0f, 2.0f, BLUE);
				// draw Memory Read signal value ---------------------------------------------------------
			// draw Memory Read signal -----------------------------------------------------------------
		// draw Memory Read sector ---------------------------------------------------------------------

		// draw Memory Write sector -------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1825, -905, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1825, -905, 245, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(375, -850, 1825, -850, Fade(BLUE, 0.8f));
			// draw Memory Write signal -----------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemWrite", Vector2{1850, -890}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1875, -845}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value ---------------------------------------------------------------
					// TODO: Get Memory Write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1915, -845}, 40.0f, 2.0f, BLUE);
				// draw Memory Write signal value ---------------------------------------------------------------
			// draw Memory Write signal -----------------------------------------------------------------------
		// draw Memory Write sector -------------------------------------------------------------------------

		// draw Memory To Register sector -----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1825, -770, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1825, -770, 245, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(375, -715, 1825, -715, Fade(BLUE, 0.8f));
			// draw Memory To Register signal ---------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{1850, -755}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1875, -710}, 40.0f, 2.0f, BLUE);
				// draw Memory To Register signal value -------------------------------------------------------
					// TODO: Get Memory To Register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1915, -710}, 40.0f, 2.0f, BLUE);
				// draw Memory To Register signal value -------------------------------------------------------
			// draw Memory To Register signal ---------------------------------------------------------------
		// draw Memory To Register sector -----------------------------------------------------------------
	
		// draw Register Write sector --------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{1825, -635, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(1825, -635, 245, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(375, -580, 1825, -580, Fade(BLUE, 0.8f));
			// draw Register Write signal -----------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{1850, -620}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{1875, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value --------------------------------------------------
					// TODO: Get Register Write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{1915, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value --------------------------------------------------
			// draw Register Write signal -----------------------------------------------------------
		// draw Register Write sector --------------------------------------------------------------
	
	// draw signal ---------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	draw_mem_wb_signal(const Info &info) {
	// draw text that indicates the current pipeline stage -----------------------------------------------
		DrawTextEx(GetFontDefault(), "MEM/WB", Vector2{3340, -855}, 50.0f, 2.0f, BLACK);
	// draw text that indicates the current pipeline stage -----------------------------------------------

	// draw signal sector -----------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{3300, -795, 300, 295}, 5.0f, Fade(BLUE, 0.4f));
		DrawRectangle(3300, -795, 300, 295, Fade(BLUE, 0.1f));
	// draw signal sector -----------------------------------------------------------------------------

	// draw signal ---------------------------------------------------------------------------------------
		
		// draw Memory To Register sector -----------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{3325, -770, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(3325, -770, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(2075, -715, 3325, -715, Fade(BLUE, 0.8f));
			// draw Memory To Register signal ---------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{3350, -755}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{3375, -710}, 40.0f, 2.0f, BLUE);
				// draw Memory To Register signal value -------------------------------------------------------
					// TODO: Get Memory To Register signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{3415, -710}, 40.0f, 2.0f, BLUE);
				// draw Memory To Register signal value -------------------------------------------------------
			// draw Memory To Register signal ---------------------------------------------------------------
		// draw Memory To Register sector -----------------------------------------------------------------
	
		// draw Register Write sector --------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{3325, -635, 250, 110}, 5.0f, Fade(BLUE, 0.8f));
			DrawRectangle(3325, -635, 250, 110, Fade(BLUE, 0.15f));
			draw_right_arrow(2075, -580, 3325, -580, Fade(BLUE, 0.8f));
			// draw Register Write signal -----------------------------------------------------------
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{3350, -620}, 40.0f, 2.0f, BLUE);
				DrawTextEx(GetFontDefault(), "=>", Vector2{3375, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value --------------------------------------------------
					// TODO: Get Register Write signal value from info
					DrawTextEx(GetFontDefault(), "True", Vector2{3415, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value --------------------------------------------------
			// draw Register Write signal -----------------------------------------------------------
		// draw Register Write sector --------------------------------------------------------------
	
	// draw signal ---------------------------------------------------------------------------------------

	(void) info;
	return (true);
}
//3300, -500, 300, 2000