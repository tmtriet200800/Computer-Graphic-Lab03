#ifndef ParabolaDrawer_H
#define ParabolaDrawer_H
#include "../Drawer.h"

class ParabolaDrawer : public Drawer  {
public:
  ParabolaDrawer();
  void drawByMidPoint(int xt, int yt, int a);  
  void drawByOpenGL(float xt, float yt, float a);
};

#endif