#ifndef LineDrawer_H
#define LineDrawer_H
#include "../Drawer.h"

class LineDrawer : public Drawer  {
public:
  LineDrawer();
  void drawByDDA(int x1, int y1, int x2, int y2);
  void drawByBresenham(int x1, int y1, int x2, int y2);
  void drawByOpenGL(float red, float green, float blue, float x1, float y1, float x2, float y2);
  void drawByOpenGL(float x1, float y1, float x2, float y2);
};

#endif