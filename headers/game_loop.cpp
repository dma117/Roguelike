//
// Created by Maria on 22.01.2021.
//

#include "game_loop.h"
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

GameLoop::GameLoop() {
  map_ = std::make_unique<Map>();
}

void GameLoop::Play() {
  map_->Load();
  map_->Show();
  map_->Update();
}
