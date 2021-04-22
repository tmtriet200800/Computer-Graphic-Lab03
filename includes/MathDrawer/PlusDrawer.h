#ifndef PlusDrawer_H
#define PlusDrawer_H
#include "../Drawer.h"

class PlusDrawer : public Drawer  {
public:
  PlusDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scale);
};

#endif