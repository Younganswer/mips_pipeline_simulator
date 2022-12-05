#include "../../incs/info.hpp"
#include "../../incs/shape.hpp"
#include "../../incs/render.hpp"
#include "../../incs/update.hpp"
#include <iostream>

int	btnClicked = 0;

bool	render_camera_sight(Info &info) {
	int	posX	= (int)info.camera.target.x;
	int	posY	= (int)info.camera.target.y;
	int	offsetY	= -180;
	
	BeginMode2D(info.camera);
		
		// check instruction --------------------------------------------------------------------------
			for (auto iter=info.instructions.begin(); iter!=info.instructions.end(); iter++) {
				string	cur_str = iter->get_asm_string();
				cur_str += " " + to_string(iter->get_opcode());
				if (iter->get_format() == R) {
					cur_str += " " + to_string(iter->get_rs());
					cur_str += " " + to_string(iter->get_rt());
					cur_str += " " + to_string(iter->get_rd());
					cur_str += " " + to_string(iter->get_shamt());
					cur_str += " " + to_string(iter->get_funct());
				} else if (iter->get_format() == I) {
					cur_str += " " + to_string(iter->get_rs());
					cur_str += " " + to_string(iter->get_rt());
					cur_str += " " + to_string(iter->get_imm());
				} else if (iter->get_format() == J) {
					cur_str += " " + to_string(iter->get_imm());
				}
				DrawText(cur_str.c_str(), posX-500, posY+offsetY, 20, RED);
				offsetY += 30;
			}
		// check instruction -------------------------------------------------------------------------

		// cross line --------------------------------------------------------------------------------
			DrawLine(posX, posY-screenHeight*5, posX, posY+screenHeight*5, GREEN);
			DrawLine(posX-screenWidth*5, posY, posX+screenWidth*5, posY, GREEN);
		// cross line --------------------------------------------------------------------------------
		
		// render contents -----------------------------------------------------------------------------
			render_contents(info);
		// render contents -----------------------------------------------------------------------------

	EndMode2D();
	return (true);
}