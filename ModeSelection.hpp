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
    sf::Text text;
    sf::Text nickname_entered;
    sf::RectangleShape text_box;
    int choice;
    public:
    ModeSelection(SnakeBoard & b, Snake & s);
    virtual int Run(sf::RenderWindow &window);

};


#endif //GAMEMODES_H_