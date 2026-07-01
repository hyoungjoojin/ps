#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 2e5 + 1;

int N;
int arr[MAX_N];

int get_lis_length() {
  std::vector<int> tails;

  for (int i = 0; i < N; i++) {
    auto it = std::lower_bound(tails.begin(), tails.end(), arr[i]);

    if (it == tails.end()) {
      tails.push_back(arr[i]);
    } else {
      *it = arr[i];
    }
  }

  return tails.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::cout << get_lis_length() << '\n';

  return 0;
}
