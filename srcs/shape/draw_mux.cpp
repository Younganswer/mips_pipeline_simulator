#include "../../incs/shape.hpp"

bool	draw_mux_0_1(int posX, int posY, Color color);
bool	draw_mux_1_0(int posX, int posY, Color color);
bool	DrawEllipseLinesEx(int posX, int posY, Color color);

bool	draw_mux_0_1(int posX, int posY, Color color) {
	DrawEllipseLinesEx(posX, posY, color);
	DrawText("0", -3000+posX-4, posY-30, 20, color);
	DrawText("1", -3000+posX-3, posY+20, 20, color);
	return (true);
}

bool	draw_mux_1_0(int posX, int posY, Color color) {
	DrawEllipseLinesEx(posX, posY, color);
	DrawText("1", -3000+posX-3, posY-30, 20, color);
	DrawText("0", -3000+posX-4, posY+20, 20, color);
	return (true);
}

bool	DrawEllipseLinesEx(int posX, int posY, Color color) {
	DrawEllipseLines(-3000+posX, posY, 30, 60, color);
	DrawEllipseLines(-3000+posX, posY, 30.25, 60.25, color);
	DrawEllipseLines(-3000+posX, posY, 30.5, 60.5, color);
	DrawEllipseLines(-3000+posX, posY, 30.75, 60.75, color);
	DrawEllipseLines(-3000+posX, posY, 31, 61, color);
	DrawEllipseLines(-3000+posX, posY, 31.25, 61.25, color);
	DrawEllipseLines(-3000+posX, posY, 31.5, 61.5, color);
	DrawEllipseLines(-3000+posX, posY, 31.75, 61.75, color);
	DrawEllipseLines(-3000+posX, posY, 32, 62, color);
	return (true);
}