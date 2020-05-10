#include "SnakeBoard.hpp"
#include <algorithm>
#include <iostream>

void SnakeBoard::set_size(int h, int w)
{
    if (h > 50) {
        std::cout << "zla wysokosc! ustawiam na 20 \n";
        height = 20;
    }
    if (w > 50) {
        std::cout << "zla szerokosc! ustawiam na 20 \n";
        width = 30;
    }
    height = h;
    width = w;
}

void SnakeBoard::set_board_obstacles()
{
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1)
                board_obstacles[row][col] = true;
            else
                board_obstacles[row][col] = false;
        }
    }

    int horizontal_g_size = (int((width - 2) * 0.2069 + 0.5));
    for (int i = 0; i < horizontal_g_size; ++i) {
        board_obstacles[0][(width - horizontal_g_size) / 2 + i] = false;
        board_obstacles[height - 1][(width - horizontal_g_size) / 2 + i] = false;
        horizontal_gate_x.push_back((width - horizontal_g_size) / 2 + i);
    }

    int vertical_g_size = (int((height - 2) * 0.2222 + 0.5));
    for (int i = 0; i < vertical_g_size; ++i) {
        board_obstacles[(height - vertical_g_size) / 2 + i][0] = false;
        board_obstacles[(height - vertical_g_size) / 2 + i][width - 1] = false;
        vertical_gate_y.push_back((height - vertical_g_size) / 2 + i);
    }

    if (current_game_mode == GameMode::NORMAL || current_game_mode == GameMode::HARD) {
        int obstacle_1_size = int(height * 0.6 + 0.5); // |     |
        int distance_between_obstacles_1 = width * 0.6;
        if (distance_between_obstacles_1 % 2 == 0) {
            distance_between_obstacles_1 += 1;
        }
        int obstacle_1_left_horizontal_indent = (width - 4 - distance_between_obstacles_1) / 2;
        int obstacle_1_right_horizontal_indent = obstacle_1_left_horizontal_indent;
        if (obstacle_1_left_horizontal_indent % 2 != 0) {
            obstacle_1_right_horizontal_indent = obstacle_1_left_horizontal_indent + 1;
        }
        int obstacle_1_vertical_indent = (height - obstacle_1_size) / 2;
        for (int i = 0; i < obstacle_1_size; ++i) {
            board_obstacles[i + obstacle_1_vertical_indent][obstacle_1_left_horizontal_indent + 1] = true;
            board_obstacles[i + obstacle_1_vertical_indent][width - 2 - obstacle_1_right_horizontal_indent] = true;
        }

        int obstacle_2_outer_denting = distance_between_obstacles_1 / 2 * 0.1111; // ---  ---
        obstacle_2_outer_denting = (obstacle_2_outer_denting < 1) ? 1 : obstacle_2_outer_denting;
        int obstacle_2_inner_denting = distance_between_obstacles_1 / 2 * 0.2222;
        obstacle_2_inner_denting = (obstacle_2_inner_denting < 2) ? 2 : obstacle_2_inner_denting;
        int obstacle_2_size = (distance_between_obstacles_1 - 2 * obstacle_2_outer_denting - obstacle_2_inner_denting) / 2;
        for (int i = 0; i < obstacle_2_size; ++i) {
            board_obstacles[height / 2 - 1][i + obstacle_1_left_horizontal_indent + 1 + obstacle_2_outer_denting + 1] = true;
            board_obstacles[height / 2 - 1][width - 2 - obstacle_1_right_horizontal_indent - obstacle_2_outer_denting - 1 - i] = true;
        }

        if (current_game_mode == GameMode::HARD) { // x x x x x
            for (int i = 0; i < distance_between_obstacles_1 / 2 + 1; ++i) {
                board_obstacles[obstacle_1_vertical_indent][2 * i + obstacle_1_left_horizontal_indent + 2] = true;
                board_obstacles[obstacle_1_vertical_indent + obstacle_1_size - 1][2 * i + obstacle_1_left_horizontal_indent + 2] = true;
            }
        }
    }
}

void SnakeBoard::draw_food()
{

    int row = rand() % height, col = rand() % width;
    while (get_tile_info(col, row) == 'X') {
        row = rand() % height, col = rand() % width;
    }
    food_x = col;
    food_y = row;
}

bool SnakeBoard::out_of_range(int col, int row) const
{
    if (col == 0 || col == width - 1) {
        if (std::find(vertical_gate_y.begin(), vertical_gate_y.end(), row) != vertical_gate_y.end()) {
            return false;
        }
    }
    if (row == 0 || row == height - 1) {
        if (std::find(horizontal_gate_x.begin(), horizontal_gate_x.end(), col) != horizontal_gate_x.end()) {
            return false;
        }
    }
    if (col < 0 || col > width - 1)
        return true;
    if (row < 0 || row > height - 1)
        return true;
    return false;
}

SnakeBoard::SnakeBoard(int h, int w, GameMode mode)
    : height(h),
      width(w),
      board_obstacles(w, h),
      horizontal_gate_x(),
      vertical_gate_y(),
      current_game_mode(mode)
{
    set_size(h, w);
    set_board_obstacles();
    draw_food();
}

char SnakeBoard::get_tile_info(int col, int row) const
{
    if (out_of_range(col, row))
        return '#';
    if (col == food_x && row == food_y)
        return 'F';
    if (board_obstacles[row][col])
        return 'X';
    if (row == 0 && std::find(horizontal_gate_x.begin(), horizontal_gate_x.end(), col) != horizontal_gate_x.end())
        return 'T';
    if (row == height - 1 && std::find(horizontal_gate_x.begin(), horizontal_gate_x.end(), col) != horizontal_gate_x.end())
        return 'B';
    if (col == 0 && std::find(vertical_gate_y.begin(), vertical_gate_y.end(), row) != vertical_gate_y.end())
        return 'L';
    if (col == width - 1 && std::find(vertical_gate_y.begin(), vertical_gate_y.end(), row) != vertical_gate_y.end())
        return 'R';

    return ' ';
}
