#ifndef TriangleDrawer_H
#define TriangleDrawer_H
#include "../Drawer.h"

class TriangleDrawer : public Drawer  {
public:
  TriangleDrawer();
  void drawIsosceles(int xt, int yt, float r);
  void drawIsosceles(int xt, int yt, float red, float green, float blue, float r);
  void drawRight(int xt, int yt, float r);
  void drawRight(int xt, int yt, float red, float green, float blue, float r);
};

#endif