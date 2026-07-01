#include <algorithm>
#include <iostream>

using ll = long long;

int N;

ll get_count(int x) {
  ll count = 0;
  for (int i = x; i <= N; i *= x) {
    count += (N / i);
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  std::cout << std::min(get_count(2), get_count(5)) << '\n';

  return 0;
}
