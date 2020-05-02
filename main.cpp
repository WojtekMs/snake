#include <iostream>
#include "SnakeBoard.hpp"
#include "Snake.hpp"
#include "Debug_view.hpp"
#include "tests.hpp"

using namespace std;

int main() {
    SnakeBoard board2(20, 31, GameMode::HARD);
    Snake snake(board2);
    Debug_view view(board2, snake);
    snake_tests(snake, view);

}
