#include "SFMLController.hpp"
#include <SFML/Graphics.hpp>

void SFMLController::handle_events(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            ctrl_snake.turn(Direction::LEFT);
        }
        if (event.key.code == sf::Keyboard::Right) {
            ctrl_snake.turn(Direction::RIGHT);
        }
    }
    // if (event.type)
   

}