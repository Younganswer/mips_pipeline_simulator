#include "../incs/mips_pipeline_simulator.hpp"

int	main(int argc, char **argv) {
	(void) argc;
	(void) argv;
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");
	Vector2	ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 4.0f;
		if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 4.0f;
		if (IsKeyDown(KEY_UP)) ballPosition.y -= 4.0f;
		if (IsKeyDown(KEY_DOWN)) ballPosition.y += 4.0f;
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Move ball", 100, 10, 20, DARKGRAY);
		DrawCircleV(ballPosition, 50, MAROON);
		EndDrawing();
	}
	CloseWindow();
	return (0);
}