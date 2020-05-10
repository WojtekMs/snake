#include "Game.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include <SFML/Graphics.hpp>
#include <cerrno>
#include <cstring>

Game::Game(SnakeBoard &board, Snake &snake)
    : view_board(board),
      view_snake(snake),
    //   game_ctrl(board, snake),
      window_width(view_board.get_width() * field_size),
      window_height(view_board.get_height() * field_size)
{
    if (!wall_texture.loadFromFile("/home/wojtek/Studia/programing/snake/wall_texture.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!grass_texture.loadFromFile("/home/wojtek/Studia/programing/snake/grass_texture.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!food_texture.loadFromFile("/home/wojtek/Studia/programing/snake/apple_texture_2.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!snake_body_texture.loadFromFile("/home/wojtek/Studia/programing/snake/body_texture.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
     if (!snake_head_texture.loadFromFile("/home/wojtek/Studia/programing/snake/head_texture.png")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    if (!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/chandas1-2.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    text.setFont(font);
    wall_sprite.setTexture(wall_texture);
    grass_sprite.setTexture(grass_texture);
    food_sprite.setTexture(food_texture);
    snake_body_sprite.setTexture(snake_body_texture);
    snake_head_sprite.setTexture(snake_head_texture);
}

void Game::draw(sf::RenderWindow &window)
{
    for (int row = 0; row < view_board.get_height(); ++row) {
        for (int col = 0; col < view_board.get_width(); ++col) {
            int field_x_pos = col * field_size;
            int field_y_pos = row * field_size;
            if (view_board.get_tile_info(col, row) == 'X') {
                wall_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(wall_sprite);
            }
            if (view_board.get_tile_info(col, row) == 'F') {
                food_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(food_sprite);
            }
            if (view_board.get_tile_info(col, row) != 'X' && view_board.get_tile_info(col, row) != 'F') {
                if (view_snake.contains(col, row)) {
                    if (view_snake.get_head().x == col && view_snake.get_head().y == row) {
                        snake_head_sprite.setPosition(field_x_pos, field_y_pos);
                        window.draw(snake_head_sprite);
                    } else {
                        snake_body_sprite.setPosition(field_x_pos, field_y_pos);
                        window.draw(snake_body_sprite);
                    }
                } else {
                    grass_sprite.setPosition(field_x_pos, field_y_pos);
                    window.draw(grass_sprite);
                }
            }
        }
    }
}

int Game::Run(sf::RenderWindow & window)
{
    sf::Clock clock;
    while(true) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            if (event.key.code == sf::Keyboard::Escape) {
                return 0;
            }
            handle_events(event);
        }
        window.clear();
        view_snake.update(clock.restart());
        draw(window);
        window.display();

    }
}

void Game::handle_events(sf::Event &event)
{
     if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            view_snake.turn(Direction::LEFT);
        }
        if (event.key.code == sf::Keyboard::Right) {
            view_snake.turn(Direction::RIGHT);
        }
    }

}

Game::Game(const Game & rhs)
:view_board(rhs.view_board),
view_snake(rhs.view_snake),
field_size(rhs.field_size),
window_width(rhs.window_width),
window_height(rhs.window_height)
{
    wall_sprite = rhs.wall_sprite;
    grass_sprite = rhs.grass_sprite;
    food_sprite = rhs.food_sprite;
    snake_body_sprite = rhs.snake_body_sprite;
    snake_head_sprite = rhs.snake_head_sprite;
    grass_texture = rhs.grass_texture;
    wall_texture = rhs.wall_texture;
    food_texture = rhs.food_texture;
    snake_body_texture = rhs.snake_body_texture;
    snake_head_texture = rhs.snake_head_texture;
    font = rhs.font;
    text = rhs.text;
}

Game & Game::operator=(const Game & rhs)
{
    if (this == &rhs) {
        return *this;
    }
    view_board = rhs.view_board;
    view_snake = rhs.view_snake;
    field_size = rhs.field_size;
    wall_sprite = rhs.wall_sprite;
    grass_sprite = rhs.grass_sprite;
    food_sprite = rhs.food_sprite;
    snake_body_sprite = rhs.snake_body_sprite;
    snake_head_sprite = rhs.snake_head_sprite;
    grass_texture = rhs.grass_texture;
    wall_texture = rhs.wall_texture;
    food_texture = rhs.food_texture;
    snake_body_texture = rhs.snake_body_texture;
    snake_head_texture = rhs.snake_head_texture;
    font = rhs.font;
    text = rhs.text;
    return *this;

}

