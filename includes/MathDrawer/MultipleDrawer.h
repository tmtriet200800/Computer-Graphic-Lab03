#ifndef MultipleDrawer_H
#define MultipleDrawer_H
#include "../Drawer.h"

class MultipleDrawer : public Drawer  {
public:
  MultipleDrawer();
  void draw(float xt, float yt, float scale);
};

#endif