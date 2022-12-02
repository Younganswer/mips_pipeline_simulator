#include "../../incs/shape.hpp"

bool	draw_trapezoid(float posX, float posY, float size) {
	DrawLineEx((Vector2){ posX, posY }, (Vector2){ posX, posY+(size*0.8f) }, 5.0f, BLACK);
	DrawLineEx((Vector2){ posX, posY+(size*0.8f) }, (Vector2){ posX+(size*0.6f), posY+size }, 5.0f, BLACK);
	DrawLineEx((Vector2){ posX+(size*0.6f), posY+size }, (Vector2){ posX, posY+(size*1.2f) }, 5.0f, BLACK);
	DrawLineEx((Vector2){ posX, posY+(size*1.2f) }, (Vector2){ posX, posY+(size*2.0f) }, 5.0f, BLACK);
	DrawLineEx((Vector2){ posX, posY }, (Vector2){ posX+(size*1.2f), posY+(size*0.4f) }, 5.0f, BLACK);
	DrawLineEx((Vector2){ posX+(size*1.2f), posY+(size*0.4f) }, (Vector2){ posX+(size*1.2f), posY+(size*1.6f) }, 5.0f, BLACK);
	DrawLineEx((Vector2){ posX+(size*1.2f), posY+(size*1.6f) }, (Vector2){ posX, posY+(size*2.0f) }, 5.0f, BLACK);
	return (true);
}