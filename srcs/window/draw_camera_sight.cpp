#include "../../incs/info.hpp"
#include "../../incs/shape.hpp"
#include "../../incs/window.hpp"
#include <iostream>

int	btnClicked = 0;

bool	draw_camera_sight(Info &info) {
	int	posX	= (int)info.camera.target.x;
	int	posY	= (int)info.camera.target.y;
	int	offsetY	= -180;
	
	BeginMode2D(info.camera);
		
		// check instruction --------------------------------------------------------------------------
			for (auto iter=info.instructions.begin(); iter!=info.instructions.end(); iter++) {
				string	cur_str = iter->getAsm();
				cur_str += " " + to_string(iter->getOpcode());
				if (iter->getFormat() == R) {
					cur_str += " " + to_string(iter->getRs());
					cur_str += " " + to_string(iter->getRt());
					cur_str += " " + to_string(iter->getRd());
					cur_str += " " + to_string(iter->getShamt());
					cur_str += " " + to_string(iter->getFunct());
				} else if (iter->getFormat() == I) {
					cur_str += " " + to_string(iter->getRs());
					cur_str += " " + to_string(iter->getRt());
					cur_str += " " + to_string(iter->getImm());
				} else if (iter->getFormat() == J) {
					cur_str += " " + to_string(iter->getImm());
				}
				DrawText(cur_str.c_str(), posX-500, posY+offsetY, 20, RED);
				offsetY += 30;
			}
		// check instruction --------------------------------------------------------------------------

		// cross line --------------------------------------------------------------------------------
			DrawLine(posX, posY-screenHeight*5, posX, posY+screenHeight*5, GREEN);
			DrawLine(posX-screenWidth*5, posY, posX+screenWidth*5, posY, GREEN);
		// cross line --------------------------------------------------------------------------------
		
		// check mouse click -------------------------------------------------------------------------
			if (info.button.action() && btnClicked == 0) {
				btnClicked = 64 * 3;
			}
			if (0 < btnClicked) {
				DrawText("Button Clicked!", posX-145, posY-40, 40, RED);
				btnClicked--;
			}
		// check mouse click -------------------------------------------------------------------------
		
		draw_content();

	EndMode2D();
	return (true);
}