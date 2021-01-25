//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_NOT_MOVING_CHARACTERS_WALL_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_NOT_MOVING_CHARACTERS_WALL_H_

#pragma once
#include "../game_object.h"
#include "../game_object.h"
#include "../moving_characters/knight.h"
#include "../moving_characters/dragon.h"
#include "../moving_characters/projectile.h"
#include "wall.h"
#include "princess.h"
#include "aidkit.h"

class Wall : public GameObject{
 public:
  Wall(Point, char, int);

  Point Move(std::map<Point, std::shared_ptr<GameObject>>&, Point);

  void Collide(GameObject&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Knight&,std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>&);
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_NOT_MOVING_CHARACTERS_WALL_H_
