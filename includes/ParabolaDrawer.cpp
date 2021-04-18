#include "ParabolaDrawer.h"

ParabolaDrawer::ParabolaDrawer(){
  
}

void ParabolaDrawer::drawByMidPoint(int xt, int yt, int a) {
    float p = 1 / (4 * a) - 1 / 2, x = 0, y = 0;

    drawPixel(xt + x, yt + y, 0, 1, 1);
    drawPixel(xt - x, yt + y, 0, 1, 1);

    while (x <= 2 * a) {
      if (p < 0) {
        p += (2 * x + 3) / (4 * a);
      } else {
        p += (2 * x + 3) / (4 * a) - 1;
        y++;
      }
      x++;

      drawPixel(xt + x, yt + y, 0, 1, 1);
      drawPixel(xt - x, yt + y, 0, 1, 1);
    }
}

void ParabolaDrawer::drawByOpenGL(float xt, float yt, float a){
  int totalPoint = 300;

  for(float x = 0; x < totalPoint; x=x+0.001){
    float y = 1/(4*a) * x * x;
    drawPixel(xt + x, yt + y, 1, 0, 1);
    drawPixel(xt - x, yt + y, 1, 0, 1);
  }
}