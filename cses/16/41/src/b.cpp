#include <algorithm>
#include <iostream>

const int MAX_N = 5001;

int N;
std::pair<int, int> arr[MAX_N];

int target;

std::tuple<int, int, int> find() {
  for (int i = 0; i < N; i++) {
    int remainder = target - arr[i].first;

    for (int li = i + 1, ri = N - 1; li < ri;) {
      int sum = arr[li].first + arr[ri].first;

      if (sum < remainder) {
        li++;
      } else if (sum > remainder) {
        ri--;
      } else {
        return {arr[i].second, arr[li].second, arr[ri].second};
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
