#include "PolygonDrawer.h"

PolygonDrawer::PolygonDrawer(){

}

void PolygonDrawer::drawPoly(vector<pair<double, double>> points){
    for(int i = 0; i < points.size() - 1; ++i){
        glBegin( GL_LINES );
            glColor3f( 1, 0, 0 );
            glVertex3f( points[i].first, points[i].second, 0.0f );  
            glVertex3f( points[i + 1].first, points[i + 1].second, 0.0f );  
        glEnd();
    }

    glBegin( GL_LINES );
            glColor3f( 1, 0, 0 );
            glVertex3f( points[points.size() - 1].first, points[points.size() - 1].second, 0.0f );  
            glVertex3f( points[0].first, points[0].second, 0.0f );  
    glEnd();
}

void PolygonDrawer::drawPentagon(){
    double xt = 150;
    double yt = 150;
    double r = 100;
    double pi = 3.14;

    double angle = pi*0.2;

    vector<pair<double, double>> points;

    double edge = 2*r*sinf(angle);

    points.push_back(make_pair(xt, yt - r));
    points.push_back(make_pair(xt + edge*sinf(1.5*angle), yt - r + edge*cosf(1.5*angle)));
    points.push_back(make_pair( xt + r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair( xt - r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair(xt - edge*sinf(1.5*angle), yt - r + edge*cosf(1.5*angle)));

    this->drawPoly(points);
};

void PolygonDrawer::drawHextagon(){
    double xt = 150;
    double yt = 150;
    double r = 100;
    double pi = 3.14;

    double angle = pi / 6;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt - r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair(xt + r*sinf(angle), yt + r*cosf(angle)));
    points.push_back(make_pair(xt + r, yt));
    points.push_back(make_pair(xt + r*sinf(angle), yt - r*cosf(angle)));
    points.push_back(make_pair(xt - r*sinf(angle), yt - r*cosf(angle)));
    points.push_back(make_pair(xt - r, yt));

    this->drawPoly(points);
}


void PolygonDrawer::drawStar(){
    double xt = 150;
    double yt = 150;
    double r2 = 100;
    double r = 50;
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

    this->drawPoly(points);
}


void PolygonDrawer::drawArrow(){
    vector<pair<double, double>> points;

    double w = 50;
    double h = 50;
    double  rx = 150;
    double ry = 150;
    double arrow_w = 50;
    double arrow_h = 100;

    points.push_back(make_pair(rx - w / 2, ry - h / 2));
    points.push_back(make_pair(rx + w / 2, ry - h / 2));
    points.push_back(make_pair(rx + w / 2, ry + h / 2));
    points.push_back(make_pair(rx + w / 2 + arrow_w, ry + h / 2));
    points.push_back(make_pair(rx, ry + arrow_h));
    points.push_back(make_pair(rx - w / 2 - arrow_w, ry + h / 2));
    points.push_back(make_pair(rx - w / 2, ry + h / 2));
    
    this->drawPoly(points);
}

void PolygonDrawer::drawPlus(){
    double xt = 150;
    double yt = 150;

    double w = 50;
    double h = 150;

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

    this->drawPoly(points);
}

void PolygonDrawer::drawMultiple(){
    double xt = 300;
    double yt = 100;

    double w = 150;
    double h = 50;

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


    this->drawPoly(final_point);
}

void PolygonDrawer::drawMinus(){
    double xt = 300;
    double yt = 100;

    double w = 150;
    double h = 50;

    vector<pair<double, double>> points;

    points.push_back(make_pair(xt + w / 2, yt - h / 2));
    points.push_back(make_pair(xt + w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt + h / 2));
    points.push_back(make_pair(xt - w / 2, yt - h / 2));

    this->drawPoly(points);
}

void PolygonDrawer::drawDivider(){
    double xt = 300;
    double yt = 100;

    double space = 50;
    double radius = 50;
}