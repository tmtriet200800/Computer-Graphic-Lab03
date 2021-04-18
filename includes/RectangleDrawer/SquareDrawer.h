#ifndef SquareDrawer_H
#define SquareDrawer_H
#include "./RectangleDrawer.h"

class SquareDrawer : public RectangleDrawer {
public:
  SquareDrawer();
  void draw(float xt, float yt, float scale);
};

#endif