#ifndef CSCREEN_H_
#define CSCREEN_H_
#include <SFML/Graphics.hpp>

class cScreen
{
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

#endif //CSCREEN_H_