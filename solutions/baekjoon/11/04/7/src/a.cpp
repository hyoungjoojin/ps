#include <iostream>

const int MAX_N = 10;

int N;
int coins[MAX_N];

int get_minimum_required_coins(int k) {
  int count = 0;
  for (int i = N - 1; i >= 0; i--) {
    count += (k / coins[i]);
    k %= coins[i];
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int K;
  std::cin >> N >> K;

  for (int i = 0; i < N; i++) {
    std::cin >> coins[i];
  }

  std::cout << get_minimum_required_coins(K) << '\n';

  return 0;
}
