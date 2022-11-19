#include "../incs/mips_pipeline_simulator.hpp"

using namespace std;

int	main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "\033[31m" << "Usage: make run" << "\033[0m" << '\n';
        exit(1);
    }

    FILE    *textSegment = fopen(argv[1], "r");
    if (textSegment == NULL) {
        cerr << "\033[31m" << "Error: Fail to open " << argv[1] << "\033[0m" << '\n';
        exit(1);
    }
    FILE    *dataSegment = fopen(argv[2], "r");
    if (dataSegment == NULL) {
        cerr << "\033[31m" << "Error: Fail to open " << argv[2] << "\033[0m" << '\n';
        exit(1);
    }
    
    // Initialize window -------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");

	// Set variables -----------------------------------------------------------------------
	Info	info;
    info.read_file(textSegment, dataSegment);

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