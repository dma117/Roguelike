//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_ZOMBIE_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_ZOMBIE_H_

#pragma once
#include "enemy.h"
#include "knight.h"
#include "dragon.h"
#include "projectile.h"
#include "../not_moving_characters/wall.h"
#include "../not_moving_characters/princess.h"
#include "../not_moving_characters/aidkit.h"

class Zombie : public Enemy {
 public:
  Zombie(Point, char, int, int, int);

  void Collide(GameObject&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Knight&,std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>&);
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MOVING_CHARACTERS_ZOMBIE_H_
