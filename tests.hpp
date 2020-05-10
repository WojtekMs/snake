#ifndef tests_hpp_
#define tests_hpp_

#include "Debug_view.hpp"
#include "Snake.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "SFMLController.hpp"
#include "Screens.hpp"

void snake_tests(Snake & s, const Debug_view & view);
void sfml_tests(Game & sfml_view, SFMLController & sfml_ctrl, Snake & snake);
void screen_tests(SnakeBoard & board, Snake & snake);

#endif //tests_hpp_