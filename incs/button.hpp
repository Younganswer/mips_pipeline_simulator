#ifndef BUTTON_HPP
# define BUTTON_HPP

# include "../libs/raylib/src/raylib.h"

typedef enum _ButtonState {
	NORMAL		= 0,
	MOUSE_HOVER	= 1,
	PRESSED		= 2
}	ButtonState;

class Button {
	private:
		Texture2D	texture;
		Rectangle	btnBounds;
		Rectangle	sourceRec;
		ButtonState	state;
		bool		isActioned;

		// Setters
		bool	set_state(void);
		bool	set_pos(void);

	public:
		Button(void);
		~Button(void);

		// Getters
		Texture2D	get_texture(void);
		Rectangle	get_btn_bounds(void);
		Rectangle	get_source_rec(void);
		ButtonState	get_state(void);
		bool		action(void);
};

#endif