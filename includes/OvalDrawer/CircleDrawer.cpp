#include "./CircleDrawer.h"

CircleDrawer::CircleDrawer(){}

void CircleDrawer::draw(float x, float y, float scaleY){
    OvalDrawer::draw(x, y, scaleY, scaleY);
}
