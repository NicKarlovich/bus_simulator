#include <iostream>
#include <cmath>
#include "point2.h"

Point2::Point2(float x_, float y_) : x_pos(x_), y_pos(y_) {};

float Point2::DistanceBetween(Point2 p) {
  return sqrt(pow(p.x_pos - x_pos,2) + pow(p.y_pos - y_pos,2));
}

int Point2::Quadrant() {
  float x = x_pos;
  float y = y_pos;
  if(x == 0 && y == 0) {
    return 0;
  } else if(x == 0) {
    if(y < 0) {
      return 4;
    } else {
      return 2;
    }
  } else if(y == 0) {
    if(x > 0) {
      return 1;
    } else {
      return 3;
    }
  } else if(x > 0) {
    if(y > 0) {
      return 1;
    } else {
      return 4;
    }
  } else if(x < 0) {
    if(y > 0) {
      return 2;
    } else {
      return 3;
    }
  } else {
    return -1;
  }
}

void Point2::Print() {
  std::cout << "Point Coords: x: " << x_pos << "  y: " << y_pos << std::endl;
}





























































//
