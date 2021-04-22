#include "./CircleDrawer.h"

CircleDrawer::CircleDrawer(){}

vector<pair<double, double>> CircleDrawer::draw(float x, float y, float scaleY){
    return OvalDrawer::draw(x, y, scaleY, scaleY);
}
