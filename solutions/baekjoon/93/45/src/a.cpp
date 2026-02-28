#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>

const int MAX_N = 100001;
const int MAX_SEGTREE_SIZE = 262145;

int N;
int segtree_size;
int array[MAX_N];
int min_segtree[MAX_SEGTREE_SIZE];
int max_segtree[MAX_SEGTREE_SIZE];

void build_segtree() {
  segtree_size = 1;
  while (segtree_size < N) {
    segtree_size *= 2;
  }

  for (int i = 0; i < N; i++) {
    array[i] = i;
    min_segtree[i + segtree_size] = i;
    max_segtree[i + segtree_size] = i;
  }

  for (int i = segtree_size + N; i < segtree_size * 2; i++) {
    min_segtree[i] = std::numeric_limits<int>::max();
    max_segtree[i] = std::numeric_limits<int>::min();
  }

  for (int i = segtree_size - 1; i >= 1; i--) {
    min_segtree[i] = std::min(min_segtree[i * 2], min_segtree[i * 2 + 1]);
    max_segtree[i] = std::max(max_segtree[i * 2], max_segtree[i * 2 + 1]);
  }
}

void modify(int i, int value) {
  i = i + segtree_size;
  min_segtree[i] = value;
  max_segtree[i] = value;

  for (int p = i / 2; p >= 1; p /= 2) {
    min_segtree[p] = std::min(min_segtree[p * 2], min_segtree[p * 2 + 1]);
    max_segtree[p] = std::max(max_segtree[p * 2], max_segtree[p * 2 + 1]);
  }
}

bool query(int l, int r) {
  int min = std::numeric_limits<int>::max(),
      max = std::numeric_limits<int>::min();

  for (int li = segtree_size + l, ri = segtree_size + r + 1; li < ri;
       li /= 2, ri /= 2) {
    if (li & 1) {
      min = std::min(min, min_segtree[li]);
      max = std::max(max, max_segtree[li]);
      li++;
    }

    if (ri & 1) {
      --ri;
      min = std::min(min, min_segtree[ri]);
      max = std::max(max, max_segtree[ri]);
    }
  }

  return (min == l && max == r);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  int num_queries;
  for (int t = 1; t <= T; t++) {
    std::cin >> N >> num_queries;

    build_segtree();

    int q, a, b;
    while (num_queries--) {
      std::cin >> q >> a >> b;

      if (q == 0) {
        std::swap(array[a], array[b]);
        modify(a, array[a]);
        modify(b, array[b]);
      } else {
        std::cout << (query(a, b) ? "YES\n" : "NO\n");
      }
    }
  }

  return 0;
}
