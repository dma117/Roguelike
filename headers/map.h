//
// Created by Maria on 22.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MAP_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MAP_H_

#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <map>
#include "moving_characters/knight.h"
#include "moving_characters/enemy.h"
#include "moving_characters/dragon.h"
#include "moving_characters/projectile.h"
#include "moving_characters/zombie.h"
#include "not_moving_characters/wall.h"
#include "not_moving_characters/princess.h"
#include "not_moving_characters/aidkit.h"
#include "game_object.h"
#include "helpers/point.h"
#include "helpers/loader.h"


class Map {
 public:
  Map() = default;
  void Load();

  int GetRows() const;
  int GetCols() const;
  int GetState() const;

  std::map<Point, std::shared_ptr<GameObject>> GetMap() const;

  void Show() const;
  void Update();
 private:
  std::shared_ptr<Knight> knight_;
  std::map<Point, std::shared_ptr<GameObject>> original_map_;
  std::map<std::shared_ptr<GameObject>, Point> game_objects_;
  int rows_;
  int cols_;
  int state_;

  void InitializeCharacters(std::vector<std::vector<char>>);
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_MAP_H_
