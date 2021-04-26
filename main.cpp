
#include <iostream>
#include <string>
#include <vector>

void printPlane(std::vector<std::string> &array) {
  for (auto & i : array) {
    for (size_t j = 0; j < 7; ++j) {
      std::cout << i[j];
      if (i[j] == 'X')
        i[j] = '#';
    }
    std::cout << "\n";
  }
}

int main() {
  int n = 0;

  int num = 0;
  std::string side, position;

  std::cin >> n;
  std::vector<std::string> array(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> array[i];
  }

  int groups = 0;
  std::cin >> groups;
  for (size_t g = 0; g < groups; ++g) {
    bool answ = false;
    std::cin >> num >> side >> position;
    if (side == "left") {
      if (position == "window") {
        for (size_t i = 0; i < n; ++i) {
          int places = 0;
          if (answ) break;
            for (size_t j = 0; j < 3; ++j) {
              if (array[i][j] == '.') {
                ++places;
              } else break;
            }
            if (num <= places) {
              answ = true;
              std::cout << "Passengers can take seats:";
              for (size_t ppl = 0; ppl < num; ++ppl) {
                array[i][ppl] = 'X';
                std::cout << ' ' << i + 1  << char('A' + ppl);
              }
              std::cout << "\n";
              printPlane(array);
            } else answ = false;
        }
        if (!answ) {
          std::cout << "Cannot fulfill passengers requirements\n";
        }
      } else if (position != "window") {
        for (size_t i = 0; i < n; ++i) {
          int places = 0;
          if (answ) break;
          for (size_t j = 2; j >= 0; --j) {
            if (array[i][j] == '.') {
              ++places;
            } else break;
          }
          if (num <= places) {
            int sh = 3 - num;
            answ = true;
            std::cout << "Passengers can take seats:";
            for (size_t ppl = 0; ppl < num; ++ppl) {
              array[i][2 - ppl] = 'X';
              std::cout << ' ' << i + 1  << char('A' + sh + ppl);
            }
            std::cout << "\n";
            printPlane(array);
          } else answ = false;
        }
        if (!answ) {
          std::cout << "Cannot fulfill passengers requirements\n";
        }
      }
    } else if (side == "right") {
      if (position == "window") {
        for (size_t i = 0; i < n; ++i) {
          int places = 0;
          if (answ) break;
          for (size_t j = 6; j >= 4; --j) {
            if (array[i][j] == '.') {
              ++places;
            } else break;
          }
          if (num <= places) {
            int sh = 3 - num;
            answ = true;
            std::cout << "Passengers can take seats:";
            for (size_t ppl = 0; ppl < num; ++ppl) {
              array[i][6 - ppl] = 'X';
              std::cout << ' ' << i + 1  << char('D' + sh + ppl);
            }
            std::cout << "\n";
            printPlane(array);
          } else answ = false;
        }
        if (!answ) {
          std::cout << "Cannot fulfill passengers requirements\n";
        }
      }else if (position != "window") {
        for (size_t i = 0; i < n; ++i) {
          int places = 0;
          if (answ) break;
          for (size_t j = 4; j < 7; ++j) {
            if (array[i][j] == '.') {
              ++places;
            } else break;
          }
          if (num <= places) {
            answ = true;
            std::cout << "Passengers can take seats:";
            for (size_t ppl = 0; ppl < num; ++ppl) {
              array[i][4 + ppl] = 'X';
              std::cout << ' ' << i + 1 << char('D' + ppl);
            }
            std::cout << "\n";
            printPlane(array);
          } else answ = false;
        }
        if (!answ) {
          std::cout << "Cannot fulfill passengers requirements\n";
        }
      }
    }
  }
  return 0;
}

