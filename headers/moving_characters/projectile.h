//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_PROJECTILE_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_PROJECTILE_H_

#pragma once
#include "enemy.h"

class Projectile : public MovingCharacter {
 public:
  Projectile() = default;
  Projectile(Point, char, int, int, int);

  void SetDirection(Point);

  void Collide(GameObject&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Knight&,std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>&);
  Point Move(std::map<Point, std::shared_ptr<GameObject>>&, Point);
 private:
  Point move_to_;
  char GetKeyToMove() const;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_PROJECTILE_H_
