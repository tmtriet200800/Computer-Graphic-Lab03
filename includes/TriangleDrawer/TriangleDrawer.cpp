#include "TriangleDrawer.h"

TriangleDrawer::TriangleDrawer(){

}

void TriangleDrawer::drawIsosceles(int xt, int yt, float r){
  glBegin( GL_LINES );
    glColor3f( 1, 0, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt + r, yt + r, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 0, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt - r, yt + r, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 0, 0 );
    glVertex3f( xt - r, yt + r, 0.0f );  
    glVertex3f( xt + r, yt + r, 0.0f );
  glEnd();
}

void TriangleDrawer::drawIsosceles(int xt, int yt, float red, float green, float blue, float r){
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
}

void TriangleDrawer::drawRight(int xt, int yt, float r){
  glBegin( GL_LINES );
    glColor3f( 1, 0, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt, yt, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 0, 0 );
    glVertex3f( xt + r, yt, 0.0f );  
    glVertex3f( xt, yt, 0.0f );
  glEnd();

  glBegin( GL_LINES );
    glColor3f( 1, 0, 0 );
    glVertex3f( xt, yt - r, 0.0f );  
    glVertex3f( xt + r, yt, 0.0f );
  glEnd();
}

void TriangleDrawer::drawRight(int xt, int yt, float red, float green, float blue, float r){
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
}