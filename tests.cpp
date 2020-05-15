#include "tests.hpp"
#include "Snake.hpp"
#include <iostream>
#include <vector>

// void snake_tests(Snake &snake, const Debug_view &view)
// {
//     //std::vector<SnakePiece> test = {{1, 7, 0}, {2, 5, 1}, {3, 3, 10}, {5, 5, 2}};
//     view.display();
//     // // snake.grow();
//     // snake.move();
//     // snake.move();
//     // // view.display();
//     // snake.grow();
//     // // view.display();
//     // snake.move();
//     // snake.move();
//     // view.display();
//     // snake.grow();

//     // snake.grow();
//     // // // for (int i = 0; i < 9; ++i)
//     // snake.move();
//     // snake.move();
//     // // // snake.move();
//     // view.display();
//     // // snake.grow();
//     // // snake.grow();
//     // // view.display();

//     // snake.turn(Direction::RIGHT);
//     // // // // // snake.display_dir();
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     // snake.turn(Direction::LEFT);
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     view.display();
//     // snake.grow();
//     // snake.grow();
//     // snake.grow();
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     // snake.turn(Direction::LEFT);
//     // snake.move();
//     // snake.move();
//     // // snake.move();
//     // snake.move();
//     view.display();
//     // snake.grow();
//     // view.display();
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     // view.display();
//     // // snake.grow();

//     // // snake.turn(Direction::LEFT);
//     // // snake.move();
//     // snake.turn(Direction::RIGHT);
//     // snake.move();
//     // snake.move();
//     // snake.move();
//     // view.display();
//     // snake.turn(Direction::LEFT);
//     // snake.move();
//     // snake.move();
//     // // snake.move();
//     // // snake.move();
//     // snake.move();
//     // snake.turn(Direction::LEFT);
//     // snake.move();
//     // snake.move();
//     // // snake.move();
//     // view.display();
//     // // Direction current = snake.get_current_dir();
//     // // Direction prev = snake.get_prev_dir();
// }

// void sfml_tests(Game & sfml_view, SFMLController & sfml_ctrl, Snake & snake)
// {
//     sf::RenderWindow window(sf::VideoMode(sfml_view.get_window_width(), sfml_view.get_window_height()), "test snake");
//     // sf::RenderWindow window(sf::VideoMode())
//     sf::Clock clock;

//     while (window.isOpen()) {
//         sf::Event event;

//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//                 continue;
//             }
//             // place for sfml_controller.handle_events()
//             sfml_ctrl.handle_events(event);
//         }
//         window.clear();

//         // sfml_view.update(clock.restart());
//         snake.update(clock.restart());

//         sfml_view.display(window);

//         window.display();
//     }
// }

void screen_tests(SnakeBoard &board, Snake &snake)
{
    int screen = 0;
    // window.setMouseCursorVisible(false);
    std::vector<cScreen *> screens;
    MainMenu menu(board, snake);
    ModeSelection mode_selec(board, snake);
    Ranking ranking(board, snake);
    Game game(board, snake);
    screens.push_back(&menu); //0
    screens.push_back(&mode_selec); //1
    screens.push_back(&ranking); //2
    screens.push_back(&game); //3
    sf::RenderWindow window(sf::VideoMode(game.get_window_width(), game.get_window_height()), "screen tests");

    while (screen >= 0) {
        screen = screens[screen]->Run(window);
    }
}
