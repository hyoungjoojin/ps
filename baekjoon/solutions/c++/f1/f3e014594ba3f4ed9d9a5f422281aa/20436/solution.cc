// 0 ms, 2024 KB

#include <cstdlib>
#include <iostream>
#include <string>

struct Key {
  bool left;
  int x;
  int y;
};

Key keys[26] = {
    Key{true, 1, 2},   // a
    Key{false, 5, 3},  // b
    Key{true, 3, 3},   // c
    Key{true, 3, 2},   // d
    Key{true, 3, 1},   // e
    Key{true, 4, 2},   // f
    Key{true, 5, 2},   // g
    Key{false, 6, 2},  // h
    Key{false, 8, 1},  // i
    Key{false, 7, 2},  // j
    Key{false, 8, 2},  // k
    Key{false, 9, 2},  // l
    Key{false, 7, 3},  // m
    Key{false, 6, 3},  // n
    Key{false, 9, 1},  // o
    Key{false, 10, 1}, // p
    Key{true, 1, 1},   // q
    Key{true, 4, 1},   // r
    Key{true, 2, 2},   // s
    Key{true, 5, 1},   // t
    Key{false, 7, 1},  // u
    Key{true, 4, 3},   // v
    Key{true, 2, 1},   // w
    Key{true, 2, 3},   // x
    Key{false, 6, 1},  // y
    Key{true, 1, 3},   // z
};

int get_minimum_time(const std::string &, Key, Key);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  char start_left = 0, start_right = 0;
  std::cin >> start_left >> start_right;

  std::string input = "";
  std::cin >> input;

  std::cout << get_minimum_time(input, keys[start_left - 'a'],
                                keys[start_right - 'a'])
            << '\n';

  return 0;
}

int distance(Key k1, Key k2) { return abs(k1.x - k2.x) + abs(k1.y - k2.y); }

int get_minimum_time(const std::string &target, Key starting_left_key,
                     Key starting_right_key) {
  int time = 0;
  Key current_key;
  for (char ch : target) {
    current_key = keys[ch - 'a'];
    bool is_left_key = current_key.left;

    time += 1 + (is_left_key ? distance(current_key, starting_left_key)
                             : distance(current_key, starting_right_key));

    if (is_left_key)
      starting_left_key = current_key;
    else
      starting_right_key = current_key;
  }

  return time;
}
