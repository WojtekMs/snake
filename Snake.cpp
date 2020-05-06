#include "Snake.hpp"
#include <algorithm>
#include <list>
#include <iterator>
#include <vector>

Snake::Snake(SnakeBoard &board)
    : length(3),
      body(),
      s_board(board)
{
    for (int i = 0; i < length; ++i){
        body.push_back(SnakePiece(length - i, 1));
    }

    current_dir = Direction::RIGHT;
    current_game_state = GameState::RUNNING;
    speed = 1;
}

bool Snake::SnakePiece::operator==(const Snake::SnakePiece & sp) const {
    if (sp.x == this->x && sp.y == this->y)
        return true;
    return false;
}

void Snake::change_direction(Direction dir)
{
    if (!(dir == Direction::RIGHT || dir == Direction::LEFT)) {
        std::cout << "wybrales zly kierunek! \n";
        return;
    }
    if (dir == Direction::RIGHT) {
        if (current_dir == Direction::RIGHT) {
            current_dir = Direction::DOWN;
        } else if (current_dir == Direction::DOWN) {
            current_dir = Direction::LEFT;
        }

        else if (current_dir == Direction::LEFT) {
            current_dir = Direction::UP;
        }

        else if (current_dir == Direction::UP) {
            current_dir = Direction::RIGHT;
        }
    } else {
        if (current_dir == Direction::RIGHT)
            current_dir = Direction::UP;

        else if (current_dir == Direction::DOWN)
            current_dir = Direction::RIGHT;

        else if (current_dir == Direction::LEFT)
            current_dir = Direction::DOWN;

        else if (current_dir == Direction::UP)
            current_dir = Direction::LEFT;
    }
}

void Snake::display_dir() const
{
    if (current_dir == Direction::RIGHT)
        std::cout << "current: right";
    if (current_dir == Direction::DOWN)
        std::cout << "current: down";
    if (current_dir == Direction::LEFT)
        std::cout << "current: left";
    if (current_dir == Direction::UP)
        std::cout << "current: up";
    std::cout << "\n-------------------------\n";
}

void Snake::move()
{
    SnakePiece new_element;
    if (current_dir == Direction::RIGHT) {
        new_element.x = body.front().x + 1;
        new_element.y = body.front().y;
    }
    if (current_dir == Direction::DOWN) {
        new_element.x = body.front().x;
        new_element.y = body.front().y + 1;
    }
    if (current_dir == Direction::LEFT) {
        new_element.x = body.front().x - 1;
        new_element.y = body.front().y;
    }
    if (current_dir == Direction::UP) {
        new_element.x = body.front().x;
        new_element.y = body.front().y - 1;
    }
    switch (s_board.get_tile_info(new_element.x, new_element.y)) {
    case 'T':
        new_element.y = s_board.get_height() - 1;
        break;
    case 'B':
        new_element.y = 0;
        break;
    case 'L':
        new_element.x = s_board.get_width() - 1;
        break;
    case 'R':
        new_element.x = 0;
    }
    body.push_front(new_element);
    body.pop_back();
    
    if (s_board.get_tile_info(body.front().x, body.front().y) == 'X')
        current_game_state = GameState::FINISHED_LOSS;
    if (std::find(std::next(body.begin(), 1), body.end(), SnakePiece(body.front().x, body.front().y) ) != body.end() ) {
        current_game_state = GameState::FINISHED_LOSS;
    }
}

bool Snake::contains(int col, int row) const
{
    if (std::find(body.begin(), body.end(), SnakePiece(col, row)) != body.end()){
        return true;
    }
    return false; 
}

void Snake::grow()
{
    SnakePiece new_one;
    std::list<SnakePiece>::iterator last = std::next(body.end(), - 1);
    std::list<SnakePiece>::iterator after_last = std::next(body.end(), - 2); 

    if (after_last->x > last->x) {
        new_one.x = last->x - 1;
        new_one.y = last->y;
    }
    if (after_last->x < last->x) {
        new_one.x = last->x + 1;
        new_one.y = last->y;
    }
    if (after_last->y > last->y) {
        new_one.x = last->x;
        new_one.y = last->y - 1;
    }
    if (after_last->y < last->y) {
        new_one.x = last->x;
        new_one.y = last->y + 1;
    }
    if (s_board.get_tile_info(new_one.x, new_one.y) == 'X') {
        std::pair<int, int> valid = get_valid(new_one.x, new_one.y);
        new_one.x = valid.first;
        new_one.y = valid.second;
    }
    length++;
    body.push_back(new_one);
}

std::pair<int, int> Snake::get_valid(int x, int y)
{
    if (s_board.get_tile_info(x - 1, y - 1) == ' ')
        return std::pair<int, int>(x - 1, y - 1);
    if (s_board.get_tile_info(x + 1, y - 1) == ' ')
        return std::pair<int, int>(x + 1, y - 1);
    if (s_board.get_tile_info(x - 1, y + 1) == ' ')
        return std::pair<int, int>(x - 1, y + 1);
    if (s_board.get_tile_info(x + 1, y + 1) == ' ')
        return std::pair<int, int>(x + 1, y + 1);
}