#include <iostream>

using ll = long long;

const int MOD = 1e9 + 7;

int power(int a, int b) {
  if (b == 0) {
    return 1;
  }

  if (b == 1) {
    return a;
  }

  ll result = power(a, b / 2);

  result = (result * result) % MOD;

  if (b % 2 == 1) {
    result = (result * a) % MOD;
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    int a, b;
    std::cin >> a >> b;
    std::cout << power(a, b) << '\n';
  }

  return 0;
}
