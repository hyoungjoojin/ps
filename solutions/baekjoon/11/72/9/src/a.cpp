#include <iostream>

int get_movement_count(int count) { return (1 << count) - 1; }

void move(int count, int from, int to) {
  if (count == 1) {
    std::cout << from << ' ' << to << '\n';
    return;
  }

  move(count - 1, from, 6 - from - to);
  move(1, from, to);
  move(count - 1, 6 - from - to, to);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::cout << get_movement_count(n) << '\n';
  move(n, 1, 3);

  return 0;
}
