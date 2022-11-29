#include "../../incs/window.hpp"

bool	draw_window(Info &info) {
	draw_camera_sight(info);
    draw_guide();
	DrawTextureRec(info.button.get_texture(), info.button.get_source_rec(), (Vector2){ info.button.get_btn_bounds().x, info.button.get_btn_bounds().y }, WHITE);
	draw_edge();
	return (true);
}