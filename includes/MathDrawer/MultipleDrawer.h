#ifndef MultipleDrawer_H
#define MultipleDrawer_H
#include "../Drawer.h"

class MultipleDrawer : public Drawer  {
public:
  MultipleDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scale);
};

#endif