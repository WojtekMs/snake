#ifndef debug_view_hpp_
#define debug_view_hpp_
#include "SnakeBoard.hpp"
#include "Snake.hpp"

class Debug_view
{
    SnakeBoard &v_board;
    Snake &v_snake;
    public:
    Debug_view(SnakeBoard &board, Snake &snake) :v_board(board), v_snake(snake) {};
    void display() const;

};

#endif //ssss