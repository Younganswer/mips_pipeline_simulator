#include "../../incs/window.hpp"

bool	draw_window(Camera2D &camera) {
	BeginMode2D(camera);
		DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
		DrawLine((int)camera.target.x, (int)camera.target.y-screenHeight*5, (int)camera.target.x, (int)camera.target.y+screenHeight*5, GREEN);
		DrawLine((int)camera.target.x-screenWidth*5, (int)camera.target.y, (int)camera.target.x+screenWidth*5, (int)camera.target.y, GREEN);
	EndMode2D();
	return (true);
}