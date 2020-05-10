#ifndef RANKING_H_
#define RANKING_H_

#include <cerrno>
#include <cstring>
#include <iostream>

#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "SnakeBoard.hpp"
#include "Snake.hpp"

class Ranking : public cScreen
{
    public:
    Ranking(SnakeBoard &b, Snake & s);
    virtual int Run(sf::RenderWindow &window);

};


#endif //RANKING_H