#ifndef SFMLCONTROLLER_H_
#define SFMLCONTROLLER_H_
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include <SFML/Graphics.hpp>

class SFMLController
{
    SnakeBoard &ctrl_board;
    Snake &ctrl_snake;

public:
    SFMLController(SnakeBoard &board, Snake &snake) : ctrl_board(board), ctrl_snake(snake) {}
    void handle_events(sf::Event &event);
};


#endif //SFMLCONTROLLER_H_