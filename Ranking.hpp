#ifndef RANKING_H_
#define RANKING_H_

#include <cerrno>
#include <cstring>
#include <iostream>

#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class Ranking : public cScreen
{
    public:
    Ranking();
    virtual int Run(sf::RenderWindow &window);

};


#endif //RANKING_H