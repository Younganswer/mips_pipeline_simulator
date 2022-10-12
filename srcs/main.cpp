#include "../incs/mips_pipeline_simulator.hpp"

int	main(int argc, char **argv) {
	(void) argc;
	(void) argv;
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Hello World!", 100, 10, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
	return (0);
}