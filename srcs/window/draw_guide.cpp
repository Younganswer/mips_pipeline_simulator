#include "../../incs/window.hpp"

bool	draw_guide(void) {
	DrawRectangle( 10, 10, 320, 120, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 320, 120, BLUE);
    DrawText("Free 2d camera controls:", 30, 30, 20, BLACK);
    DrawText("- Arrow to move camera", 60, 60, 20, DARKGRAY);
    DrawText("- I / O to Zoom in-out", 60, 90, 20, DARKGRAY);
    
	DrawRectangle( 340, 10, 280, 90, Fade(PINK, 0.5f));
    DrawRectangleLines( 340, 10, 280, 90, PURPLE);
    DrawText("Simulator controls:", 360, 30, 20, BLACK);
    DrawText("- Click to go next cycle", 360, 60, 20, DARKGRAY);
	return (true);
}