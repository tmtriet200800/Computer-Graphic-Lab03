#include "./MinusDrawer.h"

MinusDrawer::MinusDrawer(){};

void MinusDrawer::draw(float xt, float yt, float scale){
    double w = 3*scale;
    double h = scale;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt + w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt - h / 2));

    Drawer::drawPoly(points);
}
