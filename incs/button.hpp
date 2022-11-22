#ifndef BUTTON_HPP
# define BUTTON_HPP

# include "../raylib/src/raylib.h"

typedef enum _ButtonState {
	NORMAL		= 0,
	MOUSE_HOVER	= 1,
	PRESSED		= 2
}	ButtonState;

class Button {
	private:
		Texture2D	_texture;
		Rectangle	_btnBounds;
		Rectangle	_sourceRec;
		ButtonState	_state;
		bool		_action;

		// Setters
		bool	setState(void);
		bool	setPos(void);

	public:
		Button(void);
		~Button(void);

		// Getters
		Texture2D	getTexture(void);
		Rectangle	getBtnBounds(void);
		Rectangle	getSourceRec(void);
		ButtonState	getState(void);
		bool		action(void);
};

#endif