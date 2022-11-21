#include "../../incs/button.hpp"

Button::Button(void) {
	this->_button		= LoadTexture("./assets/button_next-cycle.png");
	this->_sourceRec	= { 0, 0, (float)this->_button.width, (float)this->_button.height };
	this->_btnBounds	= { (float)screenWidth - (this->_button.width-20), (float)screenHeight - (this->_button.height + 20), (float)this->_button.width, (float)this->_button.height };
	this->_state		= NORMAL;
	this->_btnAction	= false;
}

Button::~Button(void) {
	UnloadTexture(this->_button);
}

ButtonState	Button::getButtonState(void) {
	return (this->_state);
}

bool	Button::setButtonState(void) {
	Vector2	mousePos = GetMousePosition();
	this->_btnAction = false;

	if (CheckCollisionPointRec(mousePos, this->_btnBounds)) {
		
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			this->_state = PRESSED;
		} else {
			this->_state = MOUSE_HOVER;
		}
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			this->_btnAction = true;
		}
	} else {
		this->_state = NORMAL;
	}
	return (bool);
}

bool	Button::setButtonPos(void) {
	if (this->_state == MOUSE_HOVER || this->_state == PRESSED) {
		this->_btnBounds.x = (float)screenWidth - (this->_button.width+20);
	} else {
		this->_btnBounds.x = (float)screenWidth - (this->_button.width-20);
	}
	return (true);
}