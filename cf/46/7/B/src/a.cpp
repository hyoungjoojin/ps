#include <iostream>

const int MAX_M = 1001;

int M;
int K;
int armies[MAX_M];

int get_num_friends() {
  int fedor = armies[M];
  int count = 0;

  for (int i = 0; i < M; i++) {
    int diff = fedor ^ armies[i], k = 0;

    while (diff) {
      if (diff & 1) {
        k++;
      }

      diff >>= 1;
    }

    if (k <= K) {
      count++;
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n >> M >> K;

  for (int i = 0; i <= M; i++) {
    std::cin >> armies[i];
  }

  std::cout << get_num_friends() << '\n';

  return 0;
}
