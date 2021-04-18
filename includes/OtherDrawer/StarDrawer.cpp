#include "./StarDrawer.h"

StarDrawer::StarDrawer(){}

void StarDrawer::draw(float xt, float yt, float scale){
    double r2 = scale;
    double r = r2 / 2;
    double pi = 3.14;

    double angle = pi*0.2;

    vector<pair<double, double>> points;

    double edge = 2*r*sinf(angle);
    double edge2 = 2*r2*sinf(angle);

    points.push_back(make_pair(xt, yt - r2));
    points.push_back(make_pair( xt + r*sinf(angle), yt - r*cosf(angle)));

    points.push_back(make_pair(xt + edge2*sinf(1.5*angle), yt - r2 + edge2*cosf(1.5*angle)));
    points.push_back(make_pair(xt + edge*sinf(1.5*angle), yt + r - edge*cosf(1.5*angle)));

    points.push_back(make_pair( xt + r2*sinf(angle), yt + r2*cosf(angle)));
    points.push_back(make_pair(xt, yt + r));
    
    points.push_back(make_pair( xt - r2*sinf(angle), yt + r2*cosf(angle)));
    points.push_back(make_pair(xt - edge*sinf(1.5*angle), yt + r - edge*cosf(1.5*angle)));
        
    points.push_back(make_pair(xt - edge2*sinf(1.5*angle), yt - r2 + edge2*cosf(1.5*angle)));
    points.push_back(make_pair( xt - r*sinf(angle), yt - r*cosf(angle)));

    Drawer::drawPoly(points);
}
