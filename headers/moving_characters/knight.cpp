//
// Created by Maria on 22.01.2021.
//

#include "knight.h"
#include <iostream>

Knight::Knight(Point pos, char sym, int hp,
               int damage, int max_hp) :
               MovingCharacter(pos, sym, hp, damage, max_hp),
               state_(GameStates::ALIVE),
               projectile_(std::make_shared<Projectile>()) { }


Point Knight::Move(std::map<Point, std::shared_ptr<GameObject>>& map, Point bounds) {
  auto prev_pos = position_;
  position_ += direction_->GetMoveDirection(GetKeyToMove());

  if (!InMap(bounds)) {
    position_ = prev_pos;
  }

  return position_;
}

char Knight::GetKeyToMove() const {
  char key;
  std::cin >> key;
  return key;
}

void Knight::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void Knight::Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Knight::Collide(Knight&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Knight::Collide(Zombie& zombie, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ -= zombie.GetDamage();
  CorrectState();
}

void Knight::Collide(Dragon& dragon, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ -= dragon.GetDamage();
  CorrectState();
}

void Knight::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>& map) {
  state_ = GameStates::WINNER;
}

void Knight::Collide(AidKit& aid_kit, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ = std::max(hp_ + aid_kit.GetHp(), max_hp_);
  aid_kit.Collide(*this, map);
}

void Knight::Collide(Projectile& projectile, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ -= projectile.GetDamage();
  projectile.Collide(*this, map);
  CorrectState();
}

int Knight::GetState() const {
  return state_;
}

void Knight::CorrectState() {
  if (hp_ <= 0) {
    state_ = GameStates::DEAD;
  }
}

void Knight::SetState(int state) {
  state_ = state;
}

Point Knight::Shoot(std::map<Point, std::shared_ptr<GameObject>>& map, Point bounds) {
  auto prev_pos = position_;
  auto direction = direction_->GetMoveDirection(GetKeyToMove());
  position_ += direction;

  if (InMap(bounds) && map.count(position_) == 0) {
      projectile_->SetPosition(position_);
      projectile_->SetDirection(direction);
      projectile_->SetSym('@');
      projectile_->SetHp(5);

      map[position_] = projectile_;

      position_ -= direction;
      return position_ + direction;
  }

  position_ -= direction;
  return position_;
}
