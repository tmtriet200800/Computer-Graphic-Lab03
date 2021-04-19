#ifndef PlusDrawer_H
#define PlusDrawer_H
#include "../Drawer.h"

class PlusDrawer : public Drawer  {
public:
  PlusDrawer();
  void draw(float xt, float yt, float scale);
};

#endif