#include "Array2D.h"
#include "Game.hpp"
#include "Ranking.hpp"
#include "Screens.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <map>

int main()
{
   
    sf::VideoMode windowMode{1200, 700};
    if (auto modes = sf::VideoMode::getFullscreenModes(); !modes.empty()) {
        windowMode = modes.front();
    }
    sf::RenderWindow window(windowMode, "Snake");
    std::map<std::string, cScreen*> screens;
    SnakeBoard board(window.getSize().y / Consts::field_size,
                     window.getSize().x / Consts::field_size);
    Snake snake(board);
    MainMenu menu(board, snake);
    ModeSelection mode_selec(board, snake);
    Ranking ranking(board, snake);
    Game game(board, snake);
    screens["menu"] = (&menu);
    screens["mode selection"] = (&mode_selec);
    screens["ranking"] = (&ranking);
    screens["game"] = (&game);
    std::string screen = "menu";

    while (screen != "exit") {
        screen = screens[screen]->Run(window);
    }
}
