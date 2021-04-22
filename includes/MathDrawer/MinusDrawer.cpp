#include "./MinusDrawer.h"

MinusDrawer::MinusDrawer(){};

vector<pair<double, double>> MinusDrawer::draw(float xt, float yt, float scale){
    double w = 6*scale;
    double h = scale;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt + w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt - h / 2));

    Drawer::drawPoly(points);

    return points;
}
