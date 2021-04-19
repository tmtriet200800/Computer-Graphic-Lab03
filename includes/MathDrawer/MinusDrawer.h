#ifndef MinusDrawer_H
#define MinusDrawer_H
#include "../Drawer.h"

class MinusDrawer : public Drawer  {
public:
  MinusDrawer();
  void draw(float xt, float yt, float scale);
};

#endif