#ifndef DividerDrawer_H
#define DividerDrawer_H
#include "../Drawer.h"

class DividerDrawer : public Drawer  {
public:
  DividerDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scale);
};

#endif