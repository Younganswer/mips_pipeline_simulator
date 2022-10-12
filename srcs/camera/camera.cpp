#include "../../incs/camera.hpp"

bool	init_camera(Camera2D &camera) {
	camera.target = (Vector2){ 20.0f, 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.zoom = 0.8f;
	return (true);
}