#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#include "Game.hpp"


const int lim = 20;
const int max_score_count = 10;

struct player_data {
  
    char name[lim];
    char mode[lim];
    int score;
};

class SnakeBoard;
class Snake
{
public:
    friend int Game::Run(sf::RenderWindow &window);
    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    enum GameState {
        NOT_STARTED,
        RUNNING,
        FINISHED_LOSS,
    };

private:
    int length;
    class SnakePiece
    {
    public:
        int x;
        int y;
        explicit SnakePiece(int x = 0, int y = 0) : x(x), y(y){};
        bool operator==(const SnakePiece &sp) const;
    };
    std::list<Snake::SnakePiece> body;
    SnakeBoard &s_board;
    int player_score;
    std::string name;
    float speed;       //measured in field per second
    float delta_speed; //the increase of speed after eating food
    bool moved_after_turn;
    GameState current_game_state;
    Direction current_dir;
    bool saved;
    std::string fname;

    std::pair<int, int> get_valid(int x, int y);
    int sort_by_ids();
    void move();
    void grow();

public:
    explicit Snake(SnakeBoard &board);
    void turn(Direction dir);
    bool contains(int col, int row) const;
    void update(sf::Time time_elapsed);
    void set_name(const std::string &n) { name = n; };
    Snake &operator=(const Snake &rhs);
    
    void save_score();
    void init_file() const;
    
    GameState get_game_state() const { return current_game_state; };
    const SnakePiece &get_head() const { return body.front(); };
    float get_speed() const { return speed; };
    float get_delta_speed() const { return delta_speed; };
    const std::string &get_name() { return name; };
    const std::string &get_fname() { return fname; };
    Direction get_current_dir() const { return current_dir; };
    int get_length() const { return length; };
};

#endif