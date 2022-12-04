#include "../../incs/render.hpp"

bool	render_guide(void);
bool	render_button(Button &button);
bool	render_edge(void);

bool	render(Info &info) {
	render_camera_sight(info);
	render_guide();
	render_button(info.button);
	render_data(info);
	render_edge();
	return (true);
}

bool	render_guide(void) {
	DrawRectangleLines( 10, 10, 300, 150, BLUE);
	DrawRectangle( 10, 10, 300, 150, Fade(BLUE, 0.2f));
	DrawText("Free 2d camera controls:", 30, 30, 20, BLACK);
	DrawText("- Arrow to move camera", 40, 60, 20, DARKGRAY);
	DrawText("- I / O to Zoom in-out", 40, 90, 20, DARKGRAY);
	DrawText("- R to reset camera", 40, 120, 20, DARKGRAY);

	DrawRectangleLines( 315, 10, 280, 90, RED);
	DrawRectangle( 315, 10, 280, 90, Fade(RED, 0.2f));
	DrawText("Simulator controls:", 335, 30, 20, BLACK);
	DrawText("- Click to go next cycle", 335, 60, 20, DARKGRAY);
	return (true);
}

bool	render_button(Button &button) {
	string	cur_cycle = to_string(button.get_cycle());
	DrawTextEx(GetFontDefault(), "Current cycle: ", (Vector2){ button.get_btn_bounds().x+20, button.get_btn_bounds().y-30 }, 20.0f, 1.0f, BLACK);
	DrawTextEx(GetFontDefault(), cur_cycle.c_str(), (Vector2){ button.get_btn_bounds().x+185-(cur_cycle.length()*7), button.get_btn_bounds().y-30 }, 20.0f, 1.0f, BLACK);
	DrawTextureRec(button.get_texture(), button.get_source_rec(), (Vector2){ button.get_btn_bounds().x, button.get_btn_bounds().y }, WHITE);
	return (true);
}

bool	render_edge(void) {
	DrawText("SCREEN AREA", screenWidth - 200, 10, 20, RED);
	DrawRectangle(0, 0, screenWidth, 5, RED);
	DrawRectangle(0, 5, 5, screenHeight - 10, RED);
	DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 10, RED);
	DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);
	return (true);
}