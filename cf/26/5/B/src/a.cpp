#include <cstdlib>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  int time = N - 1, height = 0;

  for (int i = 0; i < N; i++) {
    int h;
    std::cin >> h;
    time += (std::abs(height - h) + 1);
    height = h;
  }

  std::cout << time << '\n';

  return 0;
}
