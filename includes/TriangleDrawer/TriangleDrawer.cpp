#include "TriangleDrawer.h"

TriangleDrawer::TriangleDrawer(){

}

vector<pair<double, double>> TriangleDrawer::drawIsosceles(int xt, int yt, float r){
  vector<pair<double, double>> points;

  points.push_back(make_pair(xt, yt -r));
  points.push_back(make_pair(xt + r, yt + r));
  points.push_back(make_pair(xt - r, yt + r));

  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt + r, yt + r, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt - r, yt + r, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( xt - r, yt + r, 0.0f );  
    glVertex3f( xt + r, yt + r, 0.0f );
  glEnd();

  return points;
}

vector<pair<double, double>> TriangleDrawer::drawIsosceles(int xt, int yt, float red, float green, float blue, float r){
  vector<pair<double, double>> points;

  points.push_back(make_pair(xt, yt -r));
  points.push_back(make_pair(xt + r, yt + r));
  points.push_back(make_pair(xt - r, yt + r));
 
  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt + r, yt + r, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt - r, yt + r, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( xt - r, yt + r, 0.0f );  
    glVertex3f( xt + r, yt + r, 0.0f );
  glEnd();

  return points;
}

vector<pair<double, double>> TriangleDrawer::drawRight(int xt, int yt, float r){
  vector<pair<double, double>> points;

  points.push_back(make_pair(xt, yt -r));
  points.push_back(make_pair(xt, yt));
  points.push_back(make_pair(xt + r, yt));

  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt, yt, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( xt + r, yt, 0.0f );  
    glVertex3f( xt, yt, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt + r, yt, 0.0f );
  glEnd();

  return points;
}

vector<pair<double, double>> TriangleDrawer::drawRight(int xt, int yt, float red, float green, float blue, float r){
  vector<pair<double, double>> points;

  points.push_back(make_pair(xt, yt -r));
  points.push_back(make_pair(xt, yt));
  points.push_back(make_pair(xt + r, yt));
 
  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( xt, yt + r, 0.0f );  
    glVertex3f( xt, yt, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( xt + r, yt, 0.0f );  
    glVertex3f( xt, yt, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( xt, yt + r, 0.0f );  
    glVertex3f( xt + r, yt, 0.0f );
  glEnd();

  return points;
}