#include "./OvalDrawer.h"

OvalDrawer::OvalDrawer(){}

vector<pair<double, double>> OvalDrawer::draw(float x, float y, float scaleX, float scaleY){
    vector<pair<double, double>> points;

    double pi = 3.14;
    glBegin(GL_POINTS);
    for(int i = 0; i < 360*10; i++){
      float angle = i*pi/180;
      glColor3f(1, 1, 0);
      glVertex2f(scaleX*cosf(angle) + x, scaleY*sinf(angle) + y);
      points.push_back(make_pair(scaleX*cosf(angle) + x, scaleY*sinf(angle) + y));
    }
    glEnd();

    return points;
}
