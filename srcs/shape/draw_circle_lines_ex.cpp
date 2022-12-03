#include "../../incs/shape.hpp"

bool	draw_circle_lines_ex(float centerX, float centerY, float radius, float thick, Color color) {
	for (float i=0; i<thick; i+=0.1f) {
		DrawCircleLines(centerX, centerY, radius+i, color);
	}
	return (true);
}