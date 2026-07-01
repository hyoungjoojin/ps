#include <iostream>

void move(int N, int from, int to) {
  if (N == 0) {
    return;
  }

  int mid = 6 - from - to;

  move(N - 1, from, mid);
  std::cout << from << ' ' << to << '\n';
  move(N - 1, mid, to);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  std::cout << (1 << N) - 1 << '\n';

  move(N, 1, 3);

  return 0;
}
