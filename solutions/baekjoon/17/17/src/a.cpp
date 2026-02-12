#include <iostream>

const int MAX_SIZE = 1000001;

int num_elements;
int sets[MAX_SIZE];

void init() {
  for (int i = 0; i <= num_elements; i++) {
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
  if (x == y) {
    return;
  }

  sets[x] = y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_queries;
  std::cin >> num_elements >> num_queries;

  init();

  int command, a, b;
  while (num_queries--) {
    std::cin >> command >> a >> b;

    if (command == 0) {
      merge_sets(a, b);
    } else {
      std::cout << (find_set(a) == find_set(b) ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
