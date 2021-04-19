#ifndef PentagonDrawer_H
#define PentagonDrawer_H
#include "../Drawer.h"

class PentagonDrawer : public Drawer  {
public:
  PentagonDrawer();
  void draw(float xt, float yt, float scale);
};

#endif