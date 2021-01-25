//
// Created by Maria on 23.01.2021.
//

#include "direction.h"

/*enum Directions {
 KEY_UP = 72,
 KEY_DOWN = 80,
 KEY_LEFT = 75,
 KEY_RIGHT = 77
};*/

enum Directions {
  UP = 'w',
  DOWN = 's',
  LEFT = 'a',
  RIGHT = 'd'
};

Direction::Direction() : up_(Point(-1, 0)), down_(Point(1, 0)),
                         left_(Point(0, -1)), right_(Point(0, 1)) { }

Point Direction::GetMoveDirection(char direction) const {
  auto pointToMove = Point(0, 0);
  //auto key = _getch();

  switch (direction) {
    case UP:
      pointToMove += up_;
      break;
    case DOWN:
      pointToMove += down_;
      break;
    case LEFT:
      pointToMove += left_;
      break;
    case RIGHT:
      pointToMove += right_;
      break;
    default:
      break;
  }

  return pointToMove;
}
