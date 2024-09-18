#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0, target = 0;
  std::cin >> N;

  std::vector<int> numbers(N);
  for (int &number : numbers)
    std::cin >> number;
  std::sort(numbers.begin(), numbers.end());

  std::cin >> M;
  while (M--) {
    std::cin >> target;
    std::cout << (std::binary_search(numbers.begin(), numbers.end(), target)
                      ? 1
                      : 0)
              << '\n';
  }

  return 0;
}
