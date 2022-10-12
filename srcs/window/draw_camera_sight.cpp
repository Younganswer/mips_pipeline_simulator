#include "../../incs/shape.hpp"
#include "../../incs/window.hpp"

bool	draw_camera_sight(Info &info) {
	int	posX	= (int)info.camera.target.x;
	int	posY	= (int)info.camera.target.y;
	int	offsetY	= -180;
	
	BeginMode2D(info.camera);
		
		DrawRectangle(-8000, -8000, 16000, 16000, LIGHTGRAY);
		for (auto iter=info.all_instructions.begin(); iter!=info.all_instructions.end(); iter++) {
			const char	*cur_str = iter->instruction.c_str();
			DrawText(cur_str, posX-strlen(cur_str)*15, posY+offsetY, 20, RED);
			offsetY += 30;
		}
		DrawLine(posX, posY-screenHeight*5, posX, posY+screenHeight*5, GREEN);
		DrawLine(posX-screenWidth*5, posY, posX+screenWidth*5, posY, GREEN);
		if (!info.button.btnClicked && info.button.btnAction) {
			info.button.btnClicked = 120;
		}
		if (info.button.btnClicked) {
			DrawText("Button Clicked!", posX-145, posY-40, 40, RED);
			info.button.btnClicked--;
		}
		DrawEllipse(-3000+50, 430, 30, 60, WHITE);
		DrawText("0", -3000+46, 400, 20, BLACK);
		DrawText("1", -3000+47, 450, 20, BLACK);
		draw_right_arrow(-3000+80, 430, -3000+130, 430);

	EndMode2D();
	return (true);
}