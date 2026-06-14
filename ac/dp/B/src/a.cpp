#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>

const int MAX_N = 1e5 + 1;

int N;
int h[MAX_N];
int memo[MAX_N];

int K;

int get_minimum_cost() {
  for (int i = 0; i < N; i++) {
    memo[i] = std::numeric_limits<int>::max();
  }

  memo[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= K && i + j < N; j++) {
      memo[i + j] = std::min(memo[i + j], memo[i] + std::abs(h[i] - h[i + j]));
    }
  }

  return memo[N - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  for (int i = 0; i < N; i++) {
    std::cin >> h[i];
  }

  std::cout << get_minimum_cost() << '\n';

  return 0;
}
