#ifndef SNAKEBOARD_H_
#define SNAKEBOARD_H_
#include "Array2D.h"
#include <vector>

enum GameMode
{
    EASY,
    NORMAL,
    HARD
};

struct board_tile
{
    bool has_obstacle;
    bool has_food;
};

class SnakeBoard
{
    // friend class Snake;

    int height, width;
    int horizontal_g_size, vertical_g_size;
    Array2D<board_tile> board;
    std::vector<int> horizontal_gate_x, vertical_gate_y;
    GameMode current_game_mode;
    // GameState current_game_state;
    bool food;

    void set_size(int h, int w);
    void set_board();
    void draw_food();
    bool is_inside(int col, int row) const;
    bool out_of_range(int col, int row) const;

public:
    explicit SnakeBoard(int h = 20, int w = 20, GameMode mode = EASY);
    void debug_display() const;
    void debug_eat_food();
    char get_tile_info(int col, int row) const;
    int get_height() { return height; };
    int get_width() { return width; };
    int get_horizontal_g_size() { return horizontal_g_size; };
    int get_vertical_g_size() { return vertical_g_size; };
};

#endif