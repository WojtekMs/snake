#include "Game.hpp"
#include "MainMenu.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include <SFML/Graphics.hpp>
#include <cerrno>
#include <cstring>

Game::Game(SnakeBoard &board, Snake &snake)
    : view_board(board),
      view_snake(snake),
      end_game_textbox(sf::Vector2f(500, 400)),
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
    total_time = sf::Time();
}

void Game::draw(sf::RenderWindow &window)
{
    for (int row = 0; row < view_board.get_height(); ++row) {
        for (int col = 0; col < view_board.get_width(); ++col) {
            int field_x_pos = col * field_size;
            int field_y_pos = row * field_size;
            switch (view_board.get_tile_info(col, row)) {
            case 'X': {
                wall_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(wall_sprite);
            } break;
            case 'F': {
                food_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(food_sprite);
            } break;
            case 'T':
            case 'B':
            case 'R':
            case 'L':
            case ' ': {
                grass_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(grass_sprite);
            } break;
            default:
                break;
            }
            if (view_snake.contains(col, row)) {
                snake_body_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(snake_body_sprite);
            }
            if (view_snake.get_head().x == col && view_snake.get_head().y == row) {
                snake_head_sprite.setPosition(field_x_pos, field_y_pos);
                window.draw(snake_head_sprite);
            }
        }
    }
}

void Game::draw_end_game_screen(sf::RenderWindow &window)
{
    end_game_textbox.setSize(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 3));
    end_game_textbox.setPosition(window.getSize().x / 4, window.getSize().y / 3);
    end_game_textbox.setFillColor(sf::Color::Black);
    end_game_textbox.setOutlineColor(sf::Color::Red);
    end_game_textbox.setOutlineThickness(2);
    window.draw(end_game_textbox);
    text.setString("Przegrales!");
    text.setPosition(end_game_textbox.getPosition().x + (end_game_textbox.getSize().x - text.getLocalBounds().width) / 2, end_game_textbox.getPosition().y + (end_game_textbox.getSize().y - text.getLocalBounds().height) / 2);
    text.setFillColor(sf::Color::Red);
    window.draw(text);
}

int Game::Run(sf::RenderWindow &window)
{
    view_snake.current_game_state = Snake::GameState::RUNNING;
    total_time = sf::Time();
    while (true) {
        sf::Event event;
        while (window.pollEvent(event)) {
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
        if (view_snake.get_game_state() == Snake::GameState::FINISHED_LOSS) {
            draw_end_game_screen(window);
            total_time += clock.getElapsedTime();
            if (total_time.asSeconds() > 2.5) {
                return 2; //ranking screen
            }
           
        }
        window.display();
    }
}

void Game::handle_events(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            view_snake.turn(Snake::Direction::LEFT);
        }
        if (event.key.code == sf::Keyboard::Right) {
            view_snake.turn(Snake::Direction::RIGHT);
        }
    }
    if (view_snake.get_game_state() == Snake::GameState::FINISHED_LOSS) {
    }
}

Game::Game(const Game &rhs)
    : view_board(rhs.view_board),
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
    total_time = rhs.total_time;
}

Game &Game::operator=(const Game &rhs)
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
    total_time = rhs.total_time;

    return *this;
}
