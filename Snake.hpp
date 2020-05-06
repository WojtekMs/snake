#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include "SnakeBoard.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

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

  

class Snake
{
    int length;
    class SnakePiece
    {
        public:
        int x;
        int y;
        explicit SnakePiece(int x = 0, int y = 0): x(x), y(y) {};
        bool operator==(const SnakePiece &sp) const;
    };
    std::list<Snake::SnakePiece> body;
    SnakeBoard &s_board;

    int speed; //measured in tiles per second
    GameState current_game_state;
    Direction current_dir;

    std::pair<int, int> get_valid(int x, int y);
    int sort_by_ids();

public:
    explicit Snake(SnakeBoard &board);
    void move();
    void change_direction(Direction dir);
    Direction get_current_dir() const { return current_dir; };
    int get_length() const { return length; };
    void display_dir() const;
    void grow();
    bool contains(int col, int row) const;
    GameState get_game_state() const { return current_game_state; };

    
};

#endif