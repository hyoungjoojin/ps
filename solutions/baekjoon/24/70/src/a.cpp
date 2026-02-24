#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>

const int MAX_NUMBERS = 100001;

int N;
int array[MAX_NUMBERS];

struct Result {
  int a;
  int b;
};

Result get_result() {
  Result result = {0, 0};
  int result_value = std::numeric_limits<int>::max();

  for (int i = 0; i < N; i++) {
    int target = -array[i];

    for (int li = i + 1, ri = N - 1; li <= ri;) {
      int mid = (li + ri) / 2;
      int sum = std::abs(array[i] + array[mid]);

      if (sum < result_value) {
        result_value = sum;
        result.a = array[i];
        result.b = array[mid];
      }

      if (array[mid] > target) {
        ri = mid - 1;
      } else {
        li = mid + 1;
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::sort(array, array + N);

  Result result = get_result();
  std::cout << result.a << ' ' << result.b << '\n';

  return 0;
}
