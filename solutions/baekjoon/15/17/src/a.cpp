#include <algorithm>
#include <iostream>

const int MAX_N = 500001;
const int MAX_SEGTREE_SIZE = 1048576;

int N;
int segtree_size;
long long segtree[MAX_SEGTREE_SIZE] = {0};

struct Item {
  int index;
  int value;
};

Item items[MAX_N];

void modify(int i) {
  i = i + segtree_size;
  segtree[i]++;

  for (int p = i / 2; p >= 1; p /= 2) {
    segtree[p] = segtree[p * 2] + segtree[p * 2 + 1];
  }
}

long long query(int l, int r) {
  long long result = 0;
  for (int li = l + segtree_size, ri = r + segtree_size + 1; li < ri;
       li /= 2, ri /= 2) {
    if (li & 1) {
      result += segtree[li++];
    }

    if (ri & 1) {
      result += segtree[--ri];
    }
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

  int value;
  for (int i = 0; i < N; i++) {
    std::cin >> value;
    items[i] = {i, value};
  }

  std::sort(items, items + N, [](const Item &i1, const Item &i2) {
    if (i1.value == i2.value) {
      return i1.index < i2.index;
    }

    return i1.value < i2.value;
  });

  long long result = 0;
  for (int i = 0; i < N; i++) {
    result += query(items[i].index + 1, N - 1);
    modify(items[i].index);
  }

  std::cout << result << '\n';

  return 0;
}
