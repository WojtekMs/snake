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

enum GameState
{
    RUNNING,
    FINISHED_LOSS,
};

  struct SnakePiece
    {
        int x;
        int y;
        int id; //used to sort snake elements
    };

class Snake
{
    int length;
    std::vector<SnakePiece> body;
    SnakeBoard &s_board;
    SnakePiece * head, * tail;

    int speed;
    int move_count;
    
    GameState current_game_state;
    Direction current_dir;

    std::pair<int, int> get_valid(int x, int y);
    int sort_by_ids();

public:
    explicit Snake(SnakeBoard &board);
    void move();
    void change_direction(Direction dir);
    int get_snake_piece_x(int idx) const { return body[idx].x; };
    int get_snake_piece_y(int idx) const { return body[idx].y; };
    int get_snake_piece_id(int idx) const { return body[idx].id; };
    int get_snake_piece_idx(int x, int y) const;
    int get_snake_piece_idx(int id) const;
    Direction get_current_dir() const { return current_dir; };
    int get_length() const { return length; };
    void display_dir() const;
    void grow();
    bool contains(int col, int row) const;
    GameState get_game_state() const { return current_game_state; };

    
};

#endif