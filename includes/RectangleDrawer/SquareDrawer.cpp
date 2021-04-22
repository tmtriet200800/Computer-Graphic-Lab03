#include "./SquareDrawer.h"

SquareDrawer::SquareDrawer(){}

vector<pair<double, double>>  SquareDrawer::draw(float xt, float yt, float scale){
    return RectangleDrawer::draw(xt, yt, scale, scale);
}
