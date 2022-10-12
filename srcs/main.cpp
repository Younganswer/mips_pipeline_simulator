#include "../incs/mips_pipeline_simulator.hpp"

using namespace std;

int	main(int argc, char **argv) {
	(void) argc;
	(void) argv;
	// Set variables -----------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");
	Info	info;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main simulator loop ----------------------------------------------------------------------
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
		// Manipulate_camera
		manipulate_camera(info.camera);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
			
            ClearBackground(RAYWHITE);

            draw_window(info);
			handling_mouse(info.mouse_clicked);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
	CloseWindow();
	return (0);
}