#include <algorithm>
#include <iostream>
#include <limits>

const int INF = std::numeric_limits<int>::max();

const int MAX_N = 2e5 + 1;
const int MAX_S = 262145;

int N;
int array[MAX_N];

int S;
int segtree[MAX_S * 2];

void build_segtree() {
  S = 1;
  while (S < N) {
    S *= 2;
  }

  for (int i = 0; i < N; i++) {
    segtree[i + S] = array[i];
  }

  for (int i = N + S; i < 2 * S; i++) {
    segtree[i] = INF;
  }

  for (int i = S - 1; i >= 1; i--) {
    segtree[i] = std::min(segtree[i * 2], segtree[i * 2 + 1]);
  }
}

void modify(int i, int v) {
  i = i + S - 1;
  segtree[i] = v;

  for (i /= 2; i >= 1; i /= 2) {
    segtree[i] = std::min(segtree[i * 2], segtree[i * 2 + 1]);
  }
}

int query(int a, int b) {
  int result = INF;
  for (int li = a + S - 1, ri = b + S; li < ri; li /= 2, ri /= 2) {
    if (li & 1) {
      result = std::min(result, segtree[li++]);
    }

    if (ri & 1) {
      result = std::min(result, segtree[--ri]);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int q;
  std::cin >> N >> q;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  build_segtree();

  while (q--) {
    int c, a, b;
    std::cin >> c >> a >> b;

    if (c == 1) {
      modify(a, b);
    } else {
      std::cout << query(a, b) << '\n';
    }
  }

  return 0;
}
