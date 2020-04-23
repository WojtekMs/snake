#include "Snake.hpp"

Snake::Snake(SnakeBoard &board)
:s_board(board)
{
    length = 3;
    head_x = s_board.get_width() / 2;
    head_y = s_board.get_width() / 2;
    current_direction = Direction::RIGHT;
}

void Snake::move(Direction current_direction)
{
    if (current_direction == Direction::)

}