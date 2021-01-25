//
// Created by Maria on 23.01.2021.
//

#include "enemy.h"
#include <cstdlib>

Enemy::Enemy(Point pos, char sym, int hp,
             int damage, int max_hp) :
    MovingCharacter(pos, sym, hp, damage, max_hp) { }

Point Enemy::Move(std::map<Point, std::shared_ptr<GameObject>>& map, Point bounds) {
  auto prev_pos = position_;
  position_ += direction_->GetMoveDirection(GetKeyToMove());

  if (!InMap(bounds)) {
    position_ = prev_pos;
  }

  return position_;
}
char Enemy::GetKeyToMove() const {
  return "wasd"[rand() % 4];
}
