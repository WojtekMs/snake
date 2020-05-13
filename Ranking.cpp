#include "Ranking.hpp"
#include <fstream>

void Ranking::load_highscore_list(const std::string &fname)
{
    std::ifstream file(fname, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "error opening file " << fname;
        abort();
    }
    player_data p_data;
    int a;
    file.read((char *)&a, sizeof(int));
    while (file.read((char *)&p_data, sizeof(p_data))) {
        highscore_list.push_back(p_data);
    }
    file.close();
    std::sort(highscore_list.begin(), highscore_list.end(), [&](player_data a, player_data b) { 
            if (a.score > b.score) {
                return true;
            }
            if (a.score == b.score) {
                return sort(a.mode, b.mode);
            }
            return false;
         });
    for (int i = 0; static_cast<size_t>(i) < highscore_list.size(); ++i) {
        std::cout << i + 1 << std::endl;
        std::cout <<  highscore_list[i].name << ", " << highscore_list[i].mode << ", " << highscore_list[i].score << '\n';

    }
    // for (auto &elem : highscore_list) {
        
    //     std::cout << &elem - &highscore_list[0] << ", " <<  elem.name << ", " << elem.mode << ", " << elem.score << '\n';
    // }
}

Ranking::Ranking(SnakeBoard &b, Snake &s)
    : board(b),
      snake(s),
      highscore_list()
{
}

int Ranking::Run(sf::RenderWindow &window)
{
    std::cout << "do nothing";
    return 0;
}

bool Ranking::sort(const char * lhs, const char * rhs)
{
    if (lhs == static_cast<std::string>("HARD")) {
        return true;
    }
   if (lhs == static_cast<std::string>("NORMAL")) {
       if (rhs == static_cast<std::string>("HARD")) {
           return false;
       }
      if (rhs == static_cast<std::string>("NORMAL")) {
           return true;
       }
       if (rhs == static_cast<std::string>("EASY")) {
           return true;
       }
   }
   if (lhs == static_cast<std::string>("EASY")) {
       if (rhs == static_cast<std::string>("HARD")) {
           return false;
       }
       if (rhs == static_cast<std::string>("NORMAL")) {
           return false;
       }
        if (rhs == static_cast<std::string>("EASY")) {
           return true;
       }
   }
   return false; //will not come to this
}