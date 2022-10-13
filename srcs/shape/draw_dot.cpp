#include "../../incs/shape.hpp"

bool	draw_dot(int posX, int posY, Color color) {
	DrawCircle(-3000+posX, posY, 10.0f, color);
	return (true);
}