#include <cmath>
#include <iostream>

long long get_height(long long n) {
  long long target = 2 * n;

  long long min = 1, max = 2 * std::sqrt(target);

  for (long long li = min, ri = max; li <= ri;) {
    long long mid = li + (ri - li) / 2;

    long long value = mid * (mid + 1);

    if (value < target) {
      li = mid + 1;
    } else if (value > target) {
      ri = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  long long n;
  for (int t = 1; t <= T; t++) {
    std::cin >> n;
    std::cout << '#' << t << ' ' << get_height(n) << '\n';
  }

  return 0;
}
