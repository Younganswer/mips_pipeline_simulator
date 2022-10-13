#include "../../incs/shape.hpp"

bool	draw_trapezoid(float posX, float posY, float size) {
	DrawLineEx((Vector2){ -3000+posX, posY }, (Vector2){ -3000+posX, posY+(size*0.8f) }, 3.0f, BLACK);
	DrawLineEx((Vector2){ -3000+posX, posY+(size*0.8f) }, (Vector2){ -3000+posX+(size*0.6f), posY+size }, 3.0f, BLACK);
	DrawLineEx((Vector2){ -3000+posX+(size*0.6f), posY+size }, (Vector2){ -3000+posX, posY+(size*1.2f) }, 3.0f, BLACK);
	DrawLineEx((Vector2){ -3000+posX, posY+(size*1.2f) }, (Vector2){ -3000+posX, posY+(size*2.0f) }, 3.0f, BLACK);
	return (true);
}