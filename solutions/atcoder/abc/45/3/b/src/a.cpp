#include <cstdlib>
#include <iostream>

int T;
int X;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> T >> X;

  int current, last_saved;

  std::cin >> current;
  last_saved = current;
  std::cout << "0 " << last_saved << '\n';

  for (int i = 1; i <= T; i++) {
    std::cin >> current;

    int diff = std::abs(current - last_saved);
    if (diff >= X) {
      last_saved = current;
      std::cout << i << ' ' << last_saved << '\n';
    }
  }

  return 0;
}
