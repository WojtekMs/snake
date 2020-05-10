#ifndef SFMLVIEW_H_
#define SFMLVIEW_H_
#include "SnakeBoard.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>

// class SnakeBoard;
// class Snake;
class SFMLView
{
    SnakeBoard & view_board;
    Snake & view_snake;
    const float field_size = 32;
    sf::Sprite wall_sprite;
    sf::Sprite grass_sprite;
    sf::Sprite food_sprite;
    sf::Sprite snake_body_sprite;
    sf::Sprite snake_head_sprite;
    sf::Texture grass_texture;
    sf::Texture wall_texture;
    sf::Texture food_texture;
    sf::Texture snake_body_texture;
    sf::Texture snake_head_texture;
    sf::Font font;
    sf::Text text;
    const unsigned int window_width;
    const unsigned int window_height;

    public:
    SFMLView(SnakeBoard & view, Snake & snake);
    void display(sf::RenderWindow & window);
    unsigned int get_window_width() { return window_width; };
    unsigned int get_window_height() { return window_height; };
    void update(sf::Time time_elapsed);


};


#endif //SFMLVIEW_H_