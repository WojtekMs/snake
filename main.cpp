#include <iostream>
#include "SnakeBoard.hpp"

using namespace std;

int main() {
    SnakeBoard board;
    SnakeBoard board2(10, 10);
    board2.debug_display();
    std::cout << "---------------------- \n";
    board.debug_display();
    board.debug_eat_food();
    board.debug_display();
}
