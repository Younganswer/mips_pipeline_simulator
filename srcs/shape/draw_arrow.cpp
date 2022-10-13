#include "../../incs/shape.hpp"

bool	draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
bool	draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
bool	draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
bool	draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);

bool	draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, color);
	return (true);
}

bool	draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, color);
	return (true);
}

bool	draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, color);
	return (true);
}

bool	draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, color);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, color);
	return (true);
}