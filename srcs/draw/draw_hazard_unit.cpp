#include "../../incs/draw_contents.hpp"

bool	draw_hazard_unit(const Info &info);

bool	draw_hazard_unit(const Info &info) {
	(void) info;
	
	// draw hazard unit sector ------------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ -1600, -1550, 500, 300 }, 0.3f, 0, 5.0f, RED);
	// draw hazard unit sector ------------------------------------------------------------------------------------

	// draw text --------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Hazard", Vector2{ -1460, -1510 }, 70.0f, 3.0f, RED);
		DrawTextEx(GetFontDefault(), "detection", Vector2{ -1495, -1430 }, 70.0f, 3.0f, RED);
		DrawTextEx(GetFontDefault(), "unit", Vector2{ -1410, -1360 }, 70.0f, 3.0f, RED);
	// draw text --------------------------------------------------------------------------------------------------
	return (true);
}