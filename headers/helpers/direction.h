//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_INPUT_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_INPUT_H_

#include "point.h"

class Direction {
 public:
  Direction();
  Point GetMoveDirection(char) const;
 private:
  Point up_;
  Point down_;
  Point left_;
  Point right_;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_INPUT_H_
