#include <iostream>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x, n;
  std::cin >> x >> n;

  std::set<int> lights = {0, x};
  std::multiset<int> gaps = {x};

  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;

    auto next = lights.upper_bound(p);
    auto prev = std::prev(next);

    gaps.erase(gaps.find(*next - *prev));
    gaps.insert(p - *prev);
    gaps.insert(*next - p);

    lights.insert(p);

    std::cout << *gaps.rbegin() << " ";
  }

  std::cout << '\n';

  return 0;
}
