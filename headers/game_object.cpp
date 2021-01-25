//
// Created by Maria on 23.01.2021.
//

#include "game_object.h"

GameObject::GameObject(Point pos, char sym, int hp) :
                        position_(pos), sym_(sym), hp_(hp) { }

Point GameObject::GetPosition() const {
  return position_;
}

char GameObject::GetSym() const {
  return sym_;
}

void GameObject::SetPosition(const Point& pos) {
  position_ = pos;
}

void GameObject::SetSym(char sym) {
  sym_ = sym;
}

int GameObject::GetHp() const {
  return hp_;
}

void GameObject::SetHp(int hp) {
  hp_ = hp;
}
