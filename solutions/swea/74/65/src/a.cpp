#include <iostream>

const int MAX_PEOPLE = 101;

int num_people;
int sets[MAX_PEOPLE];

void make_sets() {
  for (int i = 0; i <= num_people; i++) {
    sets[i] = i;
  }
}

int find_set(int x) {
  if (sets[x] == x) {
    return x;
  }

  return sets[x] = find_set(sets[x]);
}

void union_sets(int x, int y) {
  x = find_set(x);
  y = find_set(y);

  if (x != y) {
    sets[x] = y;
  }
}

int count_sets() {
  int count = 0;
  for (int i = 1; i <= num_people; i++) {
    if (find_set(i) == find_set(0)) {
      continue;
    }

    union_sets(0, i);
    count++;
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  int num_relationships;

  for (int t = 1; t <= T; t++) {
    std::cin >> num_people >> num_relationships;

    make_sets();

    int u, v;
    while (num_relationships--) {
      std::cin >> u >> v;
      union_sets(u, v);
    }

    std::cout << '#' << t << ' ' << count_sets() << '\n';
  }

  return 0;
}
