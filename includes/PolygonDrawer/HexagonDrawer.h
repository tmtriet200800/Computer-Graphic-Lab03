#ifndef HexagonDrawer_H
#define HexagonDrawer_H
#include "../Drawer.h"

class HexagonDrawer : public Drawer  {
public:
  HexagonDrawer();
  void draw(float xt, float yt, float scale);
};

#endif