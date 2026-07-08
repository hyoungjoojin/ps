#include <algorithm>
#include <iostream>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int x;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> x;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::sort(array, array + N);

  int count = 0;
  for (int li = 0, ri = N - 1; li <= ri; count++, ri--) {
    if (array[li] + array[ri] <= x) {
      li++;
    }
  }

  std::cout << count << '\n';

  return 0;
}
