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
    SnakeBoard &board;
    Snake &snake;
    std::vector<player_data> highscore_list;
    bool sort(const char * lhs, const char * rhs);
    

    public:
    Ranking(SnakeBoard &b, Snake & s);
    virtual int Run(sf::RenderWindow &window);
    void load_highscore_list(const std::string &fname);

};


#endif //RANKING_H