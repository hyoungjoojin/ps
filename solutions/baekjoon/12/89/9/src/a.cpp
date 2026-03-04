#include <iostream>

const int MAX_SEGTREE_SIZE = 4194305;

int S;
int segtree[MAX_SEGTREE_SIZE];

void init() {
  S = 1;
  while (S < 2000001) {
    S *= 2;
  }
}

void modify(int i, int value) {
  i = i + S - 1;
  segtree[i] += value;

  for (int p = i / 2; p >= 1; p /= 2) {
    segtree[p] = segtree[p * 2] + segtree[p * 2 + 1];
  }
}

int query(int i) {
  int p = 1;
  for (int count = i; p < S;) {
    if (count <= segtree[p * 2]) {
      p = p * 2;
    } else {
      count -= segtree[p * 2];
      p = p * 2 + 1;
    }
  }

  int result = p - S + 1;
  modify(result, -1);
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  init();

  int num_queries;
  std::cin >> num_queries;

  int t, x;
  for (int q = 0; q < num_queries; q++) {
    std::cin >> t >> x;

    if (t == 1) {
      modify(x, 1);
    } else {
      std::cout << query(x) << '\n';
    }
  }

  return 0;
}
