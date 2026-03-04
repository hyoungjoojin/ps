#include <iostream>

const int MAX_N = 1000001;

int N;
int K;
int M;
int sets[MAX_N];

void init() {
  for (int i = 0; i <= N; i++) {
    sets[i] = i;
  }
}

int find_set(int x) {
  if (x == sets[x]) {
    return x;
  }

  return sets[x] = find_set(sets[x]);
}

void merge_sets(int x, int y) {
  x = find_set(x), y = find_set(y);

  if (x != y) {
    sets[x] = y;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  int u, v;

  for (int t = 1; t <= T; t++) {
    std::cout << "Scenario " << t << ":\n";

    std::cin >> N;
    init();

    std::cin >> K;
    for (int i = 0; i < K; i++) {
      std::cin >> u >> v;
      merge_sets(u, v);
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
      std::cin >> u >> v;

      if (find_set(u) == find_set(v)) {
        std::cout << "1\n";
      } else {
        std::cout << "0\n";
      }
    }

    std::cout << '\n';
  }

  return 0;
}
