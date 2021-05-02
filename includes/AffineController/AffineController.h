#ifndef AffineController_H
#define AffineController_H
#include "../Drawer.h"

class AffineController : public Drawer  {
public:
  AffineController();

  void rotate(float angle, vector<pair<double, double>>& points);
  void translate(float dx, float dy, vector<pair<double, double>>& points);
  vector<pair<double, double>> scale(float scale, vector<pair<double, double>>& points);
};

#endif