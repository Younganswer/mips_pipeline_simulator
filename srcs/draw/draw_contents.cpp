#include "../../incs/draw_contents.hpp"
#include "../../incs/shape.hpp"

bool	draw_contents(const Info &info);
bool	DrawCircleSectorLinesEx(float posX, float posY, float radius, int startAngle, int endAngle, int segments, Color color);

bool	draw_contents(const Info &info) {
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

bool	DrawCircleSectorLinesEx(float posX, float posY, float radius, int startAngle, int endAngle, int segments, Color color) {
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+0.0f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+0.25f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+0.5f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+0.75f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+1.0f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+1.25f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+1.5f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+1.75f, startAngle, endAngle, segments, color);
	DrawCircleSectorLines((Vector2){ posX, posY }, radius+2.0f, startAngle, endAngle, segments, color);
	return (true);
}