#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>

const int MAX_N = 1e5 + 1;

int N;
int h[MAX_N];
int memo[MAX_N];

int get_minimum_cost() {
  for (int i = 0; i < N; i++) {
    memo[i] = std::numeric_limits<int>::max();
  }

  memo[0] = 0;

  for (int i = 0; i < N; i++) {
    if (i + 1 < N) {
      memo[i + 1] = std::min(memo[i + 1], memo[i] + std::abs(h[i] - h[i + 1]));
    }

    if (i + 2 < N) {
      memo[i + 2] = std::min(memo[i + 2], memo[i] + std::abs(h[i] - h[i + 2]));
    }
  }

  return memo[N - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> h[i];
  }

  std::cout << get_minimum_cost() << '\n';

  return 0;
}
