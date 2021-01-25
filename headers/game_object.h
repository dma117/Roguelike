//
// Created by Maria on 23.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_GAME_OBJECT_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_GAME_OBJECT_H_

#pragma once
#include "helpers/point.h"
#include <map>
#include <memory>

class Enemy;
class Knight;
class Dragon;
class Projectile;
class Zombie;
class AidKit;
class Wall;
class Princess;

class GameObject {
 public:
  GameObject() = default;
  GameObject(Point, char, int);

  Point GetPosition() const;
  char GetSym() const;
  int GetHp() const;

  void SetPosition(const Point&);
  void SetSym(char);
  void SetHp(int);

  virtual Point Move(std::map<Point, std::shared_ptr<GameObject>>&, Point) = 0;

  virtual void Collide(GameObject&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(Knight&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;
  virtual void Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

 protected:
  Point position_;
  char sym_;
  int hp_;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_GAME_OBJECT_H_
