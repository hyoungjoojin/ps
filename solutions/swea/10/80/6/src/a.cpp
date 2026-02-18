#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int n;
int a[11];

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<>>
    pq;

int get_count(int target) {
  pq.push({0, target});

  int result = 0;

  while (!pq.empty()) {
    int count = pq.top().first, x = pq.top().second;
    pq.pop();

    if (x == 0) {
      result = count;
      break;
    }

    pq.push({count + x, 0});

    for (int i = 0; i < n; i++) {
      pq.push({count + x % a[i], x / a[i]});
    }
  }

  while (!pq.empty()) {
    pq.pop();
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int target;
    std::cin >> target;

    std::cout << '#' << t << ' ' << get_count(target) << '\n';
  }

  return 0;
}
