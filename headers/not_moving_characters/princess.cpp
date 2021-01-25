//
// Created by Maria on 23.01.2021.
//

#include "princess.h"

Princess::Princess(Point pos, char sym, int hp) : GameObject(pos, sym, hp) { }

void Princess::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void Princess::Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Princess::Collide(Knight& knight, std::map<Point, std::shared_ptr<GameObject>>&) {
  knight.SetState(GameStates::WINNER);
}

void Princess::Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Princess::Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Princess::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Princess::Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Princess::Collide(Projectile& projectile, std::map<Point, std::shared_ptr<GameObject>>& map) {
  map.erase(projectile.GetPosition());
}

Point Princess::Move(std::map<Point, std::shared_ptr<GameObject>> &, Point) {
  return position_;
}
