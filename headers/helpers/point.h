//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_POINT_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_POINT_H_

class Point {
 public:
  Point() = default;
  Point(int, int);

  Point operator+(const Point&) const;
  Point& operator+=(const Point&);
  Point operator-(const Point&) const;
  Point& operator-=(const Point&);

  bool operator<(const Point&) const;
  bool operator==(const Point&) const;
  bool operator!=(const Point&) const;

  int x;
  int y;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_POINT_H_
