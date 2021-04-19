#include "./MultipleDrawer.h"

MultipleDrawer::MultipleDrawer(){};

void MultipleDrawer::draw(float xt, float yt, float scale){
    double w = 3*scale;
    double h = scale;

    double pi = 3.14;
    double angle = pi / 4;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt + w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt - h / 2));

    for(int i = 0; i < points.size(); i++){
        double x = xt +  (points[i].first - xt) * cosf(angle) - (points[i].second - yt) * sinf(angle);
        double y = yt +  (points[i].first - xt) * sinf(angle) + (points[i].second - yt) * cosf(angle);

        points[i].first = x;
        points[i].second = y;        
    }

    vector<pair<double, double>> points1;

    points1.push_back(make_pair(xt + w / 2, yt - h / 2));
    points1.push_back(make_pair(xt + w / 2, yt + h / 2));
    points1.push_back(make_pair(xt - w / 2, yt + h / 2));
    points1.push_back(make_pair(xt - w / 2, yt - h / 2));

    angle = 3*pi/4;

    for(int i = 0; i < points1.size(); i++){
        double x = xt +  (points1[i].first - xt) * cosf(angle) - (points1[i].second - yt) * sinf(angle);
        double y = yt +  (points1[i].first - xt) * sinf(angle) + (points1[i].second - yt) * cosf(angle);

        points1[i].first = x;
        points1[i].second = y;        
    }

    angle = pi/4;
    vector<pair<double, double>>final_point;

    final_point.push_back(points[1]);
    final_point.push_back(make_pair(xt, yt + h * cosf(angle)));
    final_point.push_back(points1[0]);

    final_point.push_back(points1[1]);
    final_point.push_back(make_pair(xt - h  *cosf(angle), yt));
    final_point.push_back(points[2]);

    final_point.push_back(points[3]);
    final_point.push_back(make_pair(xt, yt - h  *cosf(angle))); 
    final_point.push_back(points1[2]);

    final_point.push_back(points1[3]);
    final_point.push_back(make_pair(xt + h *cosf(angle), yt));
    final_point.push_back(points[0]);

    Drawer::drawPoly(final_point);
};