#include <algorithm>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, a, b;
  std::cin >> n >> m >> a >> b;

  int min = b * (n / m + (n % m != 0));

  for (int k = 0, r = n; r >= 0; k++, r -= m) {
    int p = b * k + a * r;
    min = std::min(min, p);
  }

  std::cout << min << '\n';

  return 0;
}
