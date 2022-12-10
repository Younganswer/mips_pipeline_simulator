#include "../../incs/button.hpp"
#include "../../incs/info.hpp"

Button::Button(void) {
	this->texture		= LoadTexture("./assets/button_next-cycle.png");
	this->sourceRec		= { 0, 0, (float)this->texture.width, (float)this->texture.height };
	this->btnBounds		= { (float)screenWidth - (this->texture.width-20), (float)screenHeight - (this->texture.height + 20), (float)this->texture.width, (float)this->texture.height };
	this->state			= NORMAL;
	this->isActioned	= false;
	this->cycle			= 0;
}

Button::~Button(void) { UnloadTexture(this->texture); }

// Getters
Texture2D	Button::get_texture(void) { return (this->texture); }
Rectangle	Button::get_btn_bounds(void) { return (this->btnBounds); }
Rectangle	Button::get_source_rec(void) { return (this->sourceRec); }
ButtonState	Button::get_state(void) { set_state(); return (this->state); }
bool		Button::is_actioned(void) { get_state(); return (this->isActioned); }
size_t		Button::get_cycle(void) { return (this->cycle); }

// Setters
bool	Button::set_state(void) {
	Vector2	mousePos = GetMousePosition();
	this->isActioned = false;

	if (CheckCollisionPointRec(mousePos, this->btnBounds)) {
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			this->state = PRESSED;
		} else {
			this->state = MOUSE_HOVER;
		}
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			this->isActioned = true;
		}
	} else {
		this->state = NORMAL;
	}
	if (this->isActioned) {
		this->cycle++;
	}
	set_pos();
	return (true);
}

bool	Button::set_pos(void) {
	if (this->state == MOUSE_HOVER || this->state == PRESSED) {
		this->btnBounds.x = (float)screenWidth - (this->texture.width+20);
		this->btnBounds.width = (float)this->texture.width + 20;
	} else {
		this->btnBounds.x = (float)screenWidth - (this->texture.width-20);
		this->btnBounds.width = (float)this->texture.width - 20;
	}
	return (true);
}