#ifndef DividerDrawer_H
#define DividerDrawer_H
#include "../Drawer.h"

class DividerDrawer : public Drawer  {
public:
  DividerDrawer();
  void draw(float xt, float yt, float scale);
};

#endif