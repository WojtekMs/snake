#include <iostream>
#include "SnakeBoard.hpp"
#include "Snake.hpp"
#include "Debug_view.hpp"

using namespace std;

int main() {
    SnakeBoard board;
    SnakeBoard board2(15, 15);
    Snake snake(board2);
//     board2.debug_display();
//     std::cout << "---------------------- \n";
//     board.debug_display();
//     board.debug_eat_food();
//     board.debug_display();
    Debug_view view(board2, snake);
    view.display();
    snake.move();
    // snake.move();
    view.display();
 
    // snake.change_direction(Direction::LEFT);
    // snake.move();
    // snake.change_direction(Direction::RIGHT);
    // snake.move();
    // snake.move();
    view.display();
    // Direction current = snake.get_current_dir();
    // Direction prev = snake.get_prev_dir();
    



}
