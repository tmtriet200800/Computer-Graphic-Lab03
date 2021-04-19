#ifndef ArrowDrawer_H
#define ArrowDrawer_H
#include "../Drawer.h"

class ArrowDrawer : public Drawer  {
public:
  ArrowDrawer();
  void draw(float xt, float yt, float scaleX, float scaleY);
};

#endif