#include <iostream>

using ll = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  ll n;
  std::cin >> n;

  while (n != 1) {
    std::cout << n << ' ';
    n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
  }

  std::cout << "1\n";

  return 0;
}
