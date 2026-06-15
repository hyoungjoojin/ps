#include <iomanip>
#include <ios>
#include <iostream>

using ld = long double;

const int MAX_N = 3000;

int N;
ld p[MAX_N];

ld memo[MAX_N][MAX_N];

ld get_probability() {
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      memo[i][j] = 0;
    }
  }

  memo[1][0] = 1 - p[1];
  memo[1][1] = p[1];

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      memo[i][j] = memo[i - 1][j] * (1 - p[i]) + memo[i - 1][j - 1] * p[i];
    }
  }

  ld result = 0;
  for (int i = N / 2 + 1; i <= N; i++) {
    result += memo[N][i];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> p[i];
  }

  std::cout << std::fixed << std::setprecision(10);
  std::cout << get_probability() << '\n';

  return 0;
}
