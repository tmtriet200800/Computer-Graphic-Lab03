#ifndef HyperbolaDrawer_H
#define HyperbolaDrawer_H
#include "../Drawer.h"

class HyperbolaDrawer : public Drawer  {
public:
  HyperbolaDrawer();
  void drawByMidPoint(int xt, int yt, int a, int b);
  void drawByOpenGL(float xt, float yt, float a, float b);
};

#endif