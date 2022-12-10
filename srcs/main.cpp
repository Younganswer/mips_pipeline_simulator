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

// TODO: immediate 작동하게 만들기
// TODO: data segment 페이지 넘기게 하기 왼, 오 []
// TODO: hazard unit execute단계에서 사용하는 rt선 연결해주기
// TODO: IF flush 선 그리기
// TODO: Register Equal signal 선 그리기
// TODO: forwarding C, D 로직 구현