#include "Array2D.h"
#include "Game.hpp"
#include "Ranking.hpp"
#include "Screens.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>



int main()
{
    int screen = 0;
    sf::RenderWindow window(sf::VideoMode(), "Snake", sf::Style::Fullscreen);
    window.setMouseCursorVisible(false);
    std::vector<cScreen *> screens;
    SnakeBoard board(window.getSize().y / Consts::field_size, window.getSize().x / Consts::field_size);
    Snake snake(board);
    MainMenu menu(board, snake);
    ModeSelection mode_selec(board, snake);
    Ranking ranking(board, snake);
    Game game(board, snake);
    screens.push_back(&menu); //0
    screens.push_back(&mode_selec); //1
    screens.push_back(&ranking); //2
    screens.push_back(&game); //3

    while (screen >= 0) {
        screen = screens[screen]->Run(window);
    }
}
