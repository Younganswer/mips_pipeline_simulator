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
		Texture2D	_button;
		Rectangle	_btnBounds;
		Rectangle	_sourceRec;
		ButtonState	_state;
		bool		_btnAction;

	public:
		Button(void);
		~Button(void);

		// Getters
		ButtonState	getButtonState(void);

		// Setters
		bool	setButtonState(void);
		bool	setButtonPos(void);
};

#endif