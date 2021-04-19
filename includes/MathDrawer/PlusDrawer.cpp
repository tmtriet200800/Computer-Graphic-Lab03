#include "./PlusDrawer.h"

PlusDrawer::PlusDrawer(){};

void PlusDrawer::draw(float xt, float yt, float scale){
    double w = scale;
    double h = 3*scale;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt + w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt - w / 2));
    points.push_back(make_pair(xt + h / 2, yt - w / 2)); 
    points.push_back(make_pair(xt + h / 2, yt + w / 2)); 
    points.push_back(make_pair(xt + w / 2, yt + w / 2));
    points.push_back(make_pair(xt + w / 2, yt + h / 2)); 
    points.push_back(make_pair(xt - w / 2, yt + h / 2)); 
    points.push_back(make_pair(xt - w / 2, yt + w / 2));
    points.push_back(make_pair(xt - h / 2, yt + w / 2)); 
    points.push_back(make_pair(xt - h / 2, yt - w / 2)); 
    points.push_back(make_pair(xt - w / 2, yt - w / 2));
    points.push_back(make_pair(xt - w / 2, yt - h / 2)); 

    Drawer::drawPoly(points);
}
