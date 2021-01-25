//
// Created by Maria on 22.01.2021.
//

#ifndef ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_LOADER_H_
#define ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_LOADER_H_

#include <vector>
#include <iostream>
#include "../map.h"

class Loader {
 public:
  Loader() = default;
  std::vector<std::vector<char>> LoadMap() const;
};

#endif //ROGUELIKE_CMAKE_BUILD_DEBUG_HEADERS_LOADER_H_
