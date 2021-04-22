#include "./HexagonDrawer.h"

HexagonDrawer::HexagonDrawer(){};

vector<pair<double, double>> HexagonDrawer::draw(float xt, float yt, float scale){
    double r = scale;
    double pi = 3.14;

    double angle = pi / 6;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt - r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair(xt + r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair(xt + r, yt));
    points.push_back(make_pair(xt + r*sinf(angle), yt - r*cosf(angle)));
    points.push_back(make_pair(xt - r*sinf(angle), yt - r*cosf(angle)));
    points.push_back(make_pair(xt - r, yt));

    Drawer::drawPoly(points);

    return points;
}