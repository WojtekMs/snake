#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include "SnakeBoard.hpp"

  enum Direction
    {
        LEFT,
        RIGHT
    };

class Snake
{
    SnakeBoard &s_board;
    int length;
    int head_x, head_y;

    Direction current_direction;

public:
    explicit Snake(SnakeBoard &board);
    void move(Direction current_direction);
    void change_direction(Direction dir);
};

#endif