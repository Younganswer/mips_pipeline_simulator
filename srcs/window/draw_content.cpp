#include "../../incs/window.hpp"
#include "../../incs/shape.hpp"

static bool	DrawCircleSectorLinesEx(float posX, float posY);

bool	draw_content(void) {
	DrawLineEx((Vector2){ -3000-80.0f, -600.0f }, (Vector2){ -3000-80.0f, 400.0f }, 3.0f, BLACK);
	DrawLineEx((Vector2){ -3000-140.0f, -700.0f }, (Vector2){ -3000-140.0f, 460.0f }, 3.0f, BLACK);
	draw_right_arrow(-80, 400, 20, 400);
	draw_right_arrow(-140, 460, 20, 460);
	draw_down_arrow(20, -820, 20, -70);
	draw_down_arrow(80, -170, 80, -70);
	DrawLineEx((Vector2){ -3000+160.0f, -170.0f }, (Vector2){ -3000+80.0f, -170.0f }, 3.0f, BLACK);
	DrawLineEx((Vector2){ -3000+160.0f, -250.0f }, (Vector2){ -3000+160.0f, -170.0f }, 3.0f, BLACK);
	DrawRectangle(-3000+60, -370, 200, 120, SKYBLUE);
	DrawRectangleLinesEx((Rectangle){ -3000+60, -370, 200, 120 }, 3.0f, BLUE);
	DrawText("EX/MEM", -3000+95, -340, 30, BLUE);
	DrawText("Branch", -3000+105, -310, 30, BLUE);
	DrawCircleSectorLinesEx(50, -70);
	draw_down_arrow(50, 0, 50, 370);
	draw_mux_0_1(50, 430);
	draw_right_arrow(80, 430, 160, 430);
	DrawRectangleLinesEx((Rectangle){ -3000+160, 340, 100, 180}, 3.0f, BLACK);
	DrawText("PC", -3000+191, 416, 30, BLACK);
	draw_right_arrow(260, 430, 460, 430);
	DrawRectangleLinesEx((Rectangle){ -3000+460, 300, 280, 500}, 3.0f, BLACK);
	DrawText("Address", -3000+490, 416, 30, BLACK);
	DrawText("Instruction", -3000+520, 520, 30, BLACK);
	DrawText("Memory", -3000+540, 560, 30, BLACK);
	draw_right_arrow(740, 550, 960, 550);
	return (true);
}

static bool	DrawCircleSectorLinesEx(float posX, float posY) {
	DrawLineEx((Vector2){ -3000+posX-72, posY }, (Vector2){ -3000+posX+72, posY }, 3.0f, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 70.0f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 70.25f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 70.5f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 70.75f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 71.0f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 71.25f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 71.5f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 71.75f, -90.0f, 90.0f, 0, BLACK);
	DrawCircleSectorLines((Vector2){ -3000+posX, posY }, 72.0f, -90.0f, 90.0f, 0, BLACK);
	return (true);
}