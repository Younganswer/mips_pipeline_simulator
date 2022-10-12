#include "../../incs/shape.hpp"

bool	draw_mux_0_1(int posX, int posY);
bool	draw_mux_1_0(int posX, int posY);
bool	DrawEllipseLinesEx(int posX, int posY);

bool	draw_mux_0_1(int posX, int posY) {
	DrawEllipseLinesEx(posX, posY);
	DrawText("0", -3000+posX-4, posY-30, 20, BLACK);
	DrawText("1", -3000+posX-3, posY+20, 20, BLACK);
	return (true);
}

bool	draw_mux_1_0(int posX, int posY) {
	DrawEllipseLinesEx(posX, posY);
	DrawText("1", -3000+posX-3, posY-30, 20, BLACK);
	DrawText("0", -3000+posX-4, posY+20, 20, BLACK);
	return (true);
}

bool	DrawEllipseLinesEx(int posX, int posY) {
	DrawEllipseLines(-3000+posX, posY, 30, 60, BLACK);
	DrawEllipseLines(-3000+posX, posY, 30.25, 60.25, BLACK);
	DrawEllipseLines(-3000+posX, posY, 30.5, 60.5, BLACK);
	DrawEllipseLines(-3000+posX, posY, 30.75, 60.75, BLACK);
	DrawEllipseLines(-3000+posX, posY, 31, 61, BLACK);
	DrawEllipseLines(-3000+posX, posY, 31.25, 61.25, BLACK);
	DrawEllipseLines(-3000+posX, posY, 31.5, 61.5, BLACK);
	DrawEllipseLines(-3000+posX, posY, 31.75, 61.75, BLACK);
	DrawEllipseLines(-3000+posX, posY, 32, 62, BLACK);
	return (true);
}