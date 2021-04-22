#ifndef TriangleDrawer_H
#define TriangleDrawer_H
#include "../Drawer.h"

class TriangleDrawer : public Drawer  {
public:
  TriangleDrawer();
  vector<pair<double, double>> drawIsosceles(int xt, int yt, float r);
  vector<pair<double, double>> drawIsosceles(int xt, int yt, float red, float green, float blue, float r);
  vector<pair<double, double>> drawRight(int xt, int yt, float r);
  vector<pair<double, double>> drawRight(int xt, int yt, float red, float green, float blue, float r);
};

#endif