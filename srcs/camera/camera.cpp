#include "../../incs/camera.hpp"
#include "../../incs/info.hpp"

bool	init_camera(Camera2D &camera) {
	camera.target = (Vector2){ 0.0f, 0.0f };
	camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
	camera.zoom = 0.3f;
	camera.rotation = 0.0f;
	return (true);
}

bool	manipulate_camera(Camera2D &camera) {
	// Camera position controls
	if (IsKeyDown(KEY_RIGHT)) camera.target.x += 20;
	else if (IsKeyDown(KEY_LEFT)) camera.target.x -= 20;
	if (IsKeyDown(KEY_UP)) camera.target.y -= 20;
	else if (IsKeyDown(KEY_DOWN)) camera.target.y += 20;

	// Camera zoom controls
	if (IsKeyDown(KEY_I)) camera.zoom *= 1.025f;
	else if (IsKeyDown(KEY_O)) camera.zoom *= 0.975f;
	if (camera.zoom > 1.0f) camera.zoom = 1.0f;
	else if (camera.zoom < 0.125f) camera.zoom = 0.125f;

	// Camera reset
	if (IsKeyPressed(KEY_R)) {
		camera.target.x = 0.0f;
		camera.target.y = 0.0f;
		camera.zoom = 0.8f;
	}

	return (true);
}