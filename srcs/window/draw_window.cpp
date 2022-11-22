#include "../../incs/window.hpp"

bool	draw_window(Info &info) {
	draw_camera_sight(info);
    draw_guide();
	DrawTextureRec(info.button.getTexture(), info.button.getSourceRec(), (Vector2){ info.button.getBtnBounds().x, info.button.getBtnBounds().y }, WHITE);
	draw_edge();
	return (true);
}