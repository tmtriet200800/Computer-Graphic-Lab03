#ifndef RectangleDrawer_H
#define RectangleDrawer_H
#include "../Drawer.h"

class RectangleDrawer : public Drawer  {
public:
  RectangleDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scaleX, float scaleY);
};

#endif