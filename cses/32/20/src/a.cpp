#include <iostream>
#include <queue>

using ll = long long;

int n, k;
ll x, a, b, c;

ll get_next_number(int current) { return (current * a + b) % c; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n >> k;
  std::cin >> x >> a >> b >> c;

  ll sum = 0, current = x;
  std::queue<ll> window;

  for (int i = 0; i < k; i++, current = get_next_number(current)) {
    sum += current;
    window.push(current);
  }

  ll result = sum;

  for (int i = k; i < n; i++, current = get_next_number(current)) {
    sum += current;
    window.push(current);

    sum -= window.front();
    window.pop();

    result = result ^ sum;
  }

  std::cout << result << '\n';

  return 0;
}
