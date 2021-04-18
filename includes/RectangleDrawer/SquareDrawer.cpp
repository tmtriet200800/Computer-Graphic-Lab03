#include "./SquareDrawer.h"

SquareDrawer::SquareDrawer(){}

void SquareDrawer::draw(float xt, float yt, float scale){
    RectangleDrawer::draw(xt, yt, scale, scale);
}
