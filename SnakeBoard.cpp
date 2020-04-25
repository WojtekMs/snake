#include "SnakeBoard.hpp"
#include <iostream>

void SnakeBoard::set_size(int h, int w)
{
    if (h > 50)
    {
        std::cout << "zla wysokosc! ustawiam na 20 \n";
        height = 20;
    }
    if (w > 50)
    {
        std::cout << "zla szerokosc! ustawiam na 20 \n";
        width = 20;
    }
    height = h;
    width = w;
}

void SnakeBoard::set_default_board()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            board[row][col].has_food = false;
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1)
                board[row][col].has_obstacle = true;
            else
                board[row][col].has_obstacle = false;
        }
    }
}

void SnakeBoard::draw_food()
{

    int row = rand() % height, col = rand() % width;
    while (!is_inside(col, row))
    {
        row = rand() % height, col = rand() % width;
    }
    board[row][col].has_food = true;
}

bool SnakeBoard::is_inside(int col, int row) const
{
    if (col > 1 && col < width - 1)
        if (row > 1 && row < height - 1)
            return true;
    return false;
}

bool SnakeBoard::out_of_range(int col, int row) const
{
    if (col < 0 || col > width)
        return true;
    if (row < 0 || row > height)
        return true;
    return false;
}

SnakeBoard::SnakeBoard(int h, int w, GameMode mode)
    : height(h),
      width(w),
      board(w, h),
      food(false)
{
    set_size(h, w);
    set_default_board();
    draw_food();
    current_game_mode = mode;
    current_game_state = RUNNING;
}

void SnakeBoard::debug_display() const
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            std::cout << "[ ";
            if (board[row][col].has_obstacle)
                std::cout << "X";
            else if (board[row][col].has_food)
                std::cout << "F";
            else
                std::cout << " ";

            std::cout << " ]";
        }
        std::cout << std::endl;
    }
}

void SnakeBoard::debug_eat_food()
{
    for (int row = 1; row < height - 1; ++row)
        for (int col = 1; col < width - 1; ++col)
            if (board[row][col].has_food)
            {
                board[row][col].has_food = false;
                draw_food();
            }
}

char SnakeBoard::get_tile_info(int col, int row) const
{
    if(out_of_range(col, row))
        return '#';
    if (board[row][col].has_obstacle)
        return 'X';
    if (board[row][col].has_food)
        return 'F';
    return ' ';
    
}