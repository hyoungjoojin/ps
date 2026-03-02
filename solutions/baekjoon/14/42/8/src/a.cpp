#include <algorithm>
#include <iostream>

const int MAX_N = 100001;
const int MAX_SEGTREE_SIZE = 262144;

int N;
int array[MAX_N];

int segtree_size;
int segtree[MAX_SEGTREE_SIZE];

int cmp(int i, int j) {
  if (i == -1) {
    return j;
  } else if (j == -1) {
    return i;
  }

  if (array[i] < array[j]) {
    return i;
  } else if (array[i] > array[j]) {
    return j;
  } else {
    return std::min(i, j);
  }
}

void build_segtree() {
  segtree_size = 1;
  while (segtree_size < N) {
    segtree_size *= 2;
  }

  for (int i = 0; i < N; i++) {
    segtree[segtree_size + i] = i;
  }

  for (int i = segtree_size + N; i < segtree_size * 2; i++) {
    segtree[i] = -1;
  }

  for (int i = segtree_size - 1; i >= 1; i--) {
    segtree[i] = cmp(segtree[i * 2], segtree[i * 2 + 1]);
  }
}

void modify(int i, int value) {
  array[i - 1] = value;
  i = i + segtree_size - 1;

  for (int p = i / 2; p >= 1; p /= 2) {
    segtree[p] = cmp(segtree[p * 2], segtree[p * 2 + 1]);
  }
}

int query(int l, int r) {
  int result = l - 1;

  for (int li = l + segtree_size - 1, ri = r + segtree_size; li < ri;
       li /= 2, ri /= 2) {
    if (li & 1) {
      result = cmp(result, segtree[li]);
      li++;
    }

    if (ri & 1) {
      ri--;
      result = cmp(result, segtree[ri]);
    }
  }

  return result;
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

  int num_queries;
  std::cin >> num_queries;

  int command, a, b;
  for (int q = 0; q < num_queries; q++) {
    std::cin >> command >> a >> b;

    if (command == 1) {
      modify(a, b);
    } else {
      std::cout << query(a, b) + 1 << '\n';
    }
  }

  return 0;
}
