#include <iostream>

const int MOD = 1e9 + 7;

const int MAX_N = 101;
const int MAX_W = 1e6 + 1;

int N;
int W;

int coins[MAX_N];

int memo[MAX_W];

int get_coin_combinations() {
  memo[0] = 1;

  for (int i = 1; i <= W; i++) {
    for (int c = 0; c < N; c++) {
      if (i - coins[c] >= 0) {
        memo[i] = (memo[i] + memo[i - coins[c]]) % MOD;
      }
    }
  }

  return memo[W];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> W;

  for (int i = 0; i < N; i++) {
    std::cin >> coins[i];
  }

  std::cout << get_coin_combinations() << '\n';

  return 0;
}
