#ifndef PentagonDrawer_H
#define PentagonDrawer_H
#include "../Drawer.h"

class PentagonDrawer : public Drawer  {
public:
  PentagonDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scale);
};

#endif