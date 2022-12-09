#include "../../incs/render.hpp"
#include "../../incs/shape.hpp"

bool	render_units(Info &info);
bool	render_hazard_unit(Info &info);
bool	render_control_unit(Info &info);
bool	render_forwarding_unit(Info &info);
bool	render_jump_unit(Info &info);

bool	render_units(Info &info) {
	render_hazard_unit(info);
	render_control_unit(info);
	render_forwarding_unit(info);
	render_jump_unit(info);
	return (true);
}

bool	render_hazard_unit(Info &info) {
	// draw hazard unit sector ------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ -1600, -1700, 500, 300 }, 0.5f, 0, 5.0f, RED);
		DrawRectangleRounded(Rectangle{ -1600, -1700, 500, 300 }, 0.5f, 0, Fade(RED, 0.2f));
		// draw lines -------------------------------------------------------------------------------------------
		DrawCircleSector(Vector2{ -2050, -850 }, 10.0f, 135.0f, 315.0f, 0, RED);
			DrawLineEx(Vector2{ -2050, -850 }, Vector2{ -2050, -1500 }, 5.0f, RED);
			draw_right_arrow(-2050, -1500, -1600, -1500, RED);
			DrawCircle(600, -985, 10.0f, RED);
			DrawLineEx(Vector2{ 600, -985 }, Vector2{ 600, -1550 }, 5.0f, RED);
			draw_left_arrow(600, -1550, -1100, -1550, RED);
		// draw lines -------------------------------------------------------------------------------------------
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Hazard", Vector2{ -1460, -1660 }, 70.0f, 3.0f, RED);
			DrawTextEx(GetFontDefault(), "detection", Vector2{ -1495, -1580 }, 70.0f, 3.0f, RED);
			DrawTextEx(GetFontDefault(), "unit", Vector2{ -1410, -1500 }, 70.0f, 3.0f, RED);
		// draw text --------------------------------------------------------------------------------------------------
	// draw hazard unit sector ------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_control_unit(Info &info) {
	// draw control unit sector ------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ -1900, -1100, 300, 500 }, 1.0f, 0, 5.0f, BLUE);
		DrawRectangleRounded(Rectangle{ -1900, -1100, 300, 500 }, 1.0f, 0, Fade(BLUE, 0.2f));
		// draw lines -------------------------------------------------------------------------------------------------
			DrawCircleSector(Vector2{ -2050, -850 }, 10.0f, -45.0f, 135.0f, 0, BLUE);
			draw_right_arrow(-2050, -850, -1900, -850, Fade(BLUE, 0.8f));
		// draw lines -------------------------------------------------------------------------------------------------
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Control", Vector2{ -1850, -925 }, 60.0f, 3.0f, BLUE);
			DrawTextEx(GetFontDefault(), "unit", Vector2{ -1800, -845 }, 60.0f, 3.0f, BLUE);
		// draw text --------------------------------------------------------------------------------------------------
	// draw control unit sector ------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_forwarding_unit(Info &info) {
	// draw forwarding unit sector ------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 1300, 1520, 480, 300 }, 1.0f, 0, 5.0f, GOLD);
		DrawRectangleRounded(Rectangle{ 1300, 1520, 480, 300 }, 1.0f, 0, Fade(GOLD, 0.2f));
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Forwarding", Vector2{ 1370, 1600 }, 70.0f, 3.0f, GOLD);
			DrawTextEx(GetFontDefault(), "unit", Vector2{ 1490, 1690 }, 70.0f, 3.0f, GOLD);
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			DrawLineEx(Vector2{ 400, 1400 }, Vector2{ 725, 1400 }, 5.0f, GOLD);
			DrawLineEx(Vector2{ 725, 1400 }, Vector2{ 725, 1770 }, 5.0f, GOLD);
			draw_right_arrow(725, 1770, 1335, 1770, GOLD);
			DrawCircle(1450, 1160, 10.0f, GOLD);
			draw_down_arrow(1450, 1160, 1450, 1520, GOLD);
			draw_left_arrow(1870, 1590, 1760, 1590, GOLD);
			draw_left_arrow(1870, 1750, 1760, 1750, GOLD);
			DrawCircle(2200, 1220, 10, GOLD);
			DrawLineEx(Vector2{ 2200, 1220 }, Vector2{ 2200, 1910 }, 5.0f, GOLD);
			DrawLineEx(Vector2{ 2200, 1910 }, Vector2{ 1660, 1910 }, 5.0f, GOLD);
			draw_up_arrow(1660, 1910, 1660, 1820, GOLD);
			DrawCircle(1580, 2110, 10, GOLD);
			draw_up_arrow(1580, 2110, 1580, 1820, GOLD);
		// draw lines -------------------------------------------------------------------------------------------------
		// draw EX/MEM RegWrite sector -------------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 1870, 1515, 250, 150 }, 5.0f, BLUE);
			DrawRectangle(1870, 1515, 250, 150, Fade(BLUE, 0.2f));
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "EX/MEM", Vector2{ 1906, 1545 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{ 1905, 1600 }, 40.0f, 3.0f, BLUE);
			// draw text --------------------------------------------------------------------------------------------------
		// draw EX/MEM RegWrite sector -------------------------------------------------------------------------------
		// draw MEM/WB RegWrite sector -------------------------------------------------------------------------------
			DrawRectangleLinesEx(Rectangle{ 1870, 1685, 250, 150 }, 5.0f, BLUE);
			DrawRectangle(1870, 1685, 250, 150, Fade(BLUE, 0.2f));
			// draw text --------------------------------------------------------------------------------------------------
				DrawTextEx(GetFontDefault(), "MEM/WB", Vector2{ 1905, 1715 }, 40.0f, 3.0f, BLUE);
				DrawTextEx(GetFontDefault(), "RegWrite", Vector2{ 1905, 1770 }, 40.0f, 3.0f, BLUE);
			// draw text --------------------------------------------------------------------------------------------------
		// draw MEM/WB RegWrite sector -------------------------------------------------------------------------------
	// draw forwarding unit sector ------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	render_jump_unit(Info &info) {
	// draw jump unit sector ---------------------------------------------------------------------------------------
		draw_circle_lines_ex(-2800, -750, 100, 5.0f, Fade(LIME, 0.2f));
		DrawCircle(-2800, -750, 100.0f, Fade(LIME, 0.05f));
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Jump", Vector2{ -2870, -820 }, 70.0f, 3.0f, Fade(LIME, 0.8f));
			DrawTextEx(GetFontDefault(), "unit", Vector2{ -2850, -740 }, 70.0f, 3.0f, Fade(LIME, 0.8f));
		// draw text --------------------------------------------------------------------------------------------------
		// draw lines -------------------------------------------------------------------------------------------------
			DrawCircle(-2050, -800, 10.0f, Fade(LIME, 0.8f));
			draw_left_arrow(-2050, -800, -2710, -800, Fade(LIME, 0.8f));

			DrawCircle(-2125, -330, 10.0f, Fade(LIME, 0.8f));
			DrawLineEx(Vector2{ -2125, -330 }, Vector2{ -2125, -700 }, 5.0f, Fade(LIME, 0.8f));
			draw_left_arrow(-2125, -700, -2710, -700, Fade(LIME, 0.8f));
		// draw lines -------------------------------------------------------------------------------------------------
	// draw jump unit sector ---------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

