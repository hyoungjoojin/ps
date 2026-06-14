#include <algorithm>
#include <iostream>
#include <utility>

using ll = long long;

const int MAX_N = 101;
const int MAX_W = 1e5 + 1;

int N;
int W;
std::pair<int, int> items[MAX_N];

ll memo[MAX_W];
ll temp[MAX_W];

ll get_maximum_sum() {
  for (int i = 0; i <= W; i++) {
    memo[i] = 0;
    temp[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    auto [w, v] = items[i];

    for (int j = w; j <= W; j++) {
      temp[j] = std::max(memo[j - w] + v, memo[j]);
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
    std::cin >> items[i].first >> items[i].second;
  }

  std::cout << get_maximum_sum() << '\n';

  return 0;
}
