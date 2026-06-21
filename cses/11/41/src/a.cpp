#include <algorithm>
#include <iostream>
#include <set>

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int get_longest_sequence_length() {
  int result = 0;
  std::set<int> set;

  for (int li = 0, ri = 0; li < N; li++) {
    while (ri < N && set.find(array[ri]) == set.end()) {
      set.insert(array[ri++]);
    }

    result = std::max(result, ri - li);
    set.erase(array[li]);
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

  std::cout << get_longest_sequence_length() << '\n';

  return 0;
}
