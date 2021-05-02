#include "./AffineController.h"

AffineController::AffineController(){

}

vector<pair<double, double>> AffineController::scale(float scale, vector<pair<double, double>>& points){
  cout << points.size() << endl;

  for(int i = 1; i < points.size(); i++){
    points[i].first *= scale;
    points[i].second *= scale;

    points[i].first -= points[0].first*(scale - 1);
    points[i].second -= points[0].second*(scale - 1);
  }

  return points;
}

void AffineController::rotate(float angle, vector<pair<double, double>>& points){
  float cx = 0;
  float cy = 0;

  for(int i = 0; i < points.size(); i++){
    cx += points[i].first;
    cy += points[i].second;

  }
  cx = cx / points.size();
  cy = cy / points.size();

 for(int i = 0; i < points.size(); i++){
    double temp_x = cx + (points[i].first - cx) * cosf(angle) - (points[i].second - cy) * sinf(angle);
    double temp_y = cy + (points[i].first - cx) * sinf(angle) + (points[i].second - cy) * cosf(angle);

    points[i].first = temp_x;
    points[i].second = temp_y;
  }
}

void AffineController::translate(float dX, float dY, vector<pair<double, double>>& points){
 for(int i = 0; i < points.size(); i++){
    points[i].first += dX;
    points[i].second += dY;
  }
}