#include <algorithm>
#include <iostream>
#include <limits>

const int MAX_FILES = 501;

int num_files;
int files[MAX_FILES];

int memo[MAX_FILES][MAX_FILES];
int prefix_sum[MAX_FILES + 1];

void init() {
  for (int i = 0; i < num_files; i++) {
    for (int j = 0; j < num_files; j++) {
      memo[i][j] = -1;
    }
  }

  prefix_sum[0] = 0;
  for (int i = 1; i <= num_files; i++) {
    prefix_sum[i] = files[i - 1] + prefix_sum[i - 1];
  }
}

int sum(int start, int end) { return prefix_sum[end + 1] - prefix_sum[start]; }

int _get_minimum_cost_recursive(int start, int end) {
  if (memo[start][end] != -1) {
    return memo[start][end];
  }

  if (start == end) {
    return memo[start][end] = 0;
  }

  int cost = std::numeric_limits<int>::max();
  for (int k = start; k < end; k++) {
    cost = std::min(cost, _get_minimum_cost_recursive(start, k) +
                              _get_minimum_cost_recursive(k + 1, end));
  }

  return memo[start][end] = cost + sum(start, end);
}

int get_minimum_cost() { return _get_minimum_cost_recursive(0, num_files - 1); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> num_files;
    for (int i = 0; i < num_files; i++) {
      std::cin >> files[i];
    }

    init();

    std::cout << get_minimum_cost() << '\n';
  }

  return 0;
}
