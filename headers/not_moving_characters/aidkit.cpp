//
// Created by Maria on 23.01.2021.
//

#include "aidkit.h"

AidKit::AidKit(Point pos, char sym, int hp) : GameObject(pos, sym, hp) { }

void AidKit::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void AidKit::Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void AidKit::Collide(Knight&, std::map<Point, std::shared_ptr<GameObject>>& map) {
  SetHp(0);

  if (hp_ <= 0) {
    map.erase(position_);
  }
}

void AidKit::Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void AidKit::Collide(Dragon&,std::map<Point, std::shared_ptr<GameObject>>&) { }

void AidKit::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void AidKit::Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void AidKit::Collide(Projectile&, std::map<Point, std::shared_ptr<GameObject>>&) { }

Point AidKit::Move(std::map<Point, std::shared_ptr<GameObject>> &, Point) {
  return position_;
}

int AidKit::GetHp() const {
  return hp_;
}

void AidKit::SetHp(int hp) {
  hp_ = hp;
}
