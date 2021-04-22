#ifndef MinusDrawer_H
#define MinusDrawer_H
#include "../Drawer.h"

class MinusDrawer : public Drawer  {
public:
  MinusDrawer();
  vector<pair<double, double>> draw(float xt, float yt, float scale);
};

#endif