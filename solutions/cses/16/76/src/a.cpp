#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_NODES = 100001;

int num_nodes;

int num_sets;
int largest_set_size;
int sets[MAX_NODES];
int set_sizes[MAX_NODES];

void init_sets() {
  num_sets = num_nodes;
  largest_set_size = 1;

  for (int i = 0; i <= num_nodes; i++) {
    sets[i] = i;
    set_sizes[i] = 1;
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
    if (set_sizes[x] > set_sizes[y]) {
      std::swap(x, y);
    }

    num_sets--;
    sets[x] = y;
    set_sizes[y] += set_sizes[x];

    largest_set_size = std::max(largest_set_size, set_sizes[y]);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_edges;
  std::cin >> num_nodes >> num_edges;

  init_sets();

  int a, b;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> a >> b;

    merge_sets(a, b);

    std::cout << num_sets << ' ' << largest_set_size << '\n';
  }

  return 0;
}
