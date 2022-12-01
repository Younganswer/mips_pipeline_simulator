#include "../../incs/draw_contents.hpp"

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
		DrawRectangleRoundedLines(Rectangle{ -1600, -1550, 500, 300 }, 0.3f, 0, 5.0f, RED);
	// draw hazard unit sector ------------------------------------------------------------------------------------

	// draw text --------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Hazard", Vector2{ -1460, -1510 }, 70.0f, 3.0f, RED);
		DrawTextEx(GetFontDefault(), "detection", Vector2{ -1495, -1430 }, 70.0f, 3.0f, RED);
		DrawTextEx(GetFontDefault(), "unit", Vector2{ -1410, -1360 }, 70.0f, 3.0f, RED);
	// draw text --------------------------------------------------------------------------------------------------

	(void) info;
	return (true);
}

bool	draw_control_unit(const Info &info) {
	// draw control unit sector ------------------------------------------------------------------------------------
		DrawPolyLinesEx(Vector2{ -1600, -1000 }, 5, 500, 300, 0.3f, RED);
	// draw control unit sector ------------------------------------------------------------------------------------
	(void) info;
	return (true);
}

bool	draw_forwarding_unit(const Info &info) {
	// draw forwarding unit sector ------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 1300, 1520, 480, 300 }, 1.0f, 0, 5.0f, BLUE);
	// draw forwarding unit sector ------------------------------------------------------------------------------

	// draw text --------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Forwarding", Vector2{ 1370, 1600 }, 70.0f, 3.0f, BLUE);
		DrawTextEx(GetFontDefault(), "unit", Vector2{ 1490, 1690 }, 70.0f, 3.0f, BLUE);
	// draw text --------------------------------------------------------------------------------------------------
	
	(void) info;
	return (true);
}