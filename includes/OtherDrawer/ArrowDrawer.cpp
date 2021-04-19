#include "./ArrowDrawer.h"

ArrowDrawer::ArrowDrawer(){}

void ArrowDrawer::draw(float xt, float yt, float scaleX, float scaleY){
    vector<pair<double, double>> points;

    double w = scaleX;
    double h = scaleY;
    double arrow_w = scaleX;
    double arrow_h = scaleY;

    points.push_back(make_pair(xt - w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt + h / 2));
    points.push_back(make_pair(xt + w / 2 + arrow_w, yt + h / 2));
    points.push_back(make_pair(xt, yt + arrow_h));
    points.push_back(make_pair(xt - w / 2 - arrow_w, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt + h / 2));

    Drawer::drawPoly(points);
}
