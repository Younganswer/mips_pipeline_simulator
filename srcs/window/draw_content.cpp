#include "../../incs/window.hpp"
#include "../../incs/shape.hpp"

static bool	DrawCircleSectorLinesEx(float posX, float posY);

bool	draw_content(void) {
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