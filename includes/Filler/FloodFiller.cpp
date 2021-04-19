#include "FloodFiller.h"

void FloodFiller::fill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	std::cout << color.r << " " << color.g << " " << color.b << std::endl;
	std::cout << oldColor.r << " " << oldColor.g << " " << oldColor.b << std::endl;
	std::cout << newColor.r << " " << newColor.g << " " << newColor.b << std::endl;


	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		fill(x+1, y, oldColor, newColor);
		fill(x, y+1, oldColor, newColor);
		fill(x-1, y, oldColor, newColor);
		fill(x, y-1, oldColor, newColor);
	}
	return;
}