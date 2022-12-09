#include "../../incs/render.hpp"
#include "../../incs/shape.hpp"

bool	render_instruction_fetch(Info &info);
bool	render_instruction_decode(Info &info);
bool	render_execute(Info &info);
bool	render_memory_access(Info &info);
bool	render_write_back(Info &info);

bool	render_instruction_fetch(Info &info) {
	// draw instruction memory sector ---------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -3100, -100, 500, 1000 }, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Address", Vector2{ -3050, 50 }, 70.0f, 1.0f, BLACK);
			DrawTextEx(GetFontDefault(), "=>", Vector2{ -3030, 125 }, 50.0f, 3.0f, BLACK);
			// TODO: get pc value from pc unit not ifid
			DrawTextEx(GetFontDefault(), n2hexstr(info.ifid.get_pc()-4).c_str(), Vector2{ -2980, 125 }, 50.0f, 3.0f, BLACK);
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
			DrawLineEx(Vector2{ -3200, -995 }, Vector2{ -3800, -995 }, 5.0f, BLACK);
			draw_down_arrow(-3800, -995, -3800, -30, BLACK);

			DrawCircle(-2635, -330, 10.0f, BLACK);
			DrawLineEx(Vector2{ -2635, -330 }, Vector2{ -2635, -600 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -2635, -600 }, Vector2{ -4000, -600 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -4000, -600 }, Vector2{ -4000, 70 }, 5.0f, BLACK);
			draw_right_arrow(-4000, 70, -3850, 70, BLACK);
			
			DrawLineEx(Vector2{ -912, -435 }, Vector2{ -765, -435 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -765, -435 }, Vector2{ -765, -1250 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -765, -1250 }, Vector2{ -4100, -1250 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -4100, -1250 }, Vector2{ -4100, 170 }, 5.0f, BLACK);
			draw_right_arrow(-4100, 170, -3850, 170, BLACK);

			DrawLineEx(Vector2{ -2900, -750 }, Vector2{ -4050, -750 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -4050, -750 }, Vector2{ -4050, 120 }, 5.0f, BLACK);
			draw_right_arrow(-4050, 120, -3850, 120, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
		// draw bus combine sector --------------------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ -3200, -1120, 100, 250 }, 5.0f, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
				draw_left_arrow(-2600, -1062.5, -3100, -1062.5, BLACK);
				draw_left_arrow(-1900, -925, -3100, -925, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
		// draw bus combine sector --------------------------------------------------------------------------------------
		// draw and gate sector ----------------------------------------------------------------------------------------
			draw_circle_sector_lines_ex(-2500, -1062.5, 100, 180, 360, 0, 5.0f, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
				DrawLineEx(Vector2{ -50, 220 }, Vector2{ -170, 220 }, 5.0f, BLACK);
				DrawLineEx(Vector2{ -170, 220 }, Vector2{ -170, -1125 }, 5.0f, BLACK);
				draw_left_arrow(-170, -1125, -2500, -1125, BLACK);
				draw_left_arrow(-1900, -1000, -2500, -1000, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
		// draw and gate sector ----------------------------------------------------------------------------------------
	// draw mux sector ----------------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_instruction_decode(Info &info) {
	// draw ALU sector ----------------------------------------------------------------------------------------------
		draw_trapezoid(-1150, -635, 200);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "+", Vector2{ -975, -465 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(-2200, -330, -1150, -330, BLACK);
			draw_right_arrow(-1300, -550, -1150, -550, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	
		// draw shift left 2 sector -----------------------------------------------------------------------------------
			draw_circle_lines_ex(-1400, -550, 100, 5.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "Shift", Vector2{ -1455, -610 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "Left 2", Vector2{ -1470, -540 }, 50.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
			// draw line --------------------------------------------------------------------------------------------------
				draw_up_arrow(-1400, 855, -1400, -450, BLACK);
			// draw line --------------------------------------------------------------------------------------------------
		// draw shift left 2 sector -----------------------------------------------------------------------------------
	// draw ALU sector ----------------------------------------------------------------------------------------------

	// draw sign extend sector --------------------------------------------------------------------------------------
		draw_circle_lines_ex(-1400, 955, 100, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Sign", Vector2{ -1445, 895 }, 50.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "Extend", Vector2{ -1480, 965 }, 50.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw line --------------------------------------------------------------------------------------------------
			DrawCircle(-2050, 955, 10, BLACK);
			DrawLineEx(Vector2{ -2050, 955 }, Vector2{ -1500, 955 }, 5.0f, BLACK);
		// draw line --------------------------------------------------------------------------------------------------
	// draw sign extend sector --------------------------------------------------------------------------------------

	// draw Registers sector ----------------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -850, -350, 600, 1150 }, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Registers", Vector2{ -710, 185 }, 70.0f, 3.0f, BLACK);
			// read register 1 --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ReadReg1", Vector2{ -810, -240 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ -800, -180 }, 50.0f, 3.0f, BLACK);
				string	readReg1 = string("$") + to_string(info.ifid.get_instruction().get_rs());
				DrawTextEx(GetFontDefault(), readReg1.c_str(), Vector2{ -750, -180 }, 50.0f, 3.0f, BLACK);
			// read register 1 --------------------------------------------------------------------------------------------------
			// read register 2 --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ReadReg2", Vector2{ -810, -30 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ -800, 30 }, 50.0f, 3.0f, BLACK);
				string	readReg2 = string("$") + to_string(info.ifid.get_instruction().get_rt());
				DrawTextEx(GetFontDefault(), readReg2.c_str(), Vector2{ -750, 30 }, 50.0f, 3.0f, BLACK);
			// read register 2 --------------------------------------------------------------------------------------------------
			// write data -------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "WriteData", Vector2{ -810, 380 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ -800, 430 }, 40.0f, 3.0f, BLACK);
				string	writeData = n2hexstr((info.memwb.get_mem_to_reg() == true) ? info.memwb.get_data_read() : info.memwb.get_alu_result());
				DrawTextEx(GetFontDefault(), writeData.c_str(), Vector2{ -750, 430 }, 40.0f, 3.0f, BLACK);
			// write data -------------------------------------------------------------------------------------------
			// write register -----------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "WriteReg", Vector2{ -810, 580 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ -800, 640 }, 50.0f, 3.0f, BLACK);
				string	writeReg = string("$") + to_string(info.ifid.get_instruction().get_rd());
				DrawTextEx(GetFontDefault(), writeReg.c_str(), Vector2{ -750, 640 }, 50.0f, 3.0f, BLACK);
			// write register -----------------------------------------------------------------------------------------
			// read data 1 -------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ReadData1", Vector2{ -550, -115 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ -550, -65 }, 40.0f, 3.0f, BLACK);
				string	readData1 = n2hexstr(info.registerValues[info.ifid.get_instruction().get_rs()]);
				DrawTextEx(GetFontDefault(), readData1.c_str(), Vector2{ -500, -65 }, 40.0f, 3.0f, BLACK);
			// read data 1 -------------------------------------------------------------------------------------------
			// read data 2 -------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ReadData2", Vector2{ -550, 490 }, 50.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ -550, 540 }, 40.0f, 3.0f, BLACK);
				string	readData2 = n2hexstr(info.registerValues[info.ifid.get_instruction().get_rt()]);
				DrawTextEx(GetFontDefault(), readData2.c_str(), Vector2{ -500, 540 }, 40.0f, 3.0f, BLACK);
			// read data 2 -------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			DrawLineEx(Vector2{ -2200, 430, }, Vector2{ -2050, 430 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -2050, -850 }, Vector2{ -2050, 1400 }, 5.0f, BLACK);
			DrawCircle(-2050, 430, 10.0f, BLACK);
			DrawCircle(-2050, -185, 10.0f, BLACK);
			draw_right_arrow(-2050, -185, -850, -185, BLACK);
			DrawCircle(-2050, 25, 10.0f, BLACK);
			draw_right_arrow(-2050, 25, -850, 25, BLACK);
			draw_right_arrow(-950, 220, -850, 220, BLACK);
			DrawLineEx(Vector2{ 3900, 715 }, Vector2{ 4000, 715 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 4000, 715 }, Vector2{ 4000, 2320 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 4000, 2320 }, Vector2{ -1150, 2320 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -1150, 2320 }, Vector2{ -1150, 425 }, 5.0f, BLACK);
			draw_right_arrow(-1150, 425, -850, 425, BLACK);
			DrawLineEx(Vector2{ 3600, 1220 }, Vector2{ 3700, 1220 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 3700, 1220 }, Vector2{ 3700, 2110 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 3700, 2110 }, Vector2{ -940, 2110 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -940, 2110 }, Vector2{ -940, 635 }, 5.0f, BLACK);
			draw_right_arrow(-940, 635, -850, 635, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
			DrawRectangleRoundedLines(Rectangle{ -100, -180, 50, 150 }, 0.5f, 5, 5, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "M", Vector2{ -88, -165 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "U", Vector2{ -86, -120 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "X", Vector2{ -86, -75 }, 40.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
			// draw lines -------------------------------------------------------------------------------------------------
				draw_down_arrow(-75, -230, -75, -180, BLACK);
				draw_right_arrow(-210, -140, -100, -140, BLACK);
				draw_right_arrow(-250, -70, -100, -70, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
			DrawRectangleRoundedLines(Rectangle{ -100, 495, 50, 150 }, 0.5f, 5, 5, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "M", Vector2{ -88, 510 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "U", Vector2{ -86, 555 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "X", Vector2{ -86, 600 }, 40.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
			// draw lines -------------------------------------------------------------------------------------------------
				draw_right_arrow(-250, 535, -100, 535, BLACK);
				DrawLineEx(Vector2{ 1300, 1703.2 }, Vector2{ -210, 1703.2 }, 5.0f, BLACK);
				DrawLineEx(Vector2{ -210, 1703.2 }, Vector2{ -210, -140 }, 5.0f, BLACK);
				DrawCircle(-210, 605, 10.0f, BLACK);
				draw_right_arrow(-210, 605, -100, 605, BLACK);
				DrawLineEx(1500, 605, -75, 535, 5.0f, BLACK);
				draw_up_arrow(-75, 695, -75, 645, BLACK);
			// draw line --------------------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
		// draw equal sector -------------------------------------------------------------------------------------------
			draw_circle_lines_ex(0, 220, 50, 5.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "=", Vector2{ -20, 175 }, 100.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
			// draw lines -------------------------------------------------------------------------------------------------
				DrawCircle(0, -70, 7.0f, BLACK);
				DrawLineEx(Vector2{ 0, -70 }, Vector2{ 0, 170 }, 5.0f, BLACK);
				DrawCircle(0, 535, 7.0f, BLACK);
				DrawLineEx(Vector2{ 0, 270 }, Vector2{ 0, 535 }, 5.0f, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
		// draw equal sector -------------------------------------------------------------------------------------------
	// draw MEM/WB RegWrite sector ----------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -1200, 145, 250, 150 }, 5.0f, BLUE);
		DrawRectangle(-1200, 145, 250, 150, Fade(BLUE, 0.2f));
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "MEM/WB", Vector2{ -1162, 175 }, 40.0f, 3.0f, BLUE);
			DrawTextEx(GetFontDefault(), "RegWrite", Vector2{ -1161, 225 }, 40.0f, 3.0f, BLUE);
		// draw text --------------------------------------------------------------------------------------------------
	// draw MEM/WB RegWrite sector ----------------------------------------------------------------------------------

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
	(void) info;
	return (true);
}

bool	render_execute(Info &info) {
	// draw mux sector -----------------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 750, -220, 100, 300 }, 1.0f, 0, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "M", Vector2{ 775, -165 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "U", Vector2{ 778, -100 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "X", Vector2{ 778, -35 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(550, -120, 750, -120, BLACK);
			draw_right_arrow(400, -70, 750, -70, BLACK);
			draw_right_arrow(650, -20, 750, -20, BLACK);
			DrawLineEx(Vector2{ 1335, 1570 }, Vector2{ 900, 1570 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 900, 1570 }, Vector2{ 900, 220 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 900, 220 }, Vector2{ 800, 220 }, 5.0f, BLACK);
			draw_up_arrow(800, 220, 800, 80, BLACK);
			DrawCircle(550, 2320, 10.0f, BLACK);
			DrawLineEx(Vector2{ 550, 2320 }, Vector2{ 550, -120 }, 5.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	// draw mux sector -----------------------------------------------------------------------------------------------

	// draw mux sector -----------------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 750, 385, 100, 300 }, 1.0f, 0, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "M", Vector2{ 775, 440 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "U", Vector2{ 778, 505 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "X", Vector2{ 778, 570 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			DrawCircle(550, 485, 10.0f, BLACK);
			draw_right_arrow(550, 485, 750, 485, BLACK);
			draw_right_arrow(400, 535, 750, 535, BLACK);
			DrawCircle(650, 585, 10.0f, BLACK);
			draw_right_arrow(650, 585, 750, 585, BLACK);
			DrawLineEx(Vector2{ 1300, 1636.6 }, Vector2{ 800, 1636.6 }, 5.0f, BLACK);
			draw_up_arrow(800, 1636.6, 800, 685, BLACK);
			DrawCircle(2300, 235, 10.0f, BLACK);
			DrawLineEx(Vector2{ 2300, 235 }, Vector2{ 2300, 2010 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 2300, 2010 }, Vector2{ 650, 2010 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 650, 2010 }, Vector2{ 650, -20 }, 5.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	// draw mux sector -----------------------------------------------------------------------------------------------

	// draw ALU control sector ---------------------------------------------------------------------------------------
		draw_circle_lines_ex(1350, 955, 100, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "ALU", Vector2{ 1315, 910 }, 40.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "Control", Vector2{ 1280, 960 }, 40.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			DrawCircle(1000, 955, 10.0f, BLACK);
			draw_right_arrow(1000, 955, 1250, 955, BLACK);
			draw_down_arrow(1270, 840, 1270, 890, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
		// draw ALU Opcode sector ---------------------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 1110, 720, 180, 120 }, 5.0f, BLUE);
			DrawRectangle(1110, 720, 180, 120, Fade(BLUE, 0.2f));
			// draw text ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ALU", Vector2{ 1165, 740 }, 35.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "Opcode", Vector2{ 1140, 785 }, 35.0f, 3.0f, BLUE);
			// draw text ------------------------------------------------------------------------------------------------
		// draw ALU Opcode sector ---------------------------------------------------------------------------------------
	// draw ALU control sector ---------------------------------------------------------------------------------------

	// draw ALU sector -----------------------------------------------------------------------------------------------
		draw_trapezoid(1250, -115, 350);
		// draw lines --------------------------------------------------------------------------------------------------
			draw_right_arrow(850, -70, 1250, -70, BLACK);
			draw_right_arrow(1210, 450, 1250, 450, BLACK);
		// draw lines --------------------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
			DrawRectangleRoundedLines(Rectangle{ 1150, 325, 60, 250 }, 1.0f, 0, 5.0f, BLACK);
			// draw text ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "M", Vector2{ 1166, 385 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "U", Vector2{ 1168, 435 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "X", Vector2{ 1168, 485 }, 40.0f, 3.0f, BLACK);
			// draw text ------------------------------------------------------------------------------------------------
			// draw lines -----------------------------------------------------------------------------------------------
				draw_down_arrow(1180, 230, 1180, 325, BLACK);
				DrawLineEx(Vector2{ 400, 955 }, Vector2{ 1000, 955 }, 5.0f, BLACK);
				DrawLineEx(Vector2{ 1000, 955 }, Vector2{ 1000, 365 }, 5.0f, BLACK);
				draw_right_arrow(1000, 365, 1150, 365, BLACK);
				draw_right_arrow(850, 535, 1150, 535, BLACK);
				draw_up_arrow(1350, 855, 1350, 555, BLACK);
			// draw lines -----------------------------------------------------------------------------------------------
			// draw ALU source sector ------------------------------------------------------------------------------------
				DrawRectangleLinesEx(Rectangle{ 1000, 90, 200, 140 }, 5.0f, BLUE);
				DrawRectangle(1000, 90, 200, 140, Fade(BLUE, 0.2f));
				// draw text --------------------------------------------------------------------------------------------
					DrawTextEx(GetFontDefault(), "ALU", Vector2{ 1063, 120 }, 40.0f, 3.0f, BLUE);
					DrawTextEx(GetFontDefault(), "Source", Vector2{ 1030, 165 }, 40.0f, 3.0f, BLUE);
				// draw text --------------------------------------------------------------------------------------------
			// draw ALU source sector ------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
	// draw ALU sector -----------------------------------------------------------------------------------------------
	

	// draw mux sector -----------------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 1550, 1095, 100, 250 }, 1.0f, 0, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "M", Vector2{ 1575, 1125 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "U", Vector2{ 1578, 1190 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "X", Vector2{ 1578, 1255 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(400, 1160, 1550, 1160, BLACK);
			draw_right_arrow(400, 1280, 1550, 1280, BLACK);
			draw_down_arrow(1600, 1000, 1600, 1095, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
		// draw ID/EX RegDst sector ------------------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 1500, 860, 200, 140 }, 5.0f, BLUE);
			DrawRectangle(1500, 860, 200, 140, Fade(BLUE, 0.2f));
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "ID/EX", Vector2{ 1538, 885 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "RegDst", Vector2{ 1532, 935 }, 40.0f, 3.0f, BLUE);
			// draw text --------------------------------------------------------------------------------------------------
		// draw ID/EX RegDst sector ------------------------------------------------------------------------------------
	// draw mux sector -----------------------------------------------------------------------------------------------

	(void) info;
	return (true);
}

bool	render_memory_access(Info &info) {
	// draw Data memory sector --------------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ 2650, 65, 500, 800 }, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Data", Vector2{ 2830, 395 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "Memory", Vector2{ 2790, 475 }, 70.0f, 3.0f, BLACK);
			// Address --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "Address", Vector2{ 2680, 195 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ 2690, 245 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), n2hexstr(info.exmem.get_alu_result()).c_str(), Vector2{ 2720, 245 }, 40.0f, 3.0f, BLACK);
			// Address --------------------------------------------------------------------------------------------------
			// Write data ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "Write data", Vector2{ 2680, 660 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "=>", Vector2{ 2690, 710 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), n2hexstr(info.exmem.get_write_data()).c_str(), Vector2{ 2720, 710 }, 40.0f, 3.0f, BLACK);
			// Write data ------------------------------------------------------------------------------------------------
		// draw text --------------------------------------------------------------------------------------------------
		// draw EX/MEM MemRead signal sector ---------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 2670, -140, 225, 140 }, 5.0f, BLUE);
			DrawRectangle(2670, -140, 225, 140, Fade(BLUE, 0.2f));
			// draw text ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "EX/MEM", Vector2{ 2695, -115 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "MemRead", Vector2{ 2695, -65 }, 40.0f, 3.0f, BLUE);
			// draw text ------------------------------------------------------------------------------------------------
		// draw EX/MEM MemRead signal sector ---------------------------------------------------------------------------
		// draw EX/MEM MemWrite signal sector --------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 2905, -140, 225, 140 }, 5.0f, BLUE);
			DrawRectangle(2905, -140, 225, 140, Fade(BLUE, 0.2f));
			// draw text ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "EX/MEM", Vector2{ 2933, -115 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "MemWrite", Vector2{ 2930, -65 }, 40.0f, 3.0f, BLUE);
			// draw text ------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(2100, 235, 2650, 235, BLACK);
			draw_right_arrow(2100, 700, 2650, 700, BLACK);
			draw_down_arrow(2782, 0, 2782, 65, BLACK);
			draw_down_arrow(3017, 0, 3017, 65, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
	// draw Data memory sector --------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_write_back(Info &info) {
	// draw mux sector -----------------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 3800, 390, 100, 650 }, 1.0f, 0, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "M", Vector2{ 3825, 540 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "U", Vector2{ 3828, 680 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "X", Vector2{ 3828, 820 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw MEM/WB MemToReg signal sector --------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 3730, 160, 240, 140 }, 5.0f, BLUE);
			DrawRectangle(3730, 160, 240, 140, Fade(BLUE, 0.2f));
			// draw text ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MEM/WB", Vector2{ 3760, 185 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "MemToReg", Vector2{ 3750, 235 }, 40.0f, 3.0f, BLUE);
			// draw text ------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(3600, 465, 3800, 465, BLACK);
			draw_right_arrow(3600, 965, 3800, 965, BLACK);
			draw_down_arrow(3850, 300, 3850, 390, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------

	(void) info;
	return (true);
}