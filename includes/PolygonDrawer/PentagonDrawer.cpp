#include "./PentagonDrawer.h"

PentagonDrawer::PentagonDrawer(){};


void PentagonDrawer::draw(float xt, float yt, float scale){
    double r = scale;
    double pi = 3.14;

    double angle = pi*0.2;

    vector<pair<double, double>> points;

    double edge = 2*r*sinf(angle);

    points.push_back(make_pair(xt, yt - r));
    points.push_back(make_pair(xt + edge*sinf(1.5*angle), yt - r + edge*cosf(1.5*angle)));
    points.push_back(make_pair( xt + r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair( xt - r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair(xt - edge*sinf(1.5*angle), yt - r + edge*cosf(1.5*angle)));

    Drawer::drawPoly(points);
}