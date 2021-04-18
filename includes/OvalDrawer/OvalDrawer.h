#ifndef OvalDrawer_H
#define OvalDrawer_H
#include "../Drawer.h"

class OvalDrawer : public Drawer  {
public:
  OvalDrawer();
  void draw(float x, float y, float scaleX, float scaleY);
};

#endif