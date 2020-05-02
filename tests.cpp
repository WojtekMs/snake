#include "tests.hpp"
#include "Snake.hpp"
#include <vector>

void snake_tests(Snake &snake, const Debug_view &view)
{
    //std::vector<SnakePiece> test = {{1, 7, 0}, {2, 5, 1}, {3, 3, 10}, {5, 5, 2}};
    view.display();
    // snake.grow();
    snake.move();
    snake.move();
    // view.display();
    // snake.grow();
    // view.display();
    snake.move();
    snake.move();
    // view.display();
    // snake.grow();
    
    // snake.grow();
    // // // for (int i = 0; i < 9; ++i)
    snake.move();
    snake.move();
    // // // snake.move();
    // view.display();
    // // snake.grow();
    // // snake.grow();
    // // view.display();

    // snake.change_direction(Direction::RIGHT);
    // // // // // snake.display_dir();
    snake.move();
    snake.move();
    snake.move();
    snake.move();
    snake.change_direction(Direction::LEFT);
    snake.move();
    snake.move();
    // snake.move();
    view.display();
    // snake.grow();
    // snake.grow();
    // snake.grow();
    // snake.move();
    // snake.move();
    // snake.move();
    // snake.move();
    // snake.change_direction(Direction::LEFT);
    // snake.move();
    // snake.move();
    // snake.move();
    // snake.move();
    // view.display();
    // snake.grow();
    // view.display();
    // snake.move();
    // snake.move();
    // snake.move();
    // view.display();
    // // snake.grow();

    // // snake.change_direction(Direction::LEFT);
    // // snake.move();
    // snake.change_direction(Direction::RIGHT);
    // snake.move();
    // snake.move();
    // snake.move();
    // view.display();
    // snake.change_direction(Direction::LEFT);
    // snake.move();
    // snake.move();
    // // snake.move();
    // // snake.move();
    // snake.move();
    // snake.change_direction(Direction::LEFT);
    // snake.move();
    // snake.move();
    // // snake.move();
    // view.display();
    // // Direction current = snake.get_current_dir();
    // // Direction prev = snake.get_prev_dir();
}
