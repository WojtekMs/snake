cmake_minimum_required(VERSION 3.10)

project(snake)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_OUTPUT_PATH ../)

find_package(SFML 2 COMPONENTS window graphics audio REQUIRED)

add_compile_options(-Wall -Wextra)

add_executable(a.out main.cpp SnakeBoard.cpp Snake.cpp Debug_view.cpp SFMLView.cpp SFMLController.cpp tests.cpp) 

target_link_libraries(a.out sfml-system sfml-window sfml-graphics sfml-audio)

