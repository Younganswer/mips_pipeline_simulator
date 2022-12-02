#include "../../incs/draw_contents.hpp"
#include "../../incs/shape.hpp"

bool	draw_units(const Info &info);
bool	draw_hazard_unit(const Info &info);
bool	draw_control_unit(const Info &info);
bool	draw_forwarding_unit(const Info &info);

bool	draw_units(const Info &info) {
	draw_hazard_unit(info);
	draw_control_unit(info);
	draw_forwarding_unit(info);
	return (true);
}

bool	draw_hazard_unit(const Info &info) {
	// draw hazard unit sector ------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ -1600, -1700, 500, 300 }, 0.5f, 0, 5.0f, RED);
		DrawRectangleRounded(Rectangle{ -1600, -1700, 500, 300 }, 0.5f, 0, Fade(RED, 0.2f));
		// draw lines -------------------------------------------------------------------------------------------
			DrawLineEx(Vector2{ -2050, -850 }, Vector2{ -2050, -1500 }, 5.0f, RED);
			draw_right_arrow(-2050, -1500, -1600, -1500, RED);
		// draw lines -------------------------------------------------------------------------------------------
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Hazard", Vector2{ -1460, -1650 }, 70.0f, 3.0f, RED);
			DrawTextEx(GetFontDefault(), "detection", Vector2{ -1495, -1570 }, 70.0f, 3.0f, RED);
			DrawTextEx(GetFontDefault(), "unit", Vector2{ -1410, -1500 }, 70.0f, 3.0f, RED);
		// draw text --------------------------------------------------------------------------------------------------
	// draw hazard unit sector ------------------------------------------------------------------------------------


	(void) info;
	return (true);
}

bool	draw_control_unit(const Info &info) {
	// draw control unit sector ------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ -1900, -1100, 300, 500 }, 1.0f, 0, 5.0f, BLUE);
		DrawRectangleRounded(Rectangle{ -1900, -1100, 300, 500 }, 1.0f, 0, Fade(BLUE, 0.2f));
		// draw lines -------------------------------------------------------------------------------------------------
			draw_right_arrow(-2050, -850, -1900, -850, Fade(BLUE, 0.8f));
		// draw lines -------------------------------------------------------------------------------------------------
		// draw text --------------------------------------------------------------------------------------------------
			DrawTextEx(GetFontDefault(), "Control", Vector2{ -1850, -910 }, 60.0f, 3.0f, BLUE);
			DrawTextEx(GetFontDefault(), "unit", Vector2{ -1800, -830 }, 60.0f, 3.0f, BLUE);
		// draw text --------------------------------------------------------------------------------------------------
	// draw control unit sector ------------------------------------------------------------------------------------

	(void) info;
	return (true);
}

bool	draw_forwarding_unit(const Info &info) {
	// draw forwarding unit sector ------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 1300, 1520, 480, 300 }, 1.0f, 0, 5.0f, GOLD);
		DrawRectangleRounded(Rectangle{ 1300, 1520, 480, 300 }, 1.0f, 0, Fade(GOLD, 0.2f));
	// draw forwarding unit sector ------------------------------------------------------------------------------

	// draw text --------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Forwarding", Vector2{ 1370, 1600 }, 70.0f, 3.0f, GOLD);
		DrawTextEx(GetFontDefault(), "unit", Vector2{ 1490, 1690 }, 70.0f, 3.0f, GOLD);
	// draw text --------------------------------------------------------------------------------------------------
	
	(void) info;
	return (true);
}