//
// Created by Maria on 23.01.2021.
//

#include "zombie.h"

Zombie::Zombie(Point pos, char sym,
               int hp, int damage, int max_hp) : Enemy(pos, sym, hp, damage, max_hp) { }

void Zombie::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void Zombie::Collide(Wall&,std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Zombie::Collide(Knight& knight, std::map<Point, std::shared_ptr<GameObject>>& map) {
  knight.SetHp(knight.GetHp() - damage_);
  knight.CorrectState();
}

void Zombie::Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Zombie::Collide(Dragon&,std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Zombie::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>& map) { }

void Zombie::Collide(AidKit& aid_kit, std::map<Point, std::shared_ptr<GameObject>>& map) {
  map.erase(aid_kit.GetPosition());
}

void Zombie::Collide(Projectile& projectile, std::map<Point, std::shared_ptr<GameObject>>& map) {
  hp_ -= projectile.GetDamage();
  projectile.Collide(*this, map);

  if (hp_ <= 0) {
    map.erase(position_);
  }
}
