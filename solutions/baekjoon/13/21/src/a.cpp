#include <iostream>

const int MAX_N = 500001;
const int MAX_SEGTREE_SIZE = 1048577;

int N;
int S;
int array[MAX_N];
int segtree[MAX_SEGTREE_SIZE];

void build_segtree() {
  S = 1;
  while (S < N) {
    S *= 2;
  }

  for (int i = 0; i < N; i++) {
    segtree[i + S] = array[i];
  }

  for (int i = S - 1; i >= 1; i--) {
    segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
  }
}

void modify(int i, int x) {
  i = i + S - 1;
  segtree[i] += x;

  for (int p = i / 2; p >= 1; p /= 2) {
    segtree[p] = segtree[p * 2] + segtree[p * 2 + 1];
  }
}

int query(int x) {
  int p = 1;
  for (int count = x; p < S;) {
    if (count <= segtree[p * 2]) {
      p = p * 2;
    } else {
      count -= segtree[p * 2];
      p = p * 2 + 1;
    }
  }

  return p - S + 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  build_segtree();

  int M;
  std::cin >> M;

  int c;
  for (int q = 1; q <= M; q++) {
    std::cin >> c;

    if (c == 1) {
      int i, a;
      std::cin >> i >> a;
      modify(i, a);
    } else {
      int i;
      std::cin >> i;
      std::cout << query(i) << '\n';
    }
  }

  return 0;
}
