#ifndef StarDrawer_H
#define StarDrawer_H
#include "../Drawer.h"

class StarDrawer : public Drawer  {
public:
  StarDrawer();
  void draw(float xt, float yt, float scale);
};

#endif