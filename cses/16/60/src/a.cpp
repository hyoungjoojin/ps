#include <iostream>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int target;

ll get_subarray_count() {
  ll count = 0, sum = 0;

  for (int li = 0, ri = 0; li < N; sum -= array[li++]) {
    while (ri < N && sum < target) {
      sum += array[ri++];
    }

    if (sum == target) {
      count++;
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> target;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::cout << get_subarray_count() << '\n';

  return 0;
}
