#ifndef SNAKEBOARD_H_
#define SNAKEBOARD_H_
#include "Array2D.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "SFMLView.hpp"
#include "Snake.hpp"

enum GameMode
{
    EASY,
    NORMAL,
    HARD
};
class SnakeBoard
{
    int height, width;
    Array2D<char> board_obstacles; //boolean vector doesnt work properly
    std::vector<int> horizontal_gate_x, vertical_gate_y;
    GameMode current_game_mode;
    int food_x, food_y;

    void set_size(int h, int w);
    void set_board_obstacles();
    void draw_food();
    bool out_of_range(int col, int row) const;
    friend void Snake::update(sf::Time time_elapsed);

public:
    explicit SnakeBoard(int h = 20, int w = 20, GameMode mode = EASY);
    char get_tile_info(int col, int row) const;
    int get_height() { return height; };
    int get_width() { return width; };
    GameMode get_current_game_mode() const { return current_game_mode; };
    int get_food_x() { return food_x; };
    int get_food_y() { return food_y; };
};

#endif