#include <iostream>

const int MAX_N = 100001;
const int MAX_SEGTREE_SIZE = 262145;

int N;
int segtree_size;
int array[MAX_N];
int segtree[MAX_SEGTREE_SIZE];

int get_value(int x) {
  if (x > 0) {
    return 1;
  } else if (x < 0) {
    return -1;
  } else {
    return 0;
  }
}

char translate_value(int x) {
  if (x > 0) {
    return '+';
  } else if (x < 0) {
    return '-';
  } else {
    return '0';
  }
}

void build_segtree() {
  segtree_size = 1;
  while (segtree_size < N) {
    segtree_size *= 2;
  }

  for (int i = 0; i < N; i++) {
    segtree[segtree_size + i] = get_value(array[i]);
  }

  for (int i = segtree_size + N; i < segtree_size * 2; i++) {
    segtree[i] = 1;
  }
  for (int i = segtree_size - 1; i >= 1; i--) {
    segtree[i] = segtree[i * 2] * segtree[i * 2 + 1];
  }
}

void modify(int i, int value) {
  i = segtree_size + i - 1;
  segtree[i] = get_value(value);

  for (int p = i / 2; p >= 1; p /= 2) {
    segtree[p] = segtree[p * 2] * segtree[p * 2 + 1];
  }
}

int query(int l, int r) {
  int result = 1;
  for (int li = l + segtree_size - 1, ri = r + segtree_size; li < ri;
       li /= 2, ri /= 2) {
    if (li & 1) {
      result *= segtree[li++];
    }

    if (ri & 1) {
      result *= segtree[--ri];
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_queries;
  while (std::cin >> N >> num_queries) {
    for (int i = 0; i < N; i++) {
      std::cin >> array[i];
    }

    build_segtree();

    char command;
    int a, b;

    for (int q = 0; q < num_queries; q++) {
      std::cin >> command >> a >> b;

      if (command == 'C') {
        modify(a, b);
      } else {
        char result = translate_value(query(a, b));
        std::cout << result;
      }
    }

    std::cout << '\n';
  }

  return 0;
}
