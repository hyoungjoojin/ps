#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>

const int MAX_N = 5001;

int N;
std::pair<int, int> arr[MAX_N];

int target;

std::tuple<int, int, int> find() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int remainder = target - arr[i].first - arr[j].first;

      for (int li = j + 1, ri = N - 1; li <= ri;) {
        int k = li + (ri - li) / 2;

        if (remainder > arr[k].first) {
          li = k + 1;
        } else if (remainder < arr[k].first) {
          ri = k - 1;
        } else {
          return {arr[i].second, arr[j].second, arr[k].second};
        }
      }
    }
  }

  return {-1, -1, -1};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> target;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i].first;
    arr[i].second = i + 1;
  }

  std::sort(arr, arr + N);

  auto [a, b, c] = find();

  if (a == -1) {
    std::cout << "IMPOSSIBLE\n";
  } else {
    std::cout << a << ' ' << b << ' ' << c << '\n';
  }

  return 0;
}
