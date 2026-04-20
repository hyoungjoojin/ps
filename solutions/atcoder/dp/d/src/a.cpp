#include <algorithm>
#include <iostream>

const int MAX_N = 101;
const int MAX_W = 1e5 + 1;

int N;
int W;

int weights[MAX_N];
int values[MAX_N];

long long memo[MAX_W];
long long temp[MAX_W];

long long maximum_value() {
  for (int i = 0; i <= W; i++) {
    memo[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j >= weights[i]) {
        temp[j] = std::max(values[i] + memo[j - weights[i]], memo[j]);
      } else {
        temp[j] = memo[j];
      }
    }

    for (int j = 0; j <= W; j++) {
      memo[j] = temp[j];
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
    std::cin >> weights[i] >> values[i];
  }

  std::cout << maximum_value() << '\n';

  return 0;
}
