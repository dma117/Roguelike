//
// Created by Maria on 23.01.2021.
//

#include "moving_character.h"

MovingCharacter::MovingCharacter(Point pos, char sym, int hp,
                                 int damage, int max_hp) :
                                 GameObject(pos, sym, hp),
                                 direction_(std::make_unique<Direction>()) {
  damage_ = damage;
  max_hp_ = max_hp;
}

int MovingCharacter::GetDamage() const {
  return damage_;
}

int MovingCharacter::GetMaxHp() const {
  return max_hp_;
}

bool MovingCharacter::InMap(Point bounds) const {
  return (position_.x >= 0 && position_.x < bounds.x) &&
         (position_.y >= 0 && position_.y < bounds.y);
}


