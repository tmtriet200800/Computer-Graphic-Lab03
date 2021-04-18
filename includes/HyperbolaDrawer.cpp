#include "HyperbolaDrawer.h"

HyperbolaDrawer::HyperbolaDrawer(){

}

void HyperbolaDrawer::drawByMidPoint(int xt, int yt, int a, int b) {
  int x, y;
  x = a, y = 0;
  int p = b * b * (2 * a + 1) * (a + 1 / 2) - 2 * a * a - 2 * a * a * b * b;
  while (y <= b * b * x / (a * a)) {
    drawPixel(xt + x, yt + y, 1, 1, 1);
    drawPixel(xt - x, yt + y, 1, 1, 1);
    drawPixel(xt + x, yt - y, 1, 1, 1);
    drawPixel(xt - x, yt - y, 1, 1, 1);

    if (p > 0) {
      p -= 2 * a * a * (1 + 2 * (y + 1));
    } else {
      p += b * b * (2 + 2 * (2 * x + 1)) - 2 * a * a * (1 + 2 * (y + 1));
      x++;
    }
    y++;
  }
  int temp = 0;
  while (temp <= 100) {
    if (p > 0) {
      p += 2 * b * b * (1 + (2 * x + 1));
    } else {
      p += 2 * b * b * (1 + (2 * x + 1)) - 2 * a * a * (1 + 2 * y + 1);
      y++;
    }
    x++;

    drawPixel(xt + x, yt + y, 1, 1, 1);
    drawPixel(xt - x, yt + y, 1, 1, 1);
    drawPixel(xt + x, yt - y, 1, 1, 1);
    drawPixel(xt - x, yt - y, 1, 1, 1);

    temp++;
  }
}

void HyperbolaDrawer::drawByOpenGL(float xt, float yt, float a, float b){
  int totalPoint = 300;
  for(float i = a; i < totalPoint; i = i + 0.001){
    float x = i;
    float y = (b / a) * sqrt(x * x - a * a);
    
    drawPixel(xt + x, yt + y, 1, 0, 1);
    drawPixel(xt - x, yt + y, 1, 0, 1);
    drawPixel(xt + x, yt - y, 1, 0, 1);
    drawPixel(xt - x, yt - y, 1, 0, 1);

  }
}