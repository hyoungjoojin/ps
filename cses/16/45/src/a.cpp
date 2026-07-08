#include <iostream>
#include <stack>
#include <utility>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  std::stack<std::pair<int, int>> stack;

  for (int i = 1; i <= N; i++) {
    int x;
    std::cin >> x;

    while (!stack.empty() && stack.top().first >= x) {
      stack.pop();
    }

    std::cout << (stack.empty() ? 0 : stack.top().second) << ' ';

    stack.push({x, i});
  }

  std::cout << '\n';

  return 0;
}
