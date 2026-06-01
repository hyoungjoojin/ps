#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_N = 1e5 + 1;

int N;
std::pair<int, int> laptops[MAX_N];

bool is_alex_happy() {
  std::sort(laptops, laptops + N,
            [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
              return p1.first < p2.first;
            });

  for (int i = 1; i < N; i++) {
    if (laptops[i - 1].second > laptops[i].second) {
      return true;
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> laptops[i].first >> laptops[i].second;
  }

  std::cout << (is_alex_happy() ? "Happy Alex\n" : "Poor Alex\n");

  return 0;
}
