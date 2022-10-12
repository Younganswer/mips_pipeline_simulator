#include "../../incs/window.hpp"

bool	draw_window(Info &info) {
	draw_camera_sight(info);
    draw_guide();
	DrawTextureRec(info.button.button, info.button.sourceRec, (Vector2){ info.button.btnBounds.x, info.button.btnBounds.y }, WHITE);
	draw_edge();
	return (true);
}