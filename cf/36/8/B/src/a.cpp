#include <iostream>
#include <set>

const int MAX_N = 1e5 + 1;

int N;
int array[MAX_N];
int distinct_count[MAX_N];

void compute_distinct_count() {
  std::set<int> set;

  for (int i = N - 1; i >= 0; i--) {
    set.insert(array[i]);
    distinct_count[i] = set.size();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int M;
  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  compute_distinct_count();

  while (M--) {
    int l;
    std::cin >> l;
    std::cout << distinct_count[l - 1] << "\n";
  }

  return 0;
}
