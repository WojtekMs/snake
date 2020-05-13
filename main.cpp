#include "Array2D.h"
#include "Game.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include "tests.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "Screens.hpp"
#include "Ranking.hpp"

int main()
{
    SnakeBoard board2(25, 40, GameMode::HARD);
    Snake snake(board2);
    Game sfml_view(board2, snake);
    // snake_tests(snake, view);
    // sfml_tests(sfml_view, sfml_ctrl, snake);
    screen_tests(board2, snake);
    Ranking trial(board2, snake);
    trial.load_highscore_list(snake.get_fname());
   
    
}
