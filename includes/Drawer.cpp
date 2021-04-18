#include "Base.h"
#include "Drawer.h"

void Drawer::drawPixel(float x, float y, float red, float green, float blue) {
    glBegin(GL_POINTS);
    glColor3f(red, green, blue);
    glVertex2i(x, y);
    glEnd();
}
