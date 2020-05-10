#include "SFMLView.hpp"
#include "Snake.hpp"
#include "SnakeBoard.hpp"
#include <SFML/Graphics.hpp>
#include <cerrno>
#include <cstring>

SFMLView::SFMLView(SnakeBoard &board, Snake &snake)
    : view_board(board),
      view_snake(snake),
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

void SFMLView::display(sf::RenderWindow &window)
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
