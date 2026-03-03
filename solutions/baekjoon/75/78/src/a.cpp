#include <iostream>
#include <unordered_map>

const int MAX_N = 500001;
const int MAX_SEGTREE_SIZE = 1048577;

int N;
int S;
int segtree[MAX_SEGTREE_SIZE];
std::unordered_map<int, int> index;

void build_segtree() {
  S = 1;
  while (S < N) {
    S *= 2;
  }
}

void modify(int i) {
  i = i + S;
  segtree[i]++;

  for (int p = i / 2; p >= 1; p /= 2) {
    segtree[p] = segtree[p * 2] + segtree[p * 2 + 1];
  }
}

int query(int i) {
  int count = 0;
  for (int li = i + S + 1, ri = N + S; li < ri; li /= 2, ri /= 2) {
    if (li & 1) {
      count += segtree[li++];
    }

    if (ri & 1) {
      count += segtree[--ri];
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  int id;
  for (int i = 0; i < N; i++) {
    std::cin >> id;
    index[id] = i;
  }

  build_segtree();

  long long total_count = 0;

  for (int i = 0; i < N; i++) {
    std::cin >> id;
    total_count += query(index[id]);
    modify(index[id]);
  }

  std::cout << total_count << '\n';

  return 0;
}
