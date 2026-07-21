#include <algorithm>
#include <iostream>

using ll = long long;

ll get_number(int r, int c) {
  ll n = std::max(r, c);

  if (r < c) {
    return (n % 2 == 0) ? ((n - 1) * (n - 1) + r) : (n * n - r + 1);
  } else {
    return (n % 2 == 0) ? (n * n - c + 1) : ((n - 1) * (n - 1) + c);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  for (int t = 0; t < T; t++) {
    int x, y;
    std::cin >> y >> x;
    std::cout << get_number(y, x) << '\n';
  }

  return 0;
}
