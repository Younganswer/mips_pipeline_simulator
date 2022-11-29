#include "../../incs/draw_contents.hpp"
#include "../../incs/shape.hpp"

static bool	DrawCircleSectorLinesEx(float posX, float posY);

bool	draw_contents(const Info &info) {
	DrawCircleSectorLinesEx(0, 0);	
	// draw operations ------------------------------------------------------------------
		draw_instruction_fetch(info);
		draw_instruction_decode(info);
		draw_execute(info);
		draw_memory_access(info);
		draw_write_back(info);
	// draw operations ------------------------------------------------------------------

	// draw pipeline --------------------------------------------------------------------
		draw_if_id(info);
		draw_id_ex(info);
		draw_ex_mem(info);
		draw_mem_wb(info);
	// draw pipeline --------------------------------------------------------------------
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