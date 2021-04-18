#include "Base.h"
#include "Drawer.h"

void Drawer::drawPixel(float x, float y, float red, float green, float blue) {
    glBegin(GL_POINTS);
    glColor3f(red, green, blue);
    glVertex2i(x, y);
    glEnd();
}

void Drawer::drawPoly(vector<pair<double, double>> points){
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