//
// Created by Maria on 22.01.2021.
//

#include <fstream>
#include <string>
#include "loader.h"

std::vector<std::vector<char>> Loader::LoadMap() const {
  std::ifstream input_file("map.txt"); //TODO maybe class should be destoyed after reading a map

  std::string line;
  std::vector<std::vector<char>> map;
  while (std::getline(input_file, line)) //TODO maybe add some checks if symbols are correct
  {
    std::vector<char> chars_on_the_map;
    for (char & i : line) {
      chars_on_the_map.push_back(i);
    }

    map.push_back(chars_on_the_map);
  }

  if (map.empty()) {
    throw std::exception("unexpected error: map cannot be empty"); //TODO catch it
  }

  return map;
}
