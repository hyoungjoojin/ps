#include <algorithm>
#include <iostream>

const int MAX_N = 1e5 + 1;

int N;
int books[MAX_N];

int T;

int get_maximum_books() {
  int max = 0;

  for (int li = 0, sum = 0, ri = 0; li < N; li++) {
    while (ri < N && sum + books[ri] <= T) {
      sum += books[ri++];
    }

    max = std::max(max, ri - li);
    sum -= books[li];
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> T;

  for (int i = 0; i < N; i++) {
    std::cin >> books[i];
  }

  std::cout << get_maximum_books() << '\n';

  return 0;
}
