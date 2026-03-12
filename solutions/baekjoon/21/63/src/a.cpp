#include <algorithm>
#include <iostream>
#include <limits>

const int MAX_N = 301;
const int MAX_M = 301;

int memo[MAX_N][MAX_M];

int get_minimum_cuts(int n, int m) {
  if (memo[n][m] != -1) {
    return memo[n][m];
  }

  if (n == 0 || m == 0) {
    return memo[n][m] = 0;
  }

  if (n == 1 && m == 1) {
    return 0;
  }

  int cuts = std::numeric_limits<int>::max();

  if (n > 1) {
    cuts = std::min(cuts, 1 + get_minimum_cuts(n / 2, m) +
                              get_minimum_cuts(n - n / 2, m));
  }

  if (m > 1) {
    cuts = std::min(cuts, 1 + get_minimum_cuts(n, m / 2) +
                              get_minimum_cuts(n, m - m / 2));
  }

  return memo[n][m] = cuts;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_M; j++) {
      memo[i][j] = -1;
    }
  }

  int N, M;
  std::cin >> N >> M;
  std::cout << get_minimum_cuts(N, M) << '\n';

  return 0;
}
