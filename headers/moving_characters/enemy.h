//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_ENEMY_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_ENEMY_H_

#pragma once
#include "moving_character.h"
#include <memory>

class Enemy : public MovingCharacter {
 public:
  Enemy(Point, char, int, int, int);

  Point Move(std::map<Point, std::shared_ptr<GameObject>>&, Point);
 private:
  char GetKeyToMove() const;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_ENEMY_H_
