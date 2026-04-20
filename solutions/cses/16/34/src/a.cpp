#include <algorithm>
#include <iostream>
#include <limits>

const int INF = std::numeric_limits<int>::max();

const int MAX_N = 101;
const int MAX_W = 1e6 + 1;

int N;
int coins[MAX_N];

int W;

int memo[MAX_W];

int get_minimum_number_of_coins() {
  memo[0] = 0;

  for (int i = 1; i <= W; i++) {
    int count = INF;

    for (int c = 0; c < N; c++) {
      if (i - coins[c] >= 0 && memo[i - coins[c]] != INF) {
        count = std::min(count, memo[i - coins[c]] + 1);
      }
    }

    memo[i] = count;
  }

  return (memo[W] == INF ? -1 : memo[W]);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> W;

  for (int i = 0; i < N; i++) {
    std::cin >> coins[i];
  }

  std::cout << get_minimum_number_of_coins() << '\n';

  return 0;
}
