#include "../../incs/render.hpp"
#include "../../incs/shape.hpp"

bool	render_instruction_fetch(const Info &info);
bool	render_instruction_decode(const Info &info);
bool	render_execute(const Info &info);
bool	render_memory_access(const Info &info);
bool	render_write_back(const Info &info);

bool	render_instruction_fetch(const Info &info) {
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
			draw_down_arrow(-3800, -150, -3800, -30, BLACK);
			draw_right_arrow(-4000, 70, -3850, 70, BLACK);
			DrawLineEx(Vector2{ -4000, 70 }, Vector2{ -4000, -600 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -4000, -600 }, Vector2{ -2635, -600 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -2635, -600 }, Vector2{ -2635, -330 }, 5.0f, BLACK);
			DrawCircle(-2635, -330, 10.0f, BLACK);
			
			draw_right_arrow(-4100, 170, -3850, 170, BLACK);
			DrawLineEx(Vector2{ -4100, 170 }, Vector2{ -4100, -1250 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -4100, -1250 }, Vector2{ -765, -1250 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -765, -1250 }, Vector2{ -765, -435 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -765, -435 }, Vector2{ -912, -435 }, 5.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
		// draw and gate sector ----------------------------------------------------------------------------------------
			draw_circle_sector_lines_ex(-3800, -250, 100, -90, 90, 0, 5.0f, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
				DrawLineEx(Vector2{ -50, 220 }, Vector2{ -150, 220 }, 5.0f, BLACK);
				DrawLineEx(Vector2{ -150, 220 }, Vector2{ -150, -1175 }, 5.0f, BLACK);
				DrawLineEx(Vector2{ -150, -1175 }, Vector2{ -3855, -1175 }, 5.0f, BLACK);
				draw_down_arrow(-3855, -1175, -3855, -250, BLACK);
				draw_down_arrow(-3745, -400, -3745, -250, BLACK);
			// draw lines -------------------------------------------------------------------------------------------------
		// draw and gate sector ----------------------------------------------------------------------------------------
	// draw mux sector ----------------------------------------------------------------------------------------------

	// draw Branch sector -------------------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ -3810, -550, 200, 150 }, 5.0f, BLUE);
		DrawRectangle(-3810, -550, 200, 150, Fade(BLUE, 0.2f));
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "ID/EX", Vector2{ -3770, -520 }, 40.0f, 3.0f, BLUE);
			DrawTextEx(GetFontDefault(), "Branch", Vector2{ -3780, -470 }, 40.0f, 3.0f, BLUE);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines --------------------------------------------------------------------------------------------------
			DrawLineEx(Vector2{ -1900, -950 }, Vector2{ -3710, -950 }, 5.0f, BLUE);
			draw_down_arrow(-3710, -950, -3710, -550, BLUE);
		// draw lines --------------------------------------------------------------------------------------------------
	// draw Branch sector -------------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_instruction_decode(const Info &info) {
	// draw ALU sector ----------------------------------------------------------------------------------------------
		draw_trapezoid(-1150, -635, 200);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "+", Vector2{ -975, -465 }, 70.0f, 3.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(-2200, -320, -1150, -320, BLACK);
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
		DrawRectangleLinesEx(Rectangle{ -850, -250, 600, 950 }, 5.0f, BLACK);
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Registers", Vector2{ -710, 185 }, 70.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "ReadReg1", Vector2{ -810, -210 }, 50.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "ReadData1", Vector2{ -530, -95 }, 50.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "ReadReg2", Vector2{ -810, 0 }, 50.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "WriteReg", Vector2{ -810, 400 }, 50.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "ReadData2", Vector2{ -540, 510 }, 50.0f, 3.0f, BLACK);
			DrawTextEx(GetFontDefault(), "WriteData", Vector2{ -810, 610 }, 50.0f, 3.0f, BLACK);
		// draw lines -------------------------------------------------------------------------------------------------
			DrawLineEx(Vector2{ -2200, 430, }, Vector2{ -2050, 430 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ -2050, -850 }, Vector2{ -2050, 1400 }, 5.0f, BLACK);
			DrawCircle(-2050, 430, 10.0f, BLACK);
			DrawCircle(-2050, -185, 10.0f, BLACK);
			draw_right_arrow(-2050, -185, -850, -185, BLACK);
			DrawCircle(-2050, 25, 10.0f, BLACK);
			draw_right_arrow(-2050, 25, -850, 25, BLACK);
			draw_right_arrow(-950, 220, -850, 220, BLACK);
			draw_right_arrow(-1150, 425, -850, 425, BLACK);
			draw_right_arrow(-940, 635, -850, 635, BLACK);
			// TODO: draw more lines
		// draw lines -------------------------------------------------------------------------------------------------
		// draw equal sector -------------------------------------------------------------------------------------------
			draw_circle_lines_ex(0, 220, 50, 5.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "=", Vector2{ -20, 175 }, 100.0f, 3.0f, BLACK);
			// draw text --------------------------------------------------------------------------------------------------
			// draw lines -------------------------------------------------------------------------------------------------
				DrawLineEx(Vector2{ 0, -70 }, Vector2{ 0, 170 }, 5.0f, BLACK);
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

bool	render_execute(const Info &info) {
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
			DrawLineEx(Vector2{ 1300, 1670 }, Vector2{ 800, 1670 }, 5.0f, BLACK);
			draw_up_arrow(800, 1670, 800, 685, BLACK);
			DrawLineEx(Vector2{ 550, -120 }, Vector2{ 550, 3000 }, 5.0f, BLACK);
			DrawLineEx(Vector2{ 650, -20 }, Vector2{ 650, 3000 }, 5.0f, BLACK);
	
	// draw ALU sector -----------------------------------------------------------------------------------------------
		draw_trapezoid(1250, -115, 350);
		// draw lines --------------------------------------------------------------------------------------------------
			draw_right_arrow(850, -70, 1250, -70, BLACK);
			draw_right_arrow(1210, 450, 1250, 450, BLACK);
			draw_down_arrow(1600, -100, 1600, 0, BLACK);
		// draw lines --------------------------------------------------------------------------------------------------
		// draw mux sector --------------------------------------------------------------------------------------------
			DrawRectangleRoundedLines(Rectangle{ 1150, 325, 60, 250 }, 1.0f, 0, 5.0f, BLACK);
			// draw text ------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "M", Vector2{ 1166, 385 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "U", Vector2{ 1168, 435 }, 40.0f, 3.0f, BLACK);
				DrawTextEx(GetFontDefault(), "X", Vector2{ 1168, 485 }, 40.0f, 3.0f, BLACK);
			// draw text ------------------------------------------------------------------------------------------------
			// draw lines -----------------------------------------------------------------------------------------------
				DrawLineEx(Vector2{ 400, 955 }, Vector2{ 1000, 955 }, 5.0f, BLACK);
				DrawLineEx(Vector2{ 1000, 955 }, Vector2{ 1000, 365 }, 5.0f, BLACK);
				draw_right_arrow(1000, 365, 1150, 365, BLACK);
				draw_right_arrow(850, 535, 1150, 535, BLACK);
				draw_down_arrow(1180, 230, 1180, 325, BLACK);
			// draw lines -----------------------------------------------------------------------------------------------
			// draw ALU source sector ------------------------------------------------------------------------------------
				DrawRectangleLinesEx(Rectangle{ 1000, 80, 200, 150 }, 5.0f, BLUE);
				DrawRectangle(1000, 80, 200, 150, Fade(BLUE, 0.2f));
				// draw text --------------------------------------------------------------------------------------------
					DrawTextEx(GetFontDefault(), "ALU", Vector2{ 1060, 115 }, 40.0f, 3.0f, BLUE);
					DrawTextEx(GetFontDefault(), "Source", Vector2{ 1030, 160 }, 40.0f, 3.0f, BLUE);
				// draw text --------------------------------------------------------------------------------------------
			// draw ALU source sector ------------------------------------------------------------------------------------
	// draw ALU sector -----------------------------------------------------------------------------------------------
	
	// draw ALU Opcode sector ---------------------------------------------------------------------------------------
		DrawRectangleLinesEx(Rectangle{ 1500, -250, 200, 150 }, 5.0f, BLUE);
		DrawRectangle(1500, -250, 200, 150, Fade(BLUE, 0.2f));
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "ALU", Vector2{ 1565, -220 }, 40.0f, 3.0f, BLUE);
			DrawTextEx(GetFontDefault(), "Opcode", Vector2{ 1530, -170 }, 40.0f, 3.0f, BLUE);
		// draw text --------------------------------------------------------------------------------------------------
	// draw ALU Opcode sector ---------------------------------------------------------------------------------------

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
				DrawTextEx(GetFontDefault(), "ID/EX", Vector2{ 1537, 885 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "RegDst", Vector2{ 1532, 935 }, 40.0f, 3.0f, BLUE);
			// draw text --------------------------------------------------------------------------------------------------
		// draw ID/EX RegDst sector ------------------------------------------------------------------------------------
	// draw mux sector -----------------------------------------------------------------------------------------------

	(void) info;
	return (true);
}

bool	render_memory_access(const Info &info) {
	(void) info;
	return (true);
}

bool	render_write_back(const Info &info) {
	(void) info;
	return (true);
}