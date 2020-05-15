#include <iostream>
#include <vector>

const int lim = 20;
struct player_data {
    char name[lim];
    char mode[lim];
    int score;
};

std::vector<player_data> highscore_list = {
  player_data{"aaa", "vvv", 2},
  player_data{"bbb", "ccc", 3},
  player_data{"ddd", "vvv", 4},
};


int main() {
  std::cout << "Hello World!\n";
  for (size_t i = 0; i < highscore_list.size(); ++i) {
        std::cout << i + 1 << ", "
                  << highscore_list[i].name << ", "
                  << highscore_list[i].mode << ", "
                  << highscore_list[i].score << '\n';
  }
}