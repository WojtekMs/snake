#ifndef GAMEMODES_H_
#define GAMEMODES_H_

#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "SnakeBoard.hpp"
#include "Snake.hpp"

class ModeSelection :public cScreen
{
    SnakeBoard & board;
    Snake & snake;
    sf::Font font;
    sf::Text easy_mode;
    sf::Text normal_mode;
    sf::Text hard_mode;
    // sf::Text text;
    int choice;
    enum option {EASY, NORMAL, HARD};
    public:
    ModeSelection(SnakeBoard & b, Snake & s);
    virtual int Run(sf::RenderWindow &window);
    GameMode get_mode() { return GameMode(choice); };
    // void set_menu_state(menu_state state) { current_menu_state}

};


#endif //GAMEMODES_H_