#ifndef SNAKEBOARD_H_
#define SNAKEBOARD_H_
#include "Array2D.h"

enum GameMode
{
    EASY,
    NORMAL,
    HARD
};
enum GameState
{
    RUNNING,
    FINISHED_LOSS,
    FINISHED_WIN
};
struct board_tile
{
    bool has_obstacle;
    bool has_food;
};

class SnakeBoard
{

    int height, width;
    Array2D<board_tile> board;
    GameMode current_game_mode;
    GameState current_game_state;
    bool food;

    void set_size(int h, int w);
    void set_default_board();
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
};

#endif