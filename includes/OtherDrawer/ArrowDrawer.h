#ifndef ArrowDrawer_H
#define ArrowDrawer_H
#include "../Drawer.h"

class ArrowDrawer : public Drawer  {
public:
  ArrowDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scaleX, float scaleY);
};

#endif