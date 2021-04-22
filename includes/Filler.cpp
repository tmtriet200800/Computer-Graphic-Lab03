#include "Filler.h"

Color Filler::getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, 600 - y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void Filler::setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}