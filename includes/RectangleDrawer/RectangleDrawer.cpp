#include "./RectangleDrawer.h"

RectangleDrawer::RectangleDrawer(){}

void RectangleDrawer::draw(float xt, float yt, float scaleX, float scaleY){
    vector<pair<double, double>> points;

    points.push_back(make_pair(xt - scaleX, yt - scaleY));
    points.push_back(make_pair(xt + scaleX, yt - scaleY));
    points.push_back(make_pair(xt + scaleX, yt + scaleY));
    points.push_back(make_pair(xt - scaleX, yt + scaleY));

    Drawer::drawPoly(points);
}
