#include <algorithm>
#include <iostream>

using ll = long long;

std::string sandwich;

int nb, ns, nc;
int pb, ps, pc;
ll r;

ll get_maximum_count() {
  int rb = 0, rs = 0, rc = 0;
  for (char ch : sandwich) {
    switch (ch) {
    case 'B':
      rb++;
      break;
    case 'S':
      rs++;
      break;
    case 'C':
      rc++;
      break;
    }
  }

  ll result = 0;
  for (ll li = 0, ri = r + nb + ns + nc; li <= ri;) {
    ll count = li + (ri - li) / 2;

    ll p = std::max(count * rb - nb, 0LL) * pb +
           std::max(count * rs - ns, 0LL) * ps +
           std::max(count * rc - nc, 0LL) * pc;

    if (p <= r) {
      result = std::max(result, count);
      li = count + 1;
    } else {
      ri = count - 1;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> sandwich;

  std::cin >> nb >> ns >> nc;
  std::cin >> pb >> ps >> pc;
  std::cin >> r;

  std::cout << get_maximum_count() << '\n';

  return 0;
}
