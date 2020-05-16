#include "MainMenu.hpp"

MainMenu::MainMenu(SnakeBoard &b, Snake &s)
    : board(b),
      snake(s)
{
    int choice = 1;
    current_option = Option(choice);
    current_menu_state = MainMenu::State::GAME_NOT_STARTED;
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

std::string MainMenu::Run(sf::RenderWindow &window)
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
    set_menu_state();
    text_continue.setFillColor(sf::Color::White);
    text_play.setFillColor(sf::Color::White);
    text_ranking.setFillColor(sf::Color::White);
    text_exit.setFillColor(sf::Color::White);
    choice = (current_menu_state == MainMenu::State::GAME_NOT_STARTED) ? 1 : 0;
    current_option = Option(choice);
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return "exit"; //will exit the application in the main function
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                return chosen_screen();
            }
            handle_events(event);
        }
        draw_options(window);
    }
    return "exit"; //normally never reaches this place
}

void MainMenu::set_menu_state() {
    switch (snake.get_game_state()) {
    case Snake::GameState::RUNNING:
        current_menu_state = MainMenu::State::GAME_STARTED;
        break;
    case Snake::GameState::NOT_STARTED:
    case Snake::GameState::FINISHED_LOSS:
        current_menu_state = MainMenu::State::GAME_NOT_STARTED;
    default:
        break;
    }
}

void MainMenu::draw_options(sf::RenderWindow &window)
{
    text_play.setFillColor(sf::Color::White);
    text_continue.setFillColor(sf::Color::White);
    text_ranking.setFillColor(sf::Color::White);
    text_exit.setFillColor(sf::Color::White);
    
    window.clear();

    if (current_option == MainMenu::Option::CONTINUE) {
        text_continue.setFillColor(sf::Color::Red);
    } else if (current_option == MainMenu::Option::NEW_GAME) {
        text_play.setFillColor(sf::Color::Red);
    } else if (current_option == MainMenu::Option::RANKING) {
        text_ranking.setFillColor(sf::Color::Red);
    } else if (current_option == MainMenu::Option::EXIT) {
        text_exit.setFillColor(sf::Color::Red);
    }
    if (current_menu_state == MainMenu::State::GAME_STARTED) {
        window.draw(text_continue);
    }

    window.draw(text_play);
    window.draw(text_ranking);
    window.draw(text_exit);

    window.display();
}

void MainMenu::handle_events(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::Up) {
            choice--;
            choice = (current_menu_state == MainMenu::State::GAME_NOT_STARTED && choice < 1) ? 3 : choice;
            choice = (current_menu_state == MainMenu::State::GAME_STARTED && choice < 0) ? 3 : choice;
            current_option = Option(choice);
        }
        if (event.key.code == sf::Keyboard::Down) {
            choice++;
            choice = (current_menu_state == MainMenu::State::GAME_NOT_STARTED && choice > 3) ? 1 : choice;
            choice = (current_menu_state == MainMenu::State::GAME_STARTED && choice > 3) ? 0 : choice;
            current_option = Option(choice);
        }
    }
}

std::string MainMenu::chosen_screen()
{
    if (current_option == Option::CONTINUE) {
        return "game"; 
    }
    if (current_option == Option::NEW_GAME) {
        if (snake.get_game_state() == Snake::GameState::RUNNING) {
            current_menu_state = MainMenu::State::GAME_STARTED;
        }
        return "mode selection"; 
    }
    if (current_option == Option::RANKING) {
        return "ranking";
    }
    return "exit";
}