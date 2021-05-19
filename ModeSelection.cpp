#include "ModeSelection.hpp"

#include "MainMenu.hpp"
#include "config.hpp"

#include <cerrno>
#include <cstring>
#include <iostream>

ModeSelection::ModeSelection(SnakeBoard& b, Snake& s) : board(b), snake(s), nickname()
{
    if (!font.loadFromFile(config::font_path)) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    easy_mode.setFont(font);
    normal_mode.setFont(font);
    hard_mode.setFont(font);
    text.setFont(font);
    nickname_drawn.setFont(font);

    easy_mode.setString("Easy");
    normal_mode.setString("Normal");
    hard_mode.setString("Hard");
    text.setString("Select game mode and enter your nickname [max 20 char]!");

    nickname_drawn.setFillColor(sf::Color::Black);

    text_box.setSize(
        sf::Vector2f(text.getCharacterSize() * 15, text.getLocalBounds().height + 10));
    text_box.setFillColor(sf::Color::White);
    choice = 0;
}

std::string ModeSelection::Run(sf::RenderWindow& window)
{
    const int text_height = easy_mode.getLocalBounds().height;
    const int text_width = easy_mode.getLocalBounds().width;
    const int screen_x_center = window.getSize().x / 2 - text_width / 2;
    const int screen_y_center = window.getSize().y / 2 - text_height / 2;

    text_box.setPosition(screen_x_center - text.getCharacterSize() * 6, 4 * text_height);
    nickname_drawn.setPosition(screen_x_center - text.getCharacterSize() * 6,
                               4 * text_height);
    text.setPosition(window.getSize().x / 2 - text.getLocalBounds().width / 2,
                     2 * text_height);
    easy_mode.setPosition(screen_x_center, screen_y_center - 2 * text_height);
    normal_mode.setPosition(screen_x_center, screen_y_center);
    hard_mode.setPosition(screen_x_center, screen_y_center + 2 * text_height);

    nickname.clear();
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return "exit";
            }
            if (nickname.length() > 0) {
                if (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Return) {
                    board = SnakeBoard(board.get_height(),
                                       board.get_width(),
                                       SnakeBoard::GameMode(choice));
                    snake = Snake(board);
                    snake.set_name(nickname);
                    return "game";  // game_screen
                }
            }
            handle_events(event);
        }
        window.clear();

        draw(window);

        window.display();
    }
}

void ModeSelection::draw(sf::RenderWindow& window)
{
    easy_mode.setFillColor(sf::Color::White);
    normal_mode.setFillColor(sf::Color::White);
    hard_mode.setFillColor(sf::Color::White);

    nickname_drawn.setString(nickname);

    if (choice == 0) {
        easy_mode.setFillColor(sf::Color::Red);
    }
    if (choice == 1) {
        normal_mode.setFillColor(sf::Color::Red);
    }
    if (choice == 2) {
        hard_mode.setFillColor(sf::Color::Red);
    }

    window.draw(easy_mode);
    window.draw(normal_mode);
    window.draw(hard_mode);
    window.draw(text);
    window.draw(text_box);
    window.draw(nickname_drawn);
}

void ModeSelection::handle_events(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            choice--;
            choice = (choice < 0) ? 2 : choice;
        }
        if (event.key.code == sf::Keyboard::Down) {
            choice++;
            choice = (choice > 2) ? 0 : choice;
        }
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode > 31 && event.text.unicode < 128 && nickname.size() < 21) {
            nickname += event.text.unicode;
        }
        if (event.text.unicode == '\b' && !nickname.empty()) {
            nickname.pop_back();
        }
    }
}
