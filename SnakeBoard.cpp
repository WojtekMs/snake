#include "SnakeBoard.hpp"
#include <iostream>
#include <algorithm>

void SnakeBoard::set_size(int h, int w)
{
    if (h > 50) {
        std::cout << "zla wysokosc! ustawiam na 20 \n";
        height = 20;
    }
    if (w > 50) {
        std::cout << "zla szerokosc! ustawiam na 20 \n";
        width = 20;
    }
    height = h;
    width = w;
}

void SnakeBoard::set_board()
{
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            board[row][col].has_food = false;
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1)
                board[row][col].has_obstacle = true;
            else
                board[row][col].has_obstacle = false;
        }
    }
   
    for (int i = 0; i < horizontal_g_size; ++i)
    {
        board[0][(width - horizontal_g_size) / 2 + i].has_obstacle = false;
        board[height - 1][(width - horizontal_g_size) / 2 + i].has_obstacle = false;
        horizontal_gate_x[i] = (width - horizontal_g_size) / 2 + i;
    }
    for (int i = 0; i < vertical_g_size; ++i)
    {
        board[(height - vertical_g_size) / 2 + i][0].has_obstacle = false;
        board[(height - vertical_g_size) / 2 + i][width - 1].has_obstacle = false;
        vertical_gate_y[i] = (height - vertical_g_size) / 2 + i;

    }

    if (current_game_mode == GameMode::NORMAL || current_game_mode == GameMode::HARD) {
        int obstacle_1_size = int(height * 0.6 + 0.5); // |     |
        int distance_between_obstacles_1 = width * 0.6;
        if (distance_between_obstacles_1 % 2 == 0){
            distance_between_obstacles_1 += 1;
        }
        int obstacle_1_left_horizontal_indent = (width - 4 - distance_between_obstacles_1) / 2;
        int obstacle_1_right_horizontal_indent = obstacle_1_left_horizontal_indent;
        if (obstacle_1_left_horizontal_indent % 2 != 0) {
            obstacle_1_right_horizontal_indent = obstacle_1_left_horizontal_indent + 1;
        } 
        int obstacle_1_vertical_indent = (height - obstacle_1_size) / 2;
        for (int i = 0; i < obstacle_1_size; ++i) {
            board[i + obstacle_1_vertical_indent][obstacle_1_left_horizontal_indent + 1].has_obstacle = true;
            board[i + obstacle_1_vertical_indent][width - 2 - obstacle_1_right_horizontal_indent].has_obstacle = true;
        }

        int obstacle_2_outer_denting = distance_between_obstacles_1 / 2 * 0.1111; // ---  ---
        obstacle_2_outer_denting = (obstacle_2_outer_denting < 1) ? 1 : obstacle_2_outer_denting;
        int obstacle_2_inner_denting = distance_between_obstacles_1 / 2 * 0.2222;
        obstacle_2_inner_denting = (obstacle_2_inner_denting < 2) ? 2 : obstacle_2_inner_denting;
        int obstacle_2_size = (distance_between_obstacles_1 - 2 * obstacle_2_outer_denting - obstacle_2_inner_denting) / 2;
        for (int i = 0; i < obstacle_2_size; ++i) {
            board[height / 2 - 1][i + obstacle_1_left_horizontal_indent + 1 + obstacle_2_outer_denting + 1].has_obstacle = true;
            board[height / 2 - 1][width - 2 - obstacle_1_right_horizontal_indent - obstacle_2_outer_denting - 1 - i].has_obstacle = true;
        }

        if (current_game_mode == GameMode::HARD) { // x x x x x 
            for (int i = 0; i < distance_between_obstacles_1 / 2 + 1; ++i) {
                    board[obstacle_1_vertical_indent - 1][2 * i + obstacle_1_left_horizontal_indent + 2].has_obstacle = true;
                    board[obstacle_1_vertical_indent + obstacle_1_size][2 * i + obstacle_1_left_horizontal_indent + 2].has_obstacle = true;
            }
        }
    }
}

void SnakeBoard::draw_food()
{

    int row = rand() % height, col = rand() % width;
    while (!is_inside(col, row)) {
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
      horizontal_g_size(int((width - 2) * 0.2069 + 0.5)),
      vertical_g_size(int((height - 2) * 0.2222 + 0.5)),
      board(w, h),
      horizontal_gate_x(horizontal_g_size),
      vertical_gate_y(vertical_g_size),
      current_game_mode(mode),
      food(false)
{
    set_size(h, w);
    set_board();
    draw_food();
}

void SnakeBoard::debug_display() const
{
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
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
            if (board[row][col].has_food) {
                board[row][col].has_food = false;
                draw_food();
            }
}

char SnakeBoard::get_tile_info(int col, int row) const
{
    if (out_of_range(col, row))
        return '#';
    if (row == 0 && std::find(horizontal_gate_x.begin(), horizontal_gate_x.end(), col) != horizontal_gate_x.end())
        return 'T';
    if (row == height - 1 && std::find(horizontal_gate_x.begin(), horizontal_gate_x.end(), col) != horizontal_gate_x.end())
        return 'B';
    if (col == 0 && std::find(vertical_gate_y.begin(), vertical_gate_y.end(), row) != vertical_gate_y.end())
        return 'L';
    if (col == width - 1 && std::find(vertical_gate_y.begin(), vertical_gate_y.end(), row) != vertical_gate_y.end())
        return 'R';
    if (board[row][col].has_obstacle)
        return 'X';
    if (board[row][col].has_food)
        return 'F';
    return ' ';
}