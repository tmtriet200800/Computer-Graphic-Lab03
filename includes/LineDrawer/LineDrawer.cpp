#include "LineDrawer.h"

LineDrawer::LineDrawer(){
    
}

void LineDrawer::drawByDDA(int x1, int y1, int x2, int y2){
  float x = x1;
  float y = y1;
  float m = float((y2 - y1) / (x2 - x1));

  drawPixel(x, int(y + 0.5), 0, 1, 0);

  for (int k = x1; k < x2; k++) {
    x++;
    y += m;
    drawPixel(x, int(y + 0.5), 0, 1, 0);
  }
}

void LineDrawer::drawByBresenham(int x1, int y1, int x2, int y2) {
  int dx, dy, p, const1, const2;
  int x, y;

  dx = x2 - x1;
  dy = y2 - y1;

  p = 2 * dy - dx;
  const1 = 2 * dy;
  const2 = 2 * (dy - dx);

  x = x1;
  y = y1;

  drawPixel(x, y, 1, 0, 0);

  for (int i = x1; i < x2; i++) {
    if (p < 0) {
      p += const1;
    } else {
      p += const2;
      y++;
    }

    x++;
    drawPixel(x, y, 1, 0, 0);
  }
}

void LineDrawer::drawByOpenGL(float red, float green, float blue, float x1, float y1, float x2, float y2){
  glBegin( GL_LINES );
    glColor3f( red, green, blue );
    glVertex3f( x1, y1, 0.0f );  
    glVertex3f( x2, y2, 0.0f );
  glEnd();
}

void LineDrawer::drawByOpenGL(float x1, float y1, float x2, float y2){
  glBegin( GL_LINES );
    glColor3f( 1, 1, 0 );
    glVertex3f( x1, y1, 0.0f );  
    glVertex3f( x2, y2, 0.0f );
  glEnd();
}