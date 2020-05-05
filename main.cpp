#include <iostream>
#include "SnakeBoard.hpp"
#include "Snake.hpp"
#include "Debug_view.hpp"
#include "tests.hpp"
#include <array>
#include "Array2D.h"


int main() {
    SnakeBoard board2(20, 30, GameMode::HARD);
    Snake snake(board2);
    Debug_view view(board2, snake);
    snake_tests(snake, view);
    
   


}
