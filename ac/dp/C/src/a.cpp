#include <algorithm>
#include <iostream>
#include <limits>

const int MAX_N = 1e5 + 1;

int N;
int a[MAX_N], b[MAX_N], c[MAX_N];
int memo[MAX_N][3];

int get_maximum_points() {
  for (int i = 0; i < N; i++) {
    memo[i][0] = memo[i][1] = memo[i][2] = std::numeric_limits<int>::max();
  }

  memo[0][0] = a[0];
  memo[0][1] = b[0];
  memo[0][2] = c[0];

  for (int i = 1; i < N; i++) {
    memo[i][0] = std::max(memo[i - 1][1], memo[i - 1][2]) + a[i];
    memo[i][1] = std::max(memo[i - 1][0], memo[i - 1][2]) + b[i];
    memo[i][2] = std::max(memo[i - 1][0], memo[i - 1][1]) + c[i];
  }

  return *std::max_element(memo[N - 1], memo[N - 1] + 3);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> a[i] >> b[i] >> c[i];
  }

  std::cout << get_maximum_points() << '\n';

  return 0;
}
