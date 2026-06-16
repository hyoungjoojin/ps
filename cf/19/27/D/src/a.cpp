#include <iostream>

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int memo[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
      std::cin >> array[i];
    }

    memo[0] = -1;
    for (int i = 1; i < N; i++) {
      memo[i] = (array[i] != array[i - 1] ? i - 1 : memo[i - 1]);
    }

    int q;
    std::cin >> q;

    while (q--) {
      int l, r;
      std::cin >> l >> r;

      l--;
      r--;

      if (memo[r] < l) {
        std::cout << "-1 -1\n";
      } else {
        std::cout << memo[r] + 1 << ' ' << r + 1 << '\n';
      }
    }
  }

  return 0;
}
