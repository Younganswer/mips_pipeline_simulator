#include "../../incs/draw_contents.hpp"

bool	draw_forwarding_unit(const Info &info);

bool	draw_forwarding_unit(const Info &info) {
	(void) info;

	// draw forwarding unit sector ------------------------------------------------------------------------------
		DrawRectangleRoundedLines(Rectangle{ 1300, 1520, 480, 300 }, 1.0f, 0, 5.0f, BLUE);
	// draw forwarding unit sector ------------------------------------------------------------------------------

	// draw text --------------------------------------------------------------------------------------------------
		DrawTextEx(GetFontDefault(), "Forwarding", Vector2{ 1370, 1600 }, 70.0f, 3.0f, BLUE);
		DrawTextEx(GetFontDefault(), "unit", Vector2{ 1490, 1690 }, 70.0f, 3.0f, BLUE);
	// draw text --------------------------------------------------------------------------------------------------
	return (true);
}