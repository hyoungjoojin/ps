#include <iostream>
#include <map>
#include <utility>

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int target;

std::pair<int, int> find_pair() {
  std::map<int, int> dictionary;

  for (int i = 0; i < N; i++) {
    int remainder = target - array[i];

    if (dictionary.find(remainder) != dictionary.end()) {
      int j = dictionary[remainder];
      return {j, i};
    }

    dictionary[array[i]] = i;
  }

  return {-1, -1};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> target;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  auto [i, j] = find_pair();

  if (i == -1) {
    std::cout << "IMPOSSIBLE\n";
  } else {
    std::cout << i + 1 << ' ' << j + 1 << '\n';
  }

  return 0;
}
