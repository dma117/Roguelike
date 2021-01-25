//
// Created by Maria on 23.01.2021.
//

#include "point.h"

Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}

Point Point::operator+(const Point& other) const {
  return {this->x + other.x, this->y + other.y};
}

Point& Point::operator+=(const Point& other) {
  *this = *this + other;

  return *this;
}

bool Point::operator<(const Point& other) const {
  return (this->x < other.x) || (this->x == other.x && this->y < other.y);
}

bool Point::operator==(const Point& other) const {
  return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const {
  return !(*this == other);
}

Point Point::operator-(const Point& other) const {
  return {this->x - other.x, this->y - other.y};
}

Point& Point::operator-=(const Point& other) {
  *this = *this - other;

  return *this;
}


