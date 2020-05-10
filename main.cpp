#include "Array2D.h"
#include "Debug_view.hpp"
#include "Game.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include "tests.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "SFMLController.hpp"
#include "Screens.hpp"

int main()
{
    SnakeBoard board2(25, 40, GameMode::HARD);
    Snake snake(board2);
    Debug_view view(board2, snake);
    Game sfml_view(board2, snake);
    SFMLController sfml_ctrl(board2, snake);
    // snake_tests(snake, view);
    // sfml_tests(sfml_view, sfml_ctrl, snake);
    screen_tests(board2, snake);
   
    
}
