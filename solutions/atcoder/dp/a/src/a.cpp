#include <algorithm>
#include <cstdlib>
#include <iostream>

const int MAX_N = 1e5 + 1;

int N;
int heights[MAX_N];

int memo[MAX_N];

int _get_minimum_cost(int i) {
  if (i == 0) {
    return 0;
  }

  if (i == 1) {
    return std::abs(heights[1] - heights[0]);
  }

  if (memo[i] != -1) {
    return memo[i];
  }

  int cost = std::min(
      _get_minimum_cost(i - 1) + std::abs(heights[i] - heights[i - 1]),
      _get_minimum_cost(i - 2) + std::abs(heights[i] - heights[i - 2]));

  return memo[i] = cost;
}

int get_minimum_cost() {
  for (int i = 0; i < N; i++) {
    memo[i] = -1;
  }

  return _get_minimum_cost(N - 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> heights[i];
  }

  std::cout << get_minimum_cost() << '\n';

  return 0;
}
