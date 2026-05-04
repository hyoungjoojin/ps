#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  long long health = 0;
  std::priority_queue<int, std::vector<int>, std::greater<>> pq;

  int a;
  for (int i = 0; i < N; i++) {
    std::cin >> a;

    pq.push(a);
    health += a;

    while (health < 0) {
      health -= pq.top();
      pq.pop();
    }
  }

  std::cout << pq.size() << '\n';

  return 0;
}
