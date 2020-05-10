#include "MainMenu.hpp"

MainMenu::MainMenu(SnakeBoard &b, Snake &s)
    : board(b),
      snake(s)
{
    running = true;
    int choice = 1;
    current_option = option(choice);
    current_menu_state = menu_state::FIRST;
    if (!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/chandas1-2.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    text_play.setFont(font);
    text_play.setString("New Game");
    text_continue.setFont(font);
    text_continue.setString("Continue");
    text_ranking.setFont(font);
    text_ranking.setString("Ranking");
    text_exit.setFont(font);
    text_exit.setString("Exit");
}

int MainMenu::Run(sf::RenderWindow &window)
{
    const int screen_height = window.getSize().y;
    const int screen_width = window.getSize().x;
    const int text_height = text_play.getLocalBounds().height;
    const int text_width = text_play.getLocalBounds().width;
    const int screen_x_center = screen_width / 2 - text_width / 2;
    const int screen_y_center = screen_height / 2 - text_height / 2;
    text_continue.setPosition(screen_x_center, screen_y_center - 4 * text_height);
    text_play.setPosition(screen_x_center, screen_y_center - 2 * text_height);
    text_ranking.setPosition(screen_x_center, screen_y_center);
    text_exit.setPosition(screen_x_center, screen_y_center + 2 * text_height);

    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return -1; //will exit the application in the main function
            }
            if (event.type == sf::Event::KeyPressed) {

                if (event.key.code == sf::Keyboard::Up) {
                    choice--;
                    choice = (current_menu_state == menu_state::FIRST && choice < 1) ? 3 : choice;
                    choice = (current_menu_state == menu_state::STARTED && choice < 0) ? 3 : choice;
                    // choice = (choice < 1) ? 3 : choice;
                    current_option = option(choice);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    choice++;
                    choice = (current_menu_state == menu_state::FIRST && choice > 3) ? 1 : choice;
                    choice = (current_menu_state == menu_state::STARTED && choice > 3) ? 0 : choice;
                    // choice = (choice > 3) ? 1 : choice;
                    current_option = option(choice);
                }
                if (event.key.code == sf::Keyboard::Return) { //enter key
                    if (current_option == option::CONTINUE) {
                        return 2; //game screen
                    }
                    if (current_option == option::NEW_GAME) {
                        current_menu_state = menu_state::STARTED;
                        // std::cout << "\n enter catched in new game main menu option \n";
                        return 1; //go to mode_selection
                    }
                    if (current_option == option::RANKING) {
                        return 2;
                    }
                    if (current_option == option::EXIT) {
                        return -1;
                    }
                }
            }
        }
        text_play.setFillColor(sf::Color::White);
        text_continue.setFillColor(sf::Color::White);
        text_ranking.setFillColor(sf::Color::White);
        text_exit.setFillColor(sf::Color::White);
        window.clear();
        if (current_option == option::CONTINUE) {
            text_continue.setFillColor(sf::Color::Red);
        } else if (current_option == option::NEW_GAME) {
            text_play.setFillColor(sf::Color::Red);
        } else if (current_option == option::RANKING) {
            text_ranking.setFillColor(sf::Color::Red);
        } else if (current_option == option::EXIT) {
            text_exit.setFillColor(sf::Color::Red);
        }
        if (current_menu_state == menu_state::STARTED) {
            window.draw(text_continue);
        }
        window.draw(text_play);
        window.draw(text_ranking);
        window.draw(text_exit);

        window.display();
    }
    return -1; //normally never reaches this place
}
