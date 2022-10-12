#include "../../incs/window.hpp"

bool	draw_camera_sight(Info &info) {
	int	posX	= (int)info.camera.target.x;
	int	posY	= (int)info.camera.target.y;
	int	offsetY	= -90;
	BeginMode2D(info.camera);
		DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
		for (auto iter=info.all_instructions.begin(); iter!=info.all_instructions.end(); iter++) {
			const char	*cur_str = iter->instruction.c_str();
			DrawText(cur_str, posX-strlen(cur_str)*6, posY+offsetY, 20, RED);
			offsetY += 30;
		}
		DrawLine(posX, posY-screenHeight*5, posX, posY+screenHeight*5, GREEN);
		DrawLine(posX-screenWidth*5, posY, posX+screenWidth*5, posY, GREEN);
	EndMode2D();
	return (true);
}