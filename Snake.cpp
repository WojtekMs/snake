#include "Snake.hpp"

Snake::Snake(SnakeBoard &board)
    : length(5),
      body(length),
      s_board(board),
      head(&body[0]),
      tail(&body[length - 1])
{
    body[0].x = length;
    body[0].y = 1;
    body[0].id = 0;
    for (int i = 1; i < length; ++i) {
        body[i].x = body[0].x - i;
        body[i].y = body[0].y;
        body[i].id = i;
    }

    current_dir = Direction::RIGHT;
    current_game_state = GameState::RUNNING;
    speed = 1;
    move_count = 0;
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
    if (s_board.get_tile_info(head->x, head->y) == 'X')
        current_game_state = GameState::FINISHED_LOSS;

    move_count++;
    if (current_dir == Direction::RIGHT) {
        tail->x = head->x + 1;
        tail->y = head->y;
    }
    if (current_dir == Direction::DOWN) {
        tail->x = head->x;
        tail->y = head->y + 1;
    }
    if (current_dir == Direction::LEFT) {
        tail->x = head->x - 1;
        tail->y = head->y;
    }
    if (current_dir == Direction::UP) {
        tail->x = head->x;
        tail->y = head->y - 1;
    }
    head = tail;
    if (move_count % length != 0) {
        tail = &body[get_snake_piece_idx(tail->id - 1)];
    } else {
        move_count = 0;
        tail = &body[get_snake_piece_idx(length - 1)];
    }
}

bool Snake::contains(int col, int row) const
{
    for (int i = 0; i < length; ++i) {
        if (body[i].x == col && body[i].y == row)
            return true;
    }
    return false;
}

int Snake::get_snake_piece_idx(int col, int row) const
{
    for (int i = 0; i < length; ++i) {
        if (body[i].x == col && body[i].y == row)
            return i;
    }
    return -1;
}

int Snake::get_snake_piece_idx(int id) const
{
    for (int i = 0; i < body.size(); ++i)
    {
        if (body[i].id == id)
            return i;
    }
}

int Snake::sort_by_ids()
{
    int element_id = 0;
    int j = 0;
    std::vector<std::pair<int, int>> indices_and_ids;
    for (int i = 0; i < body.size(); ++i) {
        if (i < length - move_count) {
            element_id = length - 1 - move_count - i;
        } else {
            element_id = length - 1 - j;
            j++;
        }
        indices_and_ids.push_back(std::pair<int, int>(get_snake_piece_idx(element_id), length - 1 - i));
    }
    for (int i = 0; i < body.size(); ++i)
    {
        body[indices_and_ids[i].first].id = indices_and_ids[i].second;
    }
}

void Snake::grow()
{
    sort_by_ids();
    SnakePiece new_one;
    SnakePiece last = body[tail->id];
    SnakePiece after_last = body[tail->id - 1];

    if (after_last.x > last.x) {
        new_one.x = last.x - 1;
        new_one.y = last.y;
    }
    if (after_last.x < last.x) {
        new_one.x = last.x + 1;
        new_one.y = last.y;
    }
    if (after_last.y > last.y) {
        new_one.x = last.x;
        new_one.y = last.y - 1;
    }
    if (after_last.y < last.y) {
        new_one.x = last.x;
        new_one.y = last.y + 1;
    }
    if (s_board.get_tile_info(new_one.x, new_one.y) == 'X') {
        std::pair<int, int> valid = get_valid(new_one.x, new_one.y);
        new_one.x = valid.first;
        new_one.y = valid.second;
    }
    length++;
    new_one.id = length - 1;
    body.push_back(new_one);
    tail = &body[get_snake_piece_idx(length - 1)];
    head = &body[get_snake_piece_idx(0)];
    move_count = 0;
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