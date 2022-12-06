#include "../../incs/render.hpp"
#include "../../incs/shape.hpp"

bool	render_if_id(const Info &info);
bool	render_id_ex(const Info &info);
bool	render_id_ex_signal(const Info &info);
bool	render_ex_mem(const Info &info);
bool	render_ex_mem_signal(const Info &info);
bool	render_mem_wb(const Info &info);
bool	render_mem_wb_signal(const Info &info);

bool	render_if_id(const Info &info) {
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
			DrawTextEx(GetFontDefault(), "TRUE", Vector2{-2430, -440}, 30.0f, 2.0f, BLACK);
		// draw signal -----------------------------------------------------------------------------------

	// draw instruction write signal ---------------------------------------------------------------------

	// draw program counter ------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Program counter", Vector2{-2480, -360}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, -320}, 30.0f, 2.0f, BLACK);

		// draw pc value ---------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.ifid.get_pc()).c_str(), Vector2{-2430, -320}, 30.0f, 2.0f, BLACK);
		// draw pc value ---------------------------------------------------------------------------------

	// draw program counter ------------------------------------------------------------------------------

	// draw instruction ----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Instruction", Vector2{-2480, 400}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{-2470, 440}, 30.0f, 2.0f, BLACK);

		// draw instruction value ------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.ifid.get_id()).c_str(), Vector2{-2430, 440}, 30.0f, 2.0f, BLACK);
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

bool	render_id_ex(const Info &info) {
	// draw id/ex signal -------------------------------------------------------------------------------
		render_id_ex_signal(info);
	// draw id/ex signal -------------------------------------------------------------------------------

	// draw pipeline sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{100, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline sector ---------------------------------------------------------------------------

	// draw rs -------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rs value", Vector2{120, -105}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, -65}, 30.0f, 2.0f, BLACK);
		// draw rs value ---------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.idex.get_read_data1()).c_str(), Vector2{170, -65}, 30.0f, 2.0f, BLACK);
		// draw rs value ---------------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(-250, -70, 100, -70, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rs -------------------------------------------------------------------------------------------

	// draw rt -------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rt value", Vector2{120, 500}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 540}, 30.0f, 2.0f, BLACK);
		// draw rt value ---------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.idex.get_read_data2()).c_str(), Vector2{170, 540}, 30.0f, 2.0f, BLACK);
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
			DrawTextEx(GetFontDefault(), n2hexstr(info.idex.get_extend_imm()).c_str(), Vector2{170, 980}, 30.0f, 2.0f, BLACK);
		// draw sign extended immediate value ------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(-1300, 955, 100, 955, BLACK);
	// draw sign extended immediate ----------------------------------------------------------------------

	// draw rt address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rt", Vector2{120, 1125}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1165}, 30.0f, 2.0f, BLACK);
		// draw rt address value -------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.idex.get_rt()).c_str(), Vector2{170, 1165}, 30.0f, 2.0f, BLACK);
		// draw rt address value -------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(-1810, -185, 10, BLACK);
			DrawLineEx(Vector2{-1810, -185}, Vector2{-1810, 1160}, 5.0f, BLACK);
			draw_right_arrow(-1810, 1160, 100, 1160, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rt address -----------------------------------------------------------------------------------

	// draw rd address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rd", Vector2{120, 1245}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1285}, 30.0f, 2.0f, BLACK);
		// draw rd address value -------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.idex.get_rd()).c_str(), Vector2{170, 1285}, 30.0f, 2.0f, BLACK);
		// draw rd address value -------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(-1930, 25, 10, BLACK);
			DrawLineEx(Vector2{-1930, 25}, Vector2{-1930, 1280}, 5.0f, BLACK);
			draw_right_arrow(-1930, 1280, 100, 1280, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw rd address -----------------------------------------------------------------------------------

	// draw rs address -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "rs", Vector2{120, 1365}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{130, 1405}, 30.0f, 2.0f, BLACK);
		// draw rs address value -------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), n2hexstr(info.idex.get_rs()).c_str(), Vector2{170, 1405}, 30.0f, 2.0f, BLACK);
		// draw rs address value -------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(-2050, 1400, 10, BLACK);
			draw_right_arrow(-2050, 1400, 100, 1400, BLACK);
	// draw rs address -----------------------------------------------------------------------------------

	// TODO: Draw something that idw
	(void) info;
	return (true);
}

bool	render_ex_mem(const Info &info) {
	// draw ex/mem signal ------------------------------------------------------------------------------
		render_ex_mem_signal(info);
	// draw ex/mem signal ------------------------------------------------------------------------------

	// draw pipeline sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{1800, -500, 300, 2000}, 5.0f, BLACK);
	// draw pipeline sector ---------------------------------------------------------------------------

	// draw ALU result -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "ALU result", Vector2{1820, 200}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, 240}, 30.0f, 2.0f, BLACK);
		// draw ALU result value ------------------------------------------------------------------------
			// TODO: Get ALU result value from info
			DrawTextEx(GetFontDefault(), "0x00000003", Vector2{1880, 240}, 30.0f, 2.0f, BLACK);
		// draw ALU result value ------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(1670, 235, 1800, 235, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw ALU result -----------------------------------------------------------------------------------

	// draw write data -----------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Write data", Vector2{1820, 665}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, 705}, 30.0f, 2.0f, BLACK);
		// draw write data value ------------------------------------------------------------------------
			// TODO: Get write data value from info
			DrawTextEx(GetFontDefault(), "0x00000003", Vector2{1880, 705}, 30.0f, 2.0f, BLACK);
		// draw write data value ------------------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			DrawCircle(1100, 535, 10, BLACK);
			DrawLineEx(Vector2{1100, 535}, Vector2{1100, 700}, 5.0f, BLACK);
			draw_right_arrow(1100, 700, 1800, 700, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw write data -----------------------------------------------------------------------------------

	// draw write register -----------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Write register", Vector2{1820, 1185}, 30.0f, 2.0f, BLACK);
		DrawTextEx(GetFontDefault(), "=>", Vector2{1840, 1225}, 30.0f, 2.0f, BLACK);
		// draw write register value ----------------------------------------------------------------
			// TODO: Get write register value from info
			DrawTextEx(GetFontDefault(), "$12", Vector2{1880, 1225}, 30.0f, 2.0f, BLACK);
		// draw write register value ----------------------------------------------------------------
		// draw line ------------------------------------------------------------------------------------
			draw_right_arrow(1650, 1220, 1800, 1220, BLACK);
		// draw line ------------------------------------------------------------------------------------
	// draw write register -----------------------------------------------------------------------


	// TODO: Draw something that idw
	(void) info;
	return (true);
}

bool	render_mem_wb(const Info &info) {
	// draw mem/wb signal ------------------------------------------------------------------------------
		render_mem_wb_signal(info);
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

bool	render_id_ex_signal(const Info &info) {
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
					string	alu_opcode = (info.idex.get_alu_op() == 0) ? "00" : (info.idex.get_alu_op() == 1) ? "01" : "10";
					DrawTextEx(GetFontDefault(), alu_opcode.c_str(), Vector2{215, -1385}, 40.0f, 2.0f, BLUE);
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
					DrawTextEx(GetFontDefault(), to_string(info.idex.get_alu_src()).c_str(), Vector2{215, -1250}, 40.0f, 2.0f, BLUE);
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
					DrawTextEx(GetFontDefault(), to_string(info.idex.get_reg_dst()).c_str(), Vector2{215, -1115}, 40.0f, 2.0f, BLUE);
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
					string	mem_read = (info.idex.get_mem_read()) ? "True" : "False";
					DrawTextEx(GetFontDefault(), mem_read.c_str(), Vector2{215, -980}, 40.0f, 2.0f, BLUE);
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
					string	mem_write = (info.idex.get_mem_write()) ? "True" : "False";
					DrawTextEx(GetFontDefault(), mem_write.c_str(), Vector2{215, -845}, 40.0f, 2.0f, BLUE);
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
					string	mem_to_reg = (info.idex.get_mem_to_reg()) ? "True" : "False";
					DrawTextEx(GetFontDefault(), mem_to_reg.c_str(), Vector2{215, -710}, 40.0f, 2.0f, BLUE);
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
					string	reg_write = (info.idex.get_reg_write()) ? "True" : "False";
					DrawTextEx(GetFontDefault(), reg_write.c_str(), Vector2{215, -575}, 40.0f, 2.0f, BLUE);
				// draw Register Write signal value -----------------------------------------------------
			// draw Register Write signal ---------------------------------------------------------------
		// draw Register Write sector ----------------------------------------------------------------

		DrawLineEx(Vector2{ -30, -575 }, Vector2{ -30, -1390 }, 5.0f, Fade(BLUE, 0.8f));
	// draw signal ---------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_ex_mem_signal(const Info &info) {
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

bool	render_mem_wb_signal(const Info &info) {
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