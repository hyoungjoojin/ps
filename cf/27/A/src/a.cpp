#include <algorithm>
#include <iostream>

const int MAX_N = 3001;

int N;
int array[MAX_N];

int find_next_integer() {
  std::sort(array, array + N);

  int candidate = 1;
  for (int i = 0; i < N; i++) {
    if (candidate == array[i]) {
      candidate++;
    } else if (candidate < array[i]) {
      break;
    }
  }

  return candidate;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::cout << find_next_integer() << '\n';

  return 0;
}
