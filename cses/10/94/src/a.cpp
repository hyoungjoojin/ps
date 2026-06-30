#include <iostream>

using ll = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  ll result = 0;
  int current = 0;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;

    if (x < current) {
      result += (current - x);
    } else {
      current = x;
    }
  }

  std::cout << result << '\n';

  return 0;
}
