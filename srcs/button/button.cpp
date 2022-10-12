#include "../../incs/button.hpp"

bool	init_button(Button &button) {
	button.button		= LoadTexture("./assets/button_next-cycle.png");
	button.sourceRec	= { 0, 0, (float)button.button.width, (float)button.button.height };
	button.btnBounds	= { (float)screenWidth - (button.button.width-20), (float)screenHeight - (button.button.height + 20), (float)button.button.width, (float)button.button.height };
	button.state		= NORMAL;
	button.btnAction	= false;
	button.btnClicked	= 0;
	return (true);
}

bool	handling_button(Info &info) {
	info.mouse = GetMousePosition();
	info.button.btnAction = false;

	if (CheckCollisionPointRec(info.mouse, info.button.btnBounds)) {
		info.button.btnBounds.x = (float)screenWidth - (info.button.button.width+20);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			info.button.state = PRESSED;
		} else {
			info.button.state = MOUSE_HOVER;
		}
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			info.button.btnAction = true;
		}
	} else {
		info.button.state = NORMAL;
		info.button.btnBounds.x = (float)screenWidth - (info.button.button.width-20);
	}
	return (true);
}