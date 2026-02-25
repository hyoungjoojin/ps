#include <algorithm>
#include <iostream>

const int MAX_N = 20;

int N;
int T[MAX_N];
int P[MAX_N];

int memo[MAX_N][2];

int _get_max_profit_recursive(int d, int take) {
  if (memo[d][take] != -1) {
    return memo[d][take];
  }

  if (d > N) {
    return 0;
  }

  int profit = 0;

  if (take) {
    if (d + T[d] - 1 <= N) {
      profit = P[d] + std::max(_get_max_profit_recursive(d + T[d], 0),
                               _get_max_profit_recursive(d + T[d], 1));
    }
  } else {
    profit = std::max(_get_max_profit_recursive(d + 1, 0),
                      _get_max_profit_recursive(d + 1, 1));
  }

  return memo[d][take] = profit;
}

int get_max_profit() {
  for (int i = 1; i <= N; i++) {
    memo[i][0] = -1;
    memo[i][1] = -1;
  }

  return std::max(_get_max_profit_recursive(1, 0),
                  _get_max_profit_recursive(1, 1));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    std::cin >> T[i] >> P[i];
  }

  std::cout << get_max_profit() << '\n';

  return 0;
}
