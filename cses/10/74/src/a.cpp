#include <algorithm>
#include <iostream>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
ll array[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::sort(array, array + N);

  ll result = 0, target = array[N / 2];

  for (int i = 0; i < N; i++) {
    result += std::abs(array[i] - target);
  }

  std::cout << result << "\n";

  return 0;
}
