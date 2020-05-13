#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <cerrno>
#include <cstring>
#include <iostream>

#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "SnakeBoard.hpp"
#include "Snake.hpp"

enum menu_state {FIRST, STARTED};
enum option {CONTINUE, NEW_GAME, RANKING, EXIT};

class MainMenu : public cScreen
{
    SnakeBoard & board;
    Snake & snake;
    bool running;
    int choice;
    option current_option;
    menu_state current_menu_state;
    sf::Event event;
    sf::Font font;
    sf::Text text_play;
    sf::Text text_continue;
    sf::Text text_ranking;
    sf::Text text_exit;

public:
    MainMenu(SnakeBoard & b, Snake & s);
    virtual int Run(sf::RenderWindow &window);
};


#endif //MAINMENU_H_