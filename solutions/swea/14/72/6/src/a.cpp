#include <algorithm>
#include <iostream>
#include <limits>

int array_size;
int size;

int array[100001];
int segtree[400001][2];

void init() {
  size = 1;
  while (size < array_size) {
    size *= 2;
  }

  for (int i = 0; i < array_size; i++) {
    segtree[i + size][0] = array[i];
    segtree[i + size][1] = array[i];
  }

  for (int i = size - 1; i >= 1; i--) {
    segtree[i][0] = std::max(segtree[i * 2][0], segtree[i * 2 + 1][0]);
    segtree[i][1] = std::min(segtree[i * 2][1], segtree[i * 2 + 1][1]);
  }
}

void update(int i, int x) {
  segtree[i + size][0] = x;
  segtree[i + size][1] = x;

  for (int c = (i + size) / 2; c >= 1; c /= 2) {
    segtree[c][0] = std::max(segtree[c * 2][0], segtree[c * 2 + 1][0]);
    segtree[c][1] = std::min(segtree[c * 2][1], segtree[c * 2 + 1][1]);
  }
}

int query(int l, int r) {
  int max = 0, min = std::numeric_limits<int>::max();

  for (int li = l + size, ri = r + size - 1; li <= ri;) {
    if (li % 2 == 1) {
      max = std::max(max, segtree[li][0]);
      min = std::min(min, segtree[li][1]);
    }

    if (ri % 2 == 0) {
      max = std::max(max, segtree[ri][0]);
      min = std::min(min, segtree[ri][1]);
    }

    li = (li + 1) / 2;
    ri = (ri - 1) / 2;
  }

  return max - min;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  int num_queries;

  for (int t = 1; t <= T; t++) {
    std::cin >> array_size >> num_queries;

    for (int i = 0; i < array_size; i++) {
      std::cin >> array[i];
    }

    init();

    int command, i, x, l, r;

    std::cout << '#' << t << ' ';

    while (num_queries--) {
      std::cin >> command;

      if (command == 0) {
        std::cin >> i >> x;
        update(i, x);
      } else {
        std::cin >> l >> r;
        std::cout << query(l, r) << ' ';
      }
    }
    std::cout << '\n';
  }

  return 0;
}
