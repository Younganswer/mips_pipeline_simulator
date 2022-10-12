#include "../../incs/window.hpp"

bool	draw_edge(void) {
	DrawText("SCREEN AREA", screenWidth - 200, 10, 20, RED);
    DrawRectangle(0, 0, screenWidth, 5, RED);
    DrawRectangle(0, 5, 5, screenHeight - 10, RED);
    DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED);
    DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);
	return (true);
}