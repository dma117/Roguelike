//
// Created by Maria on 23.01.2021.
//

#include "wall.h"

Wall::Wall(Point pos, char sym, int hp) : GameObject(pos, sym, hp) { }

void Wall::Collide(GameObject& obj, std::map<Point, std::shared_ptr<GameObject>>& map) {
  obj.Collide(*this, map);
}

void Wall::Collide(Wall&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Wall::Collide(Knight&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Wall::Collide(Zombie&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Wall::Collide(Dragon&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Wall::Collide(Princess&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Wall::Collide(AidKit&, std::map<Point, std::shared_ptr<GameObject>>&) { }

void Wall::Collide(Projectile& projectile, std::map<Point, std::shared_ptr<GameObject>>& map) {
  map.erase(projectile.GetPosition());
}

Point Wall::Move(std::map<Point, std::shared_ptr<GameObject>> &, Point) {
  return position_;
}
