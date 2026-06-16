#include <iostream>
#include <set>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
ll psum[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    std::cin >> N;

    psum[0] = 0;
    for (int i = 1; i <= N; i++) {
      int a;
      std::cin >> a;

      psum[i] = psum[i - 1] + (i % 2 == 1 ? -a : a);
    }

    std::set<ll> set;
    bool found = false;

    for (int i = 0; i <= N; i++) {
      if (set.find(psum[i]) != set.end()) {
        found = true;
        break;
      }

      set.insert(psum[i]);
    }

    std::cout << (found ? "YES\n" : "NO\n");
  }

  return 0;
}
