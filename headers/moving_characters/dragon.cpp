//
// Created by Maria on 23.01.2021.
//

#include "dragon.h"

Dragon::Dragon(Point pos, char sym,
               int hp, int damage, int max_hp) : Enemy(pos, sym, hp, damage, max_hp) { }

void Dragon::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void Dragon::Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Dragon::Collide(Knight& knight, std::map<Point, std::shared_ptr<GameObject>>& map) {
  knight.SetHp(GetHp() - damage_);
  knight.CorrectState();
}

void Dragon::Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Dragon::Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Dragon::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Dragon::Collide(AidKit& aid_kit, std::map<Point, std::shared_ptr<GameObject>>& map) {
  map.erase(aid_kit.GetPosition());
}

void Dragon::Collide(Projectile& projectile, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ -= projectile.GetDamage();

  if (hp_ <= 0) {
    map.erase(position_);
  }
}