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
    SnakeBoard board2(25, 40, SnakeBoard::GameMode::HARD);
    Snake snake(board2);
    Game sfml_view(board2, snake);
    // snake_tests(snake, view);
    // sfml_tests(sfml_view, sfml_ctrl, snake);
    screen_tests(board2, snake);
    Ranking trial(board2, snake);
    snake.init_file();
    trial.load_highscore_list(snake.get_fname());

    // std::vector<player_data> highscore_list;
    // player_data p_data {"wojtek", "hard", 100};
    // highscore_list.push_back(p_data);
    // for (size_t i = 0; i < highscore_list.size() ; ++i) {
    //     std::cout << i + 1 << ", " << highscore_list[i].name << ", " 
    //     << highscore_list[i].mode << ", " << highscore_list[i].score << "\n";
    // }
   
    
}
