//
// Created by Maria on 23.01.2021.
//

#include "projectile.h"

Projectile::Projectile(Point pos, char sym,
               int hp, int damage, int max_hp) :
               MovingCharacter(pos, sym, hp, damage, max_hp), move_to_() { }

Point Projectile::Move(std::map<Point, std::shared_ptr<GameObject>>&, Point bounds)
{
  position_ += move_to_;

  if (InMap(bounds)) {
    position_ -= move_to_;
  }

  return position_;
}

void Projectile::SetDirection(Point direction) {
  move_to_ = direction;
}

void Projectile::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void Projectile::Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Projectile::Collide(Knight&, std::map<Point, std::shared_ptr<GameObject>>& map) {
  map.erase(position_);
}

void Projectile::Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ = 0;

  if (hp_ <= 0) {
    map.erase(position_);
  }
}

void Projectile::Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ = 0;

  if (hp_ <= 0) {
    map.erase(position_);
  }
}

void Projectile::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Projectile::Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Projectile::Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

char Projectile::GetKeyToMove() const {
  return 0;
}
