#include "../../incs/mouse.hpp"

bool	handling_mouse(int &mouse_clicked) {
	if (!mouse_clicked && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		mouse_clicked = 120;
	if (0 < mouse_clicked) {
		DrawText("Mouse clicked!", screenWidth/2 - 67, screenHeight/2 - 40, 20, RED);
		mouse_clicked--;
	}
	return (true);
}