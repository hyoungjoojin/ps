#include <algorithm>
#include <cmath>
#include <iostream>

int restaurants[1000001];

int ceil(int x, int y) {
  int result = x / y;
  int remainder = x % y;

  return result + (remainder == 0 ? 0 : 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> restaurants[i];
  }

  int x, y;
  std::cin >> x >> y;

  long long result = 0;
  for (int i = 0; i < n; i++) {
    result += 1 + ceil(std::max(restaurants[i] - x, 0), y);
  }

  std::cout << result << '\n';

  return 0;
}
