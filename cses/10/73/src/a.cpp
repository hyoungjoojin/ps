#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> towers;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;

    auto it = std::upper_bound(towers.begin(), towers.end(), x);
    if (it == towers.end()) {
      towers.push_back(x);
    } else {
      *it = x;
    }
  }

  std::cout << towers.size() << "\n";

  return 0;
}
