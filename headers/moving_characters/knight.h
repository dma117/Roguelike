//
// Created by Maria on 22.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_KNIGHT_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_KNIGHT_H_

#pragma once
#include <memory>
#include "moving_character.h"
#include "enemy.h"
#include "dragon.h"
#include "projectile.h"
#include "zombie.h"
#include "../not_moving_characters/wall.h"
#include "../not_moving_characters/princess.h"
#include "../not_moving_characters/aidkit.h"
#include "../helpers/game_states.h"

class Knight : public MovingCharacter {
 public:
  Knight(Point, char, int, int, int);

  int GetState() const;
  void CorrectState();
  void SetState(int state);

  Point Move(std::map<Point, std::shared_ptr<GameObject>>&, Point);

  void Collide(GameObject&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Knight&,std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&);
  void Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>&);

  Point Shoot(std::map<Point, std::shared_ptr<GameObject>>&, Point);

 private:
  char GetKeyToMove() const;
  std::shared_ptr<Projectile> projectile_;
  int state_;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_KNIGHT_H_
