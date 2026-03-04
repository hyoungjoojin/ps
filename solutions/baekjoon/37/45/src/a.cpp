#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 100001;

int N;
int array[MAX_N];

int get_longest_increasing_subsequence_length() {
  std::vector<int> tails;

  for (int i = 0; i < N; i++) {
    auto lb = std::lower_bound(tails.begin(), tails.end(), array[i]);

    if (lb == tails.end()) {
      tails.push_back(array[i]);
    } else {
      *lb = array[i];
    }
  }

  return tails.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  while (std::cin >> N) {
    for (int i = 0; i < N; i++) {
      std::cin >> array[i];
    }

    std::cout << get_longest_increasing_subsequence_length() << '\n';
  }

  return 0;
}
