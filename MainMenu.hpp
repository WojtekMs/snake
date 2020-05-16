#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <cerrno>
#include <cstring>
#include <iostream>

#include "Game.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class MainMenu : public cScreen
{
public:
    enum State { GAME_NOT_STARTED,
                 GAME_STARTED };
    enum Option { CONTINUE,
                  NEW_GAME,
                  RANKING,
                  EXIT };

private:
    SnakeBoard &board;
    Snake &snake;
    int choice;
    State current_menu_state;
    Option current_option;    
    sf::Event event;
    sf::Font font;
    sf::Text text_play;
    sf::Text text_continue;
    sf::Text text_ranking;
    sf::Text text_exit;

    void handle_events(sf::Event &event);
    std::string chosen_screen();
    void draw_options(sf::RenderWindow &window);
    void set_menu_state();

public:
    MainMenu(SnakeBoard &b, Snake &s);
    virtual std::string Run(sf::RenderWindow &window);
};

#endif //MAINMENU_H_