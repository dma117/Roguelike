//
// Created by Maria on 22.01.2021.
//

#include "map.h"

void Map::Load() {
  state_ = GameStates::ALIVE;

  Loader loader;

  auto map = loader.LoadMap();
  rows_ = map.size();
  cols_ = map.begin()->size();

  InitializeCharacters(map);
}

int Map::GetRows() const {
  return rows_;
}

int Map::GetCols() const {
  return cols_;
}

std::map<Point, std::shared_ptr<GameObject>> Map::GetMap() const {
  return original_map_;
}

void Map::Update() {
    while (true) {
      //MoveGameObjects(knight_);

      /*char key = 'p';
      std::cin >> key;
      if (key == 'q') {
        auto pos = knight_->Shoot(original_map_, Point(rows_, cols_));

        if (original_map_.count(pos) != 0) {
          game_objects_[original_map_[pos]] = pos;
          Show();
        }
      }*/

      auto prev_pos = knight_->GetPosition();
      auto new_pos = knight_->Move(original_map_, Point(rows_, cols_));

      if (original_map_.count(new_pos) != 0) {
        knight_->Collide(*original_map_[new_pos], original_map_);
        knight_->SetPosition(prev_pos);
      }
      else {
        original_map_[new_pos] = original_map_[prev_pos];
        original_map_.erase(prev_pos);
      }

      if (knight_->GetState() != GameStates::ALIVE) {
        state_ = knight_->GetState();
        break;
      }

      for (auto obj = game_objects_.begin(); obj != game_objects_.end(); obj++) {
            /*MoveGameObjects(std::make_pair(obj->first, obj->second));
            game_objects_[obj->first] = obj->second;*/

            auto prev_pos = obj->first->GetPosition();
            auto new_pos = obj->first->Move(original_map_, Point(rows_, cols_));

            if (new_pos == prev_pos) {
              continue;
            }

            if (original_map_.count(new_pos) == 0) {
              original_map_[new_pos] = original_map_[prev_pos];
              original_map_.erase(prev_pos);
              game_objects_[obj->first] = obj->second;
            }

            else {
              auto cur_obj = obj->first;
              auto collide_with = original_map_[new_pos];

              obj->first->Collide(*collide_with, original_map_);

              if (original_map_.count(prev_pos) == 0) {
                obj--;
                game_objects_.erase(cur_obj);
              }
              else {
                if (original_map_.count(new_pos) == 0) {
                  original_map_[new_pos] = original_map_[prev_pos];
                  original_map_.erase(prev_pos);
                  game_objects_[obj->first] = obj->second;
                }
                else {
                  obj->first->SetPosition(prev_pos);
                }
              }
              if (original_map_.count(new_pos) == 0) {
                obj--;
                game_objects_.erase(collide_with);
              }
            }
          }

          Show();
        }
}

void Map::Show() const {
  std::cout << std::endl;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (original_map_.count(Point(i, j)) == 0) {
        std::cout << '.';
      }
      else {
        std::cout << original_map_.at(Point(i, j))->GetSym();
      }
    }

    std::cout << std::endl;
  }
}



void Map::InitializeCharacters(std::vector<std::vector<char>> map) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      auto element = map[i][j];

      switch(element) {
        case 'K':
          knight_ = std::make_shared<Knight>(Point(i, j), 'K', 10, 10, 10);
          original_map_[Point(i, j)] = knight_;
          break;
        case 'Z':
          original_map_[Point(i, j)] = std::make_shared<Zombie>(Point(i, j), 'Z', 10, 10, 10);
          game_objects_[std::make_shared<Zombie>(Point(i, j), 'Z', 10, 10, 10)] = Point(i, j);
          break;
        case 'D':
          original_map_[Point(i, j)] = std::make_shared<Zombie>(Point(i, j), 'D', 10, 10, 10);
          game_objects_[std::make_shared<Zombie>(Point(i, j), 'D', 10, 10, 10)] = Point(i, j);
          break;
        case '#':
          original_map_[Point(i, j)] = std::make_shared<Wall>(Point(i, j), '#', 1);
          //game_objects_[std::make_shared<Wall>(Point(i, j), '#', 0)] = Point(i, j);
          break;
        case 'P':
          original_map_[Point(i, j)] = std::make_shared<Princess>(Point(i, j), 'P', 1);
          //game_objects_[std::make_shared<Princess>(Point(i, j), 'P', 0)] = Point(i, j);
          break;
        case '+':
          original_map_[Point(i, j)] = std::make_shared<AidKit>(Point(i, j), '+', 5);
          //game_objects_[std::make_shared<AidKit>(Point(i, j), '+', 5)] = Point(i, j);
          break;
        default:
          break;
      }
    }
  }
}

int Map::GetState() const {
  return state_;
}


//TODO add random aidkit