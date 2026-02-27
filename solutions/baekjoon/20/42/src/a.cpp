#include <iostream>

const int MAX_N = 1000001;
const int MAX_TREE_SIZE = 2097152;

int N;
int segtree_size;
long long segtree[MAX_TREE_SIZE] = {0};

void modify(int i, long long value) {
  i = segtree_size + i - 1;
  segtree[i] = value;

  for (int k = i / 2; k >= 1; k /= 2) {
    segtree[k] = segtree[k * 2] + segtree[k * 2 + 1];
  }
}

long long query(int l, int r) {
  long long sum = 0;
  for (int li = segtree_size + l - 1, ri = segtree_size + r; li < ri;
       li /= 2, ri /= 2) {
    if (li & 1) {
      sum += segtree[li++];
    }

    if (ri & 1) {
      sum += segtree[--ri];
    }
  }

  return sum;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m, k;
  std::cin >> N >> m >> k;

  segtree_size = 1;
  while (segtree_size < N) {
    segtree_size *= 2;
  }

  for (int i = 0; i < N; i++) {
    std::cin >> segtree[segtree_size + i];
  }

  for (int i = segtree_size - 1; i >= 1; i--) {
    segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
  }

  long long a, b, c;
  for (int q = 0; q < m + k; q++) {
    std::cin >> a >> b >> c;

    if (a == 1) {
      modify(b, c);
    } else {
      std::cout << query(b, c) << '\n';
    }
  }

  return 0;
}
