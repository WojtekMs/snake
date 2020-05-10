#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
#include <SFML/Graphics.hpp>

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

class SnakeBoard;
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

    float speed; //measured in field per second
    float delta_speed; //the increase of speed after eating food
    bool moved_after_turn;
    GameState current_game_state;
    Direction current_dir;
    int game_points;
    std::string name;

    std::pair<int, int> get_valid(int x, int y);
    int sort_by_ids();
    void move();
    void grow();

public:
    explicit Snake(SnakeBoard &board);
    void turn(Direction dir);
    Direction get_current_dir() const { return current_dir; };
    int get_length() const { return length; };
    void display_dir() const;
    bool contains(int col, int row) const;
    GameState get_game_state() const { return current_game_state; };
    const SnakePiece & get_head() const { return body.front(); };
    float get_speed() const { return speed; };
    float get_delta_speed() const { return delta_speed; };
    void update(sf::Time time_elapsed);
    Snake & operator=(const Snake & rhs);
    void set_name(const std::string & n) { name = n; };

    
};

#endif