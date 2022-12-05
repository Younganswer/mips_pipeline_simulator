#include <iostream>
#include "../incs/mips_pipeline_simulator.hpp"

using namespace std;

int	main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "\033[31m" << "Usage: make run" << "\033[0m" << '\n';
	}

	// Initialize window -------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "mips_pipeline_simulator");

	// Set variables -----------------------------------------------------------------------
	Info	info(argv[1], argv[2]);
	// init_camera(info.camera);
	// info.setInstructions(argv[1]);
	// info.setMemory(argv[2]);
	// info.setRegisterValues();

	SetTargetFPS(60);   // Set our simulator to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main simulator loop -----------------------------------------------------------------
	while (!WindowShouldClose())// Detect window close button or ESC key
	{
		// manipulate camera -----------------------------------------------
			manipulate_camera(info.camera);
		// manipulate camera -----------------------------------------------
		
		// check mouse click -------------------------------------------------------------------------
			if (info.button.is_actioned()) {
				update(info);
			}
		// check mouse click -------------------------------------------------------------------------

		// rendering ----------------------------------------------------------------------------------
			BeginDrawing();
			
			ClearBackground(RAYWHITE);
			render(info);

			EndDrawing();
		// rendering ----------------------------------------------------------------------------------
	}

	// Close window ------------------------------------------------------------------------
	CloseWindow();

	return (0);
}