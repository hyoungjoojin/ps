#include <iostream>

const int MAX_N = 2e5 + 1;

int N;
bool found[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 1; i < N; i++) {
    int x;
    std::cin >> x;
    found[x] = true;
  }

  for (int i = 1; i <= N; i++) {
    if (!found[i]) {
      std::cout << i << '\n';
      break;
    }
  }

  return 0;
}
