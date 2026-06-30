#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  if (N == 2 || N == 3) {
    std::cout << "NO SOLUTION\n";
  } else {
    for (int i = 2; i <= N; i += 2) {
      std::cout << i << ' ';
    }

    for (int i = 1; i <= N; i += 2) {
      std::cout << i << ' ';
    }

    std::cout << '\n';
  }

  return 0;
}
