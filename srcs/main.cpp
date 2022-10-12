#include "../incs/mips_pipeline_simulator.hpp"

int	main(int argc, char **argv) {
	(void) argc;
	(void) argv;
	// Set variables -----------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");
    Camera2D	camera;
	init_camera(camera);
	int			mouse_clicked = 0;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop ----------------------------------------------------------------------
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
		// Manipulate_camera
		manipulate_camera(camera);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
			
            ClearBackground(RAYWHITE);

            draw_window(camera);
			
			if (!mouse_clicked && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				mouse_clicked = 120;
			if (0 < mouse_clicked) {
				DrawText("Mouse clicked!", screenWidth/2 - 67, screenHeight/2 - 40, 20, RED);
				mouse_clicked--;
			}
				
            DrawText("SCREEN AREA", screenWidth - 200, 10, 20, RED);

            DrawRectangle(0, 0, screenWidth, 5, RED);
            DrawRectangle(0, 5, 5, screenHeight - 10, RED);
            DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED);
            DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);

            DrawRectangle( 10, 10, 320, 120, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 320, 120, BLUE);
            DrawText("Free 2d camera controls:", 30, 30, 20, BLACK);
            DrawText("- Arrow to move camera", 60, 60, 20, DARKGRAY);
            DrawText("- I / O to Zoom in-out", 60, 90, 20, DARKGRAY);
            
			DrawRectangle( 340, 10, 280, 90, Fade(PINK, 0.5f));
            DrawRectangleLines( 340, 10, 280, 90, PURPLE);
            DrawText("Simulator controls:", 360, 30, 20, BLACK);
            DrawText("- Click to go next cycle", 360, 60, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
	CloseWindow();
	return (0);
}