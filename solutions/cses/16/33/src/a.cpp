#include <iostream>

const int MOD = 1e9 + 7;

int get_dice_combinations(int n) {
  int base[6];
  for (int i = 0; i < 6; i++) {
    base[i] = (1 << i);
  }

  if (n <= 6) {
    return base[n - 1];
  }

  for (int i = 7; i <= n; i++) {
    int next = 0;
    for (int j = 0; j < 6; j++) {
      next = (next + base[j]) % MOD;
    }

    for (int j = 0; j < 5; j++) {
      base[j] = base[j + 1];
    }

    base[5] = next;
  }

  return base[5];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::cout << get_dice_combinations(n) << '\n';

  return 0;
}
