#include <iostream>

const int MAX_NODES = 500001;

int num_nodes;
int num_edges;
int sets[MAX_NODES];

void init_sets() {
  for (int i = 0; i <= num_nodes; i++) {
    sets[i] = i;
  }
}

int find_set(int x) {
  if (sets[x] == x) {
    return x;
  }

  return sets[x] = find_set(sets[x]);
}

void merge_sets(int x, int y) {
  x = find_set(x), y = find_set(y);
  sets[x] = y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges;

  init_sets();

  int result = 0;

  int u, v;
  for (int i = 1; i <= num_edges; i++) {
    std::cin >> u >> v;

    if (find_set(u) == find_set(v)) {
      result = i;
      break;
    }

    merge_sets(u, v);
  }

  std::cout << result << '\n';

  return 0;
}
