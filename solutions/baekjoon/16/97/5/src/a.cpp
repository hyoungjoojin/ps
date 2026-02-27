#include <iostream>

const int MAX_N = 100001;
const int MAX_SEGTREE_SIZE = 262144;

int N;
int segtree_size;
long long segtree[MAX_SEGTREE_SIZE];

void modify(int l, int r, int value) {
  for (int li = l + segtree_size - 1, ri = r + segtree_size; li < ri;
       li /= 2, ri /= 2) {
    if (li & 1) {
      segtree[li++] += value;
    }

    if (ri & 1) {
      segtree[--ri] += value;
    }
  }
}

long long query(int i) {
  long long result = 0;
  for (i = i + segtree_size - 1; i >= 1; i /= 2) {
    result += segtree[i];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  segtree_size = 1;
  while (segtree_size < N) {
    segtree_size *= 2;
  }

  for (int i = 0; i < N; i++) {
    std::cin >> segtree[segtree_size + i];
  }

  int num_queries;
  std::cin >> num_queries;

  int command, i, j, k;
  for (int q = 0; q < num_queries; q++) {
    std::cin >> command;

    if (command == 1) {
      std::cin >> i >> j >> k;
      modify(i, j, k);
    } else {
      std::cin >> i;
      std::cout << query(i) << '\n';
    }
  }

  return 0;
}
