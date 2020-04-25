#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include "SnakeBoard.hpp"
#include <vector>

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

  struct SnakePiece
    {
        int x;
        int y;
    };

class Snake
{
    int length;
    std::vector<SnakePiece> body;
    SnakeBoard &s_board;

    //not initialized
    int head_x, head_y; //przechowuja wspolrzedne glowy //in current model not used
    int tail_x, tail_y; //przechowuja wspolrzedne ogona //in current model not used
    int speed;

    Direction current_dir, prev_dir;

    std::pair<int, int> get_valid(int x, int y);

public:
    explicit Snake(SnakeBoard &board);
    void move();
    void change_direction(Direction dir);
    int get_snake_piece_x(int idx) { return body[idx].x; };
    int get_snake_piece_y(int idx) { return body[idx].y; };
    int get_snake_piece_idx(int x, int y) const;
    Direction get_current_dir() const { return current_dir; };
    Direction get_prev_dir() { return prev_dir; };
    int get_length() const { return length; };
    void display_dir() const;
    void grow();
    bool contains(int col, int row) const;
    
};

#endif