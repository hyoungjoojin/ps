#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<std::pair<int, int>>>
    pq;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, l;
  std::cin >> n >> l;

  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;

    pq.push({x, i});

    int min;
    while (true) {
      int value = pq.top().first, index = pq.top().second;

      if (index <= i - l) {
        pq.pop();
        continue;
      } else {
        min = value;
        break;
      }
    }

    std::cout << min << ' ';
  }

  return 0;
}
