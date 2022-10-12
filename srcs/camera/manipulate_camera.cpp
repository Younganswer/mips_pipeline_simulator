#include "../../incs/camera.hpp"

bool	manipulate_camera(Camera2D &camera) {
	// Camera position controls
    if (IsKeyDown(KEY_RIGHT)) camera.target.x += 20;
    else if (IsKeyDown(KEY_LEFT)) camera.target.x -= 20;
	
	if (IsKeyDown(KEY_UP)) camera.target.y -= 20;
	else if (IsKeyDown(KEY_DOWN)) camera.target.y += 20;
    
	// Camera zoom controls
	if (IsKeyDown(KEY_I)) camera.zoom *= 1.025f;
	else if (IsKeyDown(KEY_O)) camera.zoom *= 0.975f;
    
	if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f) camera.zoom = 0.1f;
    
	// Camera reset (zoom and rotation)
    if (IsKeyPressed(KEY_R))
        camera.zoom = 0.8f;
	return (true);
}