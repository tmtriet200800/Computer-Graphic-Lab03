#ifndef CircleDrawer_H
#define CircleDrawer_H
#include "./OvalDrawer.h"

class CircleDrawer : public OvalDrawer  {
public:
  CircleDrawer();
  vector<pair<double, double>> draw(float x, float y, float scaleY);
};

#endif