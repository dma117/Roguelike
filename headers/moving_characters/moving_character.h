//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_MOVING_CHARACTER_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_MOVING_CHARACTER_H_

#pragma once
#include "../helpers/point.h"
#include "../game_object.h"
#include "../helpers/direction.h"
#include <memory>

class MovingCharacter : public GameObject {
 public:
  MovingCharacter() = default;
  MovingCharacter(Point, char, int, int, int);

  int GetDamage() const;
  int GetMaxHp() const;

 protected:
  int damage_;
  int max_hp_;
  //visitor
  std::unique_ptr<Direction> direction_;

  bool InMap(Point) const;

  virtual char GetKeyToMove() const = 0;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_MOVING_CHARACTER_H_
