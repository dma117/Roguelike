//
// Created by Maria on 22.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_GAME_LOOP_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_GAME_LOOP_H_

#pragma once
#include "map.h"
#include <memory>
#include <vector>

class GameLoop {
 public:
  GameLoop();
  void Play();
  bool EndGame(int);
 private:
  std::unique_ptr<Map> map_;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_GAME_LOOP_H_
