#include "ModeSelection.hpp"
#include "MainMenu.hpp"
#include <cerrno>
#include <cstring>
#include <iostream>

ModeSelection::ModeSelection(SnakeBoard &b, Snake &s)
    : board(b),
      snake(s)
{
    if (!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/chandas1-2.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    easy_mode.setFont(font);
    normal_mode.setFont(font);
    hard_mode.setFont(font);
    // text.setFont(font);

    easy_mode.setString("Easy");
    normal_mode.setString("Normal");
    hard_mode.setString("Hard");
    // text.setString("Select game mode");
    choice = 0;
}

int ModeSelection::Run(sf::RenderWindow &window)
{
    const int text_height = easy_mode.getLocalBounds().height;
    const int text_width = easy_mode.getLocalBounds().width;
    const int screen_x_center = window.getSize().x / 2 - text_width / 2;
    const int screen_y_center = window.getSize().y / 2 - text_height / 2;
    sf::Event event;

    // text.setPosition(window.getSize().x / 2 - text.getLocalBounds().width / 2, 2 * text_height);
    easy_mode.setPosition(screen_x_center, screen_y_center - 2 * text_height);
    normal_mode.setPosition(screen_x_center, screen_y_center);
    hard_mode.setPosition(screen_x_center, screen_y_center + 2 * text_height);
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    choice--;
                    choice = (choice < 0) ? 2 : choice;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    choice++;
                    choice = (choice > 2) ? 0 : choice;
                }
                if (event.key.code == sf::Keyboard::Return) {
                    // board.set_game_mode(GameMode(choice));
                    board = SnakeBoard(board.get_height(), board.get_width(), GameMode(choice));
                    snake = Snake(board);
                    std::cout << "\nenter catched on mode selection\n";
                    return 2; //game_screen
                }
            }
        }
        easy_mode.setFillColor(sf::Color::White);
        normal_mode.setFillColor(sf::Color::White);
        hard_mode.setFillColor(sf::Color::White);
        if (choice == 0) {
            easy_mode.setFillColor(sf::Color::Red);
        }
        if (choice == 1) {
            normal_mode.setFillColor(sf::Color::Red);
        }
        if (choice == 2) {
            hard_mode.setFillColor(sf::Color::Red);
        }
        window.clear();
        window.draw(easy_mode);
        window.draw(normal_mode);
        window.draw(hard_mode);

        window.display();
    }
}
