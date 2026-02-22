#include <algorithm>
#include <iostream>

const int MAX_SIZE = 200001;

int n;
int array[MAX_SIZE];

int k;

int get_minimum_operations() {
  std::sort(array, array + n);

  int median = n / 2;

  int result = array[median];
  for (int li = array[median], ri = array[median] + k; li <= ri;) {
    int mid = li + (ri - li) / 2;

    long long operations = 0;
    for (int i = median; i < n; i++) {
      operations += std::max(0, mid - array[i]);
    }

    if (operations <= k) {
      result = std::max(result, mid);
      li = mid + 1;
    } else {
      ri = mid - 1;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n >> k;

  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  std::cout << get_minimum_operations() << '\n';

  return 0;
}
