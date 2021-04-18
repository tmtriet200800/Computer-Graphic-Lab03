#ifndef PolygonDrawer_H
#define PolygonDrawer_H
#include "Drawer.h"

class PolygonDrawer : public Drawer  {
public:
  PolygonDrawer();
  void drawPoly(vector<pair<double, double>> points);
  void drawPentagon();
  void drawHextagon();
  void drawStar();
  void drawArrow();
  void drawPlus();
  void drawMinus();
  void drawMultiple();
  void drawDivider();
};

#endif