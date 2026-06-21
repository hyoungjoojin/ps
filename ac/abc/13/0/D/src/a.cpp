#include <iostream>

using ll = long long;

const int MAX_N = 1e5 + 1;

int N;
int array[MAX_N];

ll K;

ll get_count() {
  ll result = 0, sum = 0;

  for (int li = 0, ri = 0; li < N; li++) {
    while (ri < N && sum < K) {
      sum += array[ri++];
    }

    if (sum < K) {
      break;
    }

    result += (N - ri + 1);
    sum -= array[li];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::cout << get_count() << '\n';

  return 0;
}
