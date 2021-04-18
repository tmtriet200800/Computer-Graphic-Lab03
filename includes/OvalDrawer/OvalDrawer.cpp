#include "./OvalDrawer.h"

OvalDrawer::OvalDrawer(){}

void OvalDrawer::draw(float x, float y, float scaleX, float scaleY){
    double pi = 3.14;
    glBegin(GL_POINTS);
    for(int i = 0; i < 360; i++){
      float angle = i*pi/180;
      glColor3f(1, 0, 0);
      glVertex2f(scaleX*cosf(angle) + x, scaleY*sinf(angle) + y);
    }
    glEnd();
}
