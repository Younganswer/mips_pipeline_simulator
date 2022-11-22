#include "../../incs/button.hpp"
#include "../../incs/info.hpp"

Button::Button(void) {
	this->_texture		= LoadTexture("./assets/button_next-cycle.png");
	this->_sourceRec	= { 0, 0, (float)this->_texture.width, (float)this->_texture.height };
	this->_btnBounds	= { (float)screenWidth - (this->_texture.width-20), (float)screenHeight - (this->_texture.height + 20), (float)this->_texture.width, (float)this->_texture.height };
	this->_state		= NORMAL;
	this->_action		= false;
}

Button::~Button(void) {
	UnloadTexture(this->_texture);
}

// Getters
Texture2D	Button::getTexture(void) {
	return (this->_texture);
}

Rectangle	Button::getBtnBounds(void) {
	return (this->_btnBounds);
}

Rectangle	Button::getSourceRec(void) {
	return (this->_sourceRec);
}

ButtonState	Button::getState(void) {
	setState();
	return (this->_state);
}

bool	Button::action(void) {
	getState();
	return (this->_action);
}

// Setters
bool	Button::setState(void) {
	Vector2	mousePos = GetMousePosition();
	this->_action = false;

	if (CheckCollisionPointRec(mousePos, this->_btnBounds)) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			this->_state = PRESSED;
		} else {
			this->_state = MOUSE_HOVER;
		}
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			this->_action = true;
		}
	} else {
		this->_state = NORMAL;
	}
	setPos();
	return (true);
}

bool	Button::setPos(void) {
	if (this->_state == MOUSE_HOVER || this->_state == PRESSED) {
		this->_btnBounds.x = (float)screenWidth - (this->_texture.width+20);
	} else {
		this->_btnBounds.x = (float)screenWidth - (this->_texture.width-20);
	}
	return (true);
}