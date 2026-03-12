#include <iostream>

int f(int n) {
  int memo[3] = {1, 2, 4};
  if (n <= 3) {
    return memo[n - 1];
  }

  for (int i = 4; i <= n; i++) {
    int temp = memo[0] + memo[1] + memo[2];
    memo[0] = memo[1];
    memo[1] = memo[2];
    memo[2] = temp;
  }

  return memo[2];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  int n;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    std::cout << f(n) << '\n';
  }

  return 0;
}
