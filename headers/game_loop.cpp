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
  EndGame(map_->GetState());
}

bool GameLoop::EndGame(int state) {
  switch(state) {
    case ALIVE:
      return false;
      break;
    case DEAD:
      std::cout << "you died";
      return true;
      break;
    case WINNER:
      std::cout << "you won the game!";
      return true;
      break;
    default:
      break;
  }

  return false;
}
