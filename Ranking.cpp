#include "Ranking.hpp"
#include <algorithm>
#include <fstream>
#include <numeric>

void Ranking::load_highscore_list(const std::string &fname)
{
    highscore_list.clear();
    std::ifstream file(fname, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "error opening file " << fname;
        abort();
    }
    player_data p_data;
    int a;
    file.read((char *)&a, sizeof(int));
    while (file.read((char *)&p_data, sizeof(p_data))) {
        highscore_list.push_back(p_data);
    }
    file.close();
    std::sort(highscore_list.begin(), highscore_list.end(), [&](player_data a, player_data b) {
        if (a.score > b.score) {
            return true;
        }
        if (a.score == b.score) {
            return sort(a.mode, b.mode);
        }
        return false;
    });
}

Ranking::Ranking(SnakeBoard &b, Snake &s)
    : board(b),
      snake(s),
      highscore_list(),
      table(sf::Lines, 8),
      cols_x_start(4)
{
    if (!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/chandas1-2.ttf")) {
        std::cerr << "loading font failed \n";
        abort();
    }
    text.setFont(font);
    text.setString("Example Text");
    text.setFillColor(sf::Color::White);
    cols_x_start[0] = 0;
    cols_x_start[1] = (text.getCharacterSize() * 2);
    cols_x_start[2] = cols_x_start[1] + (text.getCharacterSize() * 15);
    cols_x_start[3] = cols_x_start[2] + (text.getCharacterSize() * 6);
    current_option = option::MAIN_MENU;
    choice = 0;
}

int Ranking::Run(sf::RenderWindow &window)
{
    load_highscore_list(snake.get_fname());
    set_table(window);
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return 0; //main menu
            }
        }
        window.clear();

        draw(window);

        window.display();
    }
    return -1; //will never reach this point
}

void Ranking::draw(sf::RenderWindow &window)
{
    text.setString("Press escape to go back to menu");
    text.setPosition((window.getSize().x - text.getLocalBounds().width) / 2, text.getCharacterSize());
    window.draw(text);
    window.draw(table);
    draw_header(window);
    draw_scores(window);
}

void Ranking::set_table(sf::RenderWindow &window)
{
    int table_height = 20 * text.getLocalBounds().height + 10;
    int table_width = cols_x_start.back() + text.getCharacterSize() * 5; //x coordinate of the last column + space for it
    int table_x_indent = (window.getSize().x - table_width) / 2;
    int table_y_indent = (text.getLocalBounds().height * 5) + text.getCharacterSize();
    int vertical_lines_indent = table_y_indent - (text.getLocalBounds().height + 5);

    //horizontal line
    table[0].position = sf::Vector2f(table_x_indent, table_y_indent);
    table[1].position = sf::Vector2f(table_x_indent + table_width, table_y_indent);
    //1st vertical line
    table[2].position = sf::Vector2f(table_x_indent + cols_x_start[1], vertical_lines_indent);
    table[3].position = sf::Vector2f(table_x_indent + cols_x_start[1], table_y_indent + table_height);
    //2nd vertical line
    table[4].position = sf::Vector2f(table_x_indent + cols_x_start[2], vertical_lines_indent);
    table[5].position = sf::Vector2f(table_x_indent + cols_x_start[2], table_y_indent + table_height);
    //3rd vertical line
    table[6].position = sf::Vector2f(table_x_indent + cols_x_start[3], vertical_lines_indent);
    table[7].position = sf::Vector2f(table_x_indent + cols_x_start[3], table_y_indent + table_height);
}

void Ranking::draw_scores(sf::RenderWindow &window)
{
    int table_x_indent = table[0].position.x;
    int table_y_indent = table[0].position.y;
    for (size_t row = 0; row < highscore_list.size(); ++row) {
        for (size_t col = 0; col < 4; ++col) {
            fill_table(text, col, row);
            text.setPosition(table_x_indent + cols_x_start[col], table_y_indent + 2 * row * text.getCharacterSize());
            window.draw(text);
        }
    }
}

void Ranking::draw_header(sf::RenderWindow &window)
{
    int table_x_indent = table[0].position.x;
    int table_y_indent = table[0].position.y;
    text.setFillColor(sf::Color::Yellow);
    for (size_t col = 0; col < cols_x_start.size(); ++col) {
        fill_header(text, col);
        text.setPosition(table_x_indent + cols_x_start[col], table_y_indent - (text.getCharacterSize() + 5));
        window.draw(text);
    }
    text.setFillColor(sf::Color::White);
}

void Ranking::fill_header(sf::Text &text, int col)
{
    if (col == 0) {
        text.setString("No.");
    }
    if (col == 1) {
        text.setString("Nickname");
    }
    if (col == 2) {
        text.setString("Mode");
    }
    if (col == 3) {
        text.setString("Score");
    }
}

void Ranking::fill_table(sf::Text &text, int col, int row)
{
    if (col == 0) {
        text.setString(std::to_string(row + 1));
    }
    if (col == 1) {
        text.setString(highscore_list[row].name);
    }
    if (col == 2) {
        text.setString(highscore_list[row].mode);
    }
    if (col == 3) {
        text.setString(std::to_string(highscore_list[row].score));
    }
}

bool Ranking::sort(const char *lhs, const char *rhs)
{
    if (lhs == static_cast<std::string>("HARD")) {
        return true;
    }
    if (lhs == static_cast<std::string>("NORMAL")) {
        if (rhs == static_cast<std::string>("HARD")) {
            return false;
        }
        if (rhs == static_cast<std::string>("NORMAL")) {
            return true;
        }
        if (rhs == static_cast<std::string>("EASY")) {
            return true;
        }
    }
    if (lhs == static_cast<std::string>("EASY")) {
        if (rhs == static_cast<std::string>("HARD")) {
            return false;
        }
        if (rhs == static_cast<std::string>("NORMAL")) {
            return false;
        }
        if (rhs == static_cast<std::string>("EASY")) {
            return true;
        }
    }
    return false; //will not come to this
}