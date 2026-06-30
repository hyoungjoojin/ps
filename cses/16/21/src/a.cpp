#include <algorithm>
#include <iostream>

const int MAX_N = 2e5 + 1;

int N;
int arr[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + N);

  int result = 1, current = arr[0];

  for (int i = 1; i < N; i++) {
    if (current != arr[i]) {
      result++;
      current = arr[i];
    }
  }

  std::cout << result << '\n';

  return 0;
}
