#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, K;
  std::cin >> N >> K;

  std::priority_queue<int, std::vector<int>, std::greater<>> pq;

  int input;
  for (int i = 0; i < K; i++) {
    std::cin >> input;
    pq.push(input);
  }

  for (int i = K; i < N; i++) {
    std::cout << pq.top() << '\n';

    std::cin >> input;
    pq.push(input);
    pq.pop();
  }

  std::cout << pq.top() << '\n';

  return 0;
}
