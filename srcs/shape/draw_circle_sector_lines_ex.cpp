#include "../../incs/shape.hpp"
#include <math.h>

bool	draw_circle_sector_lines_ex(float centerX, float centerY, float radius, float startAngle, float endAngle, int segments, float thick, Color color) {
	for (float i=0; i<thick; i+=0.1f) {
		DrawLineEx(Vector2{ centerX, centerY }, Vector2{ centerX + sinf(startAngle*PI / 180) * (radius + i), centerY + cosf(startAngle*PI / 180) * (radius + i) }, thick, color);
		DrawLineEx(Vector2{ centerX, centerY }, Vector2{ centerX + sinf(endAngle*PI / 180) * (radius + i), centerY + cosf(endAngle*PI / 180) * (radius + i) }, thick, color);
		DrawCircleSectorLines(Vector2{ centerX, centerY }, radius+i, startAngle, endAngle, segments, color);
	}
	return (true);
}