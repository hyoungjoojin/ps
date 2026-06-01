#include <iostream>

const int MAX_N = 1e5 + 1;

int N;
int array[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int M;
  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  int cumsum = 0;

  while (M--) {
    int op;
    std::cin >> op;

    if (op == 1) {
      int v, x;
      std::cin >> v >> x;
      array[v - 1] = x - cumsum;
    } else if (op == 2) {
      int y;
      std::cin >> y;
      cumsum += y;
    } else if (op == 3) {
      int q;
      std::cin >> q;
      std::cout << array[q - 1] + cumsum << '\n';
    }
  }

  return 0;
}
