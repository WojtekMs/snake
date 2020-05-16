#ifndef RANKING_H_
#define RANKING_H_

#include <cerrno>
#include <cstring>
#include <iostream>

#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


class Ranking : public cScreen
{
    SnakeBoard &board;
    Snake &snake;
    std::vector<player_data> highscore_list;
    sf::Event event;
    sf::VertexArray table;
    std::vector<int> cols_x_start;
    sf::Font font;
    sf::Text text;
    int choice;
    enum option { MAIN_MENU,
                  EXIT };
    option current_option;
   

    bool sort(const char *lhs, const char *rhs);
    void draw(sf::RenderWindow &window);
    void fill_table(sf::Text &text, int col, int row);
    void fill_header(sf::Text &text, int col);
    void draw_header(sf::RenderWindow &window);
    void draw_scores(sf::RenderWindow &window);
    void set_table(sf::RenderWindow &window);

public:
    Ranking(SnakeBoard &b, Snake &s);
    virtual std::string Run(sf::RenderWindow &window);
    void load_highscore_list(const std::string &fname);
};

#endif //RANKING_H