#ifndef tests_hpp_
#define tests_hpp_

#include "Debug_view.hpp"
#include "Snake.hpp"
#include "SFMLView.hpp"
#include <SFML/Graphics.hpp>
#include "SFMLController.hpp"

void snake_tests(Snake & s, const Debug_view & view);
void sfml_tests(SFMLView & sfml_view, SFMLController & sfml_ctrl, Snake & snake);

#endif //tests_hpp_