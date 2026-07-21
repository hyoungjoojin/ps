#include <iostream>

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    int x;
    std::cin >> x;
    array[x] = i;
  }

  int result = 1;

  for (int i = 2; i <= N; i++) {
    if (array[i - 1] > array[i]) {
      result++;
    }
  }

  std::cout << result << '\n';

  return 0;
}
