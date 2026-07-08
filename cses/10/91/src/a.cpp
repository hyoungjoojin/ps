#include <iostream>
#include <iterator>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::multiset<int> set;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;
    set.insert(x);
  }

  for (int i = 0; i < M; i++) {
    int x;
    std::cin >> x;

    auto next = set.upper_bound(x);
    if (next == set.begin()) {
      std::cout << "-1\n";
      continue;
    }

    auto ticket = std::prev(next);
    std::cout << *ticket << '\n';

    set.erase(ticket);
  }

  return 0;
}
