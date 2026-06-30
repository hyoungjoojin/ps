#include <algorithm>
#include <iostream>

using ll = long long;

const ll NINF = -1e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  ll g = NINF, c = NINF;

  for (int i = 0; i < N; i++) {
    ll x;
    std::cin >> x;

    c = std::max(c + x, x);
    g = std::max(g, c);
  }

  std::cout << g << '\n';

  return 0;
}
