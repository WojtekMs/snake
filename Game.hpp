#ifndef SFMLVIEW_H_
#define SFMLVIEW_H_
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class Snake;
class SnakeBoard;
class Game : public cScreen
{
    SnakeBoard& view_board;
    Snake& view_snake;
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
    sf::RectangleShape end_game_textbox;
    sf::Clock clock;
    sf::Time total_time;
    unsigned int window_width;
    unsigned int window_height;
    void handle_events(sf::Event& event);
    void draw_end_game_screen(sf::RenderWindow& window);

   public:
    Game(SnakeBoard& view, Snake& snake);
    void draw(sf::RenderWindow& window);
    unsigned int get_window_width() const { return window_width; };
    unsigned int get_window_height() const { return window_height; };
    void update(sf::Time time_elapsed);
    virtual std::string Run(sf::RenderWindow& window);
    Game(const Game& rhs);
    Game& operator=(const Game& rhs);
};

#endif  // SFMLVIEW_H_
