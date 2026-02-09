#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int solution(std::vector<std::pair<int, int>> &bags, int k) {
  std::vector<int> memo(k + 1, 0), temp(k + 1, 0);

  for (auto &[w, v] : bags) {
    for (int i = 0; i <= k; i++) {
      temp[i] = i >= w ? std::max(memo[i - w] + v, memo[i]) : memo[i];
    }

    for (int i = 0; i <= k; i++) {
      memo[i] = temp[i];
    }
  }

  return memo[k];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  std::vector<std::pair<int, int>> bags(n);
  for (auto &[w, v] : bags) {
    std::cin >> w >> v;
  }

  std::cout << solution(bags, k) << '\n';

  return 0;
}
