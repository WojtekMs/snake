#include "Snake.hpp"

Snake::Snake(SnakeBoard &board)
    : length(4),
      body(length),
      s_board(board)
{
    body[0].x = s_board.get_width() / 2 - 1;
    body[0].y = s_board.get_height() / 2 - 1;
    for (int i = 1; i < length; ++i)
    {
        body[i].x = body[0].x - i;
        body[i].y = body[0].y;
    }

    head_x = body[0].x;
    head_y = body[0].y;
    tail_x = body[length - 1].x;
    tail_y = body[length - 1].y;
    current_dir = Direction::RIGHT;
    prev_dir = current_dir;
    speed = 2;
}

void Snake::change_direction(Direction dir)
{
    if (!(dir == Direction::RIGHT || dir == Direction::LEFT))
    {
        std::cout << "wybrales zly kierunek! \n";
        return;
    }
    prev_dir = current_dir;
    if (dir == Direction::RIGHT)
    {
        if (current_dir == Direction::RIGHT)
        {
            current_dir = Direction::DOWN;
        }
        else if (current_dir == Direction::DOWN)
        {
            current_dir = Direction::LEFT;
        }

        else if (current_dir == Direction::LEFT)
        {
            current_dir = Direction::UP;
        }

        else if (current_dir == Direction::UP)
        {
            current_dir = Direction::RIGHT;
        }
    }
    else
    {
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
    std::cout << std::endl;
    if (prev_dir == Direction::RIGHT)
        std::cout << "prev: right";
    if (prev_dir == Direction::DOWN)
        std::cout << "prev: down";
    if (prev_dir == Direction::LEFT)
        std::cout << "prev: left";
    if (prev_dir == Direction::UP)
        std::cout << "prev: up";
    std::cout << "\n-------------------------\n";
}

void Snake::move()
{
    // int last_idx, first_idx = 0;
    // last_idx = get_snake_piece_idx(tail_x, tail_y);
    // first_idx = get_snake_piece_idx(head_x, head_y);
    // int after_tail_x = body[length - 2].x;
    // int after_tail_y = body[length - 2].y;
    //if (prev_dir == Direction::RIGHT)
    // {
    std::pair<int, int> even_idx, odd_idx;
    even_idx.first = body[0].x;
    even_idx.second = body[0].y;
    if (current_dir == Direction::RIGHT)
    {
        body[0].x += 1;
    }
    if (current_dir == Direction::DOWN)
    {
        body[0].y += 1;
    }
    if (current_dir == Direction::LEFT)
    {
        body[0].x -= 1;
    }
    if (current_dir == Direction::UP)
    {
        body[0].y -= 1;
    }
    for (int idx = 1; idx < length; ++idx)
    {
        if (idx % 2 != 0)
        {
            odd_idx.first = body[idx].x;
            odd_idx.second = body[idx].y;
            body[idx].x = even_idx.first;
            body[idx].y = even_idx.second;
        }
        else
        {
            even_idx.first = body[idx].x;
            even_idx.second = body[idx].y;
            body[idx].x = odd_idx.first;
            body[idx].y = odd_idx.second;
        }
        if (idx == length - 1)
        {
            tail_x = body[idx].x;
            tail_y = body[idx].y;
        }
    }

    // after_tail_x = tail_x + 1;
    // after_tail_y = tail

    //     // tail_x = head_x + 1;
    //     // tail_y = head_y;
    //     temp_x = body[0].x;
    //     temp_y = body[0].y;
    //     body[0].x += 1;
    //     for (int i = 1; i < length; ++i)
    //     {
    //         temp_x2 = body[i].x;
    //         temp_y2 = body[i].y;
    //         body[i].x = body[i - 1].x;
    //         body[i].y = body[i - 1].y;
    //         temp_x = body[i].x;
    //         temp_y = body[i].y;

    //     }

    //     body[last_idx].x = body[first_idx].x + 1;
    //     body[last_idx].y = body[last_idx].y;
    //     head_x += 1;
    // }
    // if (current_dir == Direction::DOWN)
    // {
    //     // tail_x = head_x;
    //     // tail_y = head_y + speed;
    // }
    // if (current_dir == Direction::LEFT)
    // {
    //     tail_x = head_x - speed;
    //     tail_y = head_y;
    // }
    // if (current_dir == Direction::UP)
    // {
    //     tail_x = head_x;
    //     tail_y = head_y + speed;
    // }

    // }
    // if (current_dir == Direction::RIGHT)
    // {
    //     tail_x = head_x + speed;
    //     tail_y = head_y;
    // }

    // if (current_dir == Direction::LEFT)
    // {
    //     tail_x = head_x - speed;
    //     tail_y =
    // }
}

bool Snake::contains(int col, int row) const
{
    for (int i = 0; i < length; ++i)
    {
        if (body[i].x == col && body[i].y == row)
            return true;
    }
    return false;
}

int Snake::get_snake_piece_idx(int col, int row) const
{
    for (int i = 0; i < length; ++i)
    {
        if (body[i].x == col && body[i].y == row)
            return i;
    }
    return -1;
}

void Snake::grow()
{
    SnakePiece new_one;
    SnakePiece last = body[length - 1];
    SnakePiece after_last = body[length - 2];
    if (after_last.x > last.x)
    {
        new_one.x = last.x - 1;
        new_one.y = last.y;
    }
    if (after_last.x < last.x)
    {
        new_one.x = last.x + 1;
        new_one.y = last.y;
    }
    if (after_last.y > last.y)
    {
        new_one.x = last.x;
        new_one.y = last.y - 1;        
    }
    if (after_last.y < last.y)
    {
        new_one.x = last.x;
        new_one.y = last.y + 1;
    }
    body.push_back(new_one);
    length++;
}