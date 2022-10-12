#include "../../incs/shape.hpp"

bool	draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY);
bool	draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY);
bool	draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY);
bool	draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY);

bool	draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, BLACK);
	return (true);
}

bool	draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, BLACK);
	return (true);
}

bool	draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY+ARROW_LENGTH}, 3.0f, BLACK);
	return (true);
}

bool	draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY) {
	DrawLineEx((Vector2){startPosX-3000, startPosY}, (Vector2){endPosX-3000, endPosY}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000+ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, BLACK);
	DrawLineEx((Vector2){endPosX-3000, endPosY}, (Vector2){endPosX-3000-ARROW_LENGTH, endPosY-ARROW_LENGTH}, 3.0f, BLACK);
	return (true);
}