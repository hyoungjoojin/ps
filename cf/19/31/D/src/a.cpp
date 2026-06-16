#include <iostream>
#include <map>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int x;
int y;

ll encode(int a, int b) {
  ll result = a;
  return (result << 32) + b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    std::cin >> N >> x >> y;

    for (int i = 0; i < N; i++) {
      std::cin >> array[i];
    }

    std::map<ll, int> h;
    ll count = 0;

    for (int i = 0; i < N; i++) {
      int mx = array[i] % x, my = array[i] % y;

      count += h[encode((x - mx) % x, my)];

      h[encode(mx, my)]++;
    }

    std::cout << count << '\n';
  }

  return 0;
}
