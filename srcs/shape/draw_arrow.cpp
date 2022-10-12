#include "../../incs/shape.hpp"

bool	draw_left_arrow(int startPosX, int startPosY, int endPosX, int endPosY);
bool	draw_right_arrow(int startPosX, int startPosY, int endPosX, int endPosY);
bool	draw_up_arrow(int startPosX, int startPosY, int endPosX, int endPosY);
bool	draw_down_arrow(int startPosX, int startPosY, int endPosX, int endPosY);

bool	draw_left_arrow(int startPosX, int startPosY, int endPosX, int endPosY) {
	DrawLineEx((Vector2){static_cast<float>(startPosX, startPosY)}, (Vector2){static_cast<float>(endPosX, endPosY)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX+ARROW_LENGTH, endPosY+ARROW_LENGTH)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX+ARROW_LENGTH, endPosY-ARROW_LENGTH)}, 2.0f, BLACK);
	return (true);
}

bool	draw_right_arrow(int startPosX, int startPosY, int endPosX, int endPosY) {
	DrawLineEx((Vector2){static_cast<float>(startPosX, startPosY)}, (Vector2){static_cast<float>(endPosX, endPosY)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX-ARROW_LENGTH, endPosY+ARROW_LENGTH)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX-ARROW_LENGTH, endPosY-ARROW_LENGTH)}, 2.0f, BLACK);
	return (true);
}

bool	draw_up_arrow(int startPosX, int startPosY, int endPosX, int endPosY) {
	DrawLineEx((Vector2){static_cast<float>(startPosX, startPosY)}, (Vector2){static_cast<float>(endPosX, endPosY)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX+ARROW_LENGTH, endPosY+ARROW_LENGTH)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX-ARROW_LENGTH, endPosY+ARROW_LENGTH)}, 2.0f, BLACK);
	return (true);
}

bool	draw_down_arrow(int startPosX, int startPosY, int endPosX, int endPosY) {
	DrawLineEx((Vector2){static_cast<float>(startPosX, startPosY)}, (Vector2){static_cast<float>(endPosX, endPosY)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX+ARROW_LENGTH, endPosY-ARROW_LENGTH)}, 2.0f, BLACK);
	DrawLineEx((Vector2){static_cast<float>(endPosX, endPosY)}, (Vector2){static_cast<float>(endPosX-ARROW_LENGTH, endPosY-ARROW_LENGTH)}, 2.0f, BLACK);
	return (true);
}