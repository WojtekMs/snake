#include "Debug_view.hpp"

void Debug_view::display() const
{
    for (int row = 0; row < v_board.get_height(); ++row)
    {
        for (int col = 0; col < v_board.get_width(); ++col)
        {
            std::cout << "[ ";
            if (v_board.get_tile_info(col, row) == 'X')
                std::cout << "X";
            if (v_board.get_tile_info(col, row) == 'F')
                std::cout << "F";
            if (v_board.get_tile_info(col, row) == ' ')
                std::cout << " ";

            std::cout << " ]";
        }
        std::cout << std::endl;
    }
}
