#ifndef SFMLVIEW_H_
#define SFMLVIEW_H_
#include "SnakeBoard.hpp"
#include "Snake.hpp"
#include "SFMLController.hpp"
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"

// class SnakeBoard;
// class Snake;
// enum GameScreenState {DISPLAYING, NOT_DISPLAYING};
class Game : public cScreen
{
    SnakeBoard & view_board;
    Snake & view_snake;
    // SFMLController game_ctrl;
    float field_size = 32;
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
    unsigned int window_width;
    unsigned int window_height;
    // GameScreenState current_screen_state;
    void handle_events(sf::Event &event);

    public:
    Game(SnakeBoard & view, Snake & snake);
    void draw(sf::RenderWindow & window);
    unsigned int get_window_width() const { return window_width; };
    unsigned int get_window_height() const { return window_height; };
    void update(sf::Time time_elapsed);
    virtual int Run(sf::RenderWindow & window);
    Game (const Game & rhs);
    Game & operator=(const Game & rhs);
    // GameScreenState get_game_screen_state() { return current_screen_state; }


};


#endif //SFMLVIEW_H_