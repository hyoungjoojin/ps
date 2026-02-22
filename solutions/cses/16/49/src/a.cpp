#include <algorithm>
#include <iostream>
#include <limits>

const int MAX_SIZE = 200001;

int array_size;
int array[MAX_SIZE];

int n;
int segtree[MAX_SIZE * 4];

void build_segtree() {
  n = 1;
  while (n < array_size) {
    n *= 2;
  }

  for (int i = 0; i < n * 2; i++) {
    segtree[i] = std::numeric_limits<int>::max();
  }

  for (int i = 0; i < array_size; i++) {
    segtree[i + n] = array[i];
  }

  for (int i = n - 1; i >= 1; i--) {
    segtree[i] = std::min(segtree[i * 2], segtree[i * 2 + 1]);
  }
}

void modify_segtree(int i, int value) {
  i += n;

  segtree[i] = value;
  for (; i > 1; i /= 2) {
    segtree[i / 2] = std::min(segtree[i], segtree[i ^ 1]);
  }
}

int query_segtree(int l, int r) {
  int result = std::numeric_limits<int>::max();

  for (l = l + n, r = r + n; l < r; l /= 2, r /= 2) {
    if (l & 1) {
      result = std::min(result, segtree[l++]);
    }

    if (r & 1) {
      result = std::min(result, segtree[--r]);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_queries;
  std::cin >> array_size >> num_queries;

  for (int i = 0; i < array_size; i++) {
    std::cin >> array[i];
  }

  build_segtree();

  int command, a, b;
  while (num_queries--) {
    std::cin >> command >> a >> b;

    if (command == 1) {
      modify_segtree(a - 1, b);
    } else {
      std::cout << query_segtree(a - 1, b) << '\n';
    }
  }

  return 0;
}
