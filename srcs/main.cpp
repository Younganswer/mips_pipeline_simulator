#include "../incs/mips_pipeline_simulator.hpp"

using namespace std;

int	main(int argc, char **argv) {
	(void) argc;
	(void) argv;
    
    // Initialize window -------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");

	// Set variables -----------------------------------------------------------------------
	Info	info;

    SetTargetFPS(60);                   // Set our simulator to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main simulator loop -----------------------------------------------------------------
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
		// Manipulate_camera
		manipulate_camera(info.camera);

        // Handling_button
        handling_button(info);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
			
            ClearBackground(RAYWHITE);
            draw_window(info);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadTexture(info.button.button);
    // Close window ------------------------------------------------------------------------
	CloseWindow();
	return (0);
}