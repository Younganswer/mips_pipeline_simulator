#include "../../incs/window.hpp"

bool	draw_window(Info &info) {
	draw_camera_sight(info);
	draw_edge();
    draw_guide();
	return (true);
}