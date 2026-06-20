#include <algorithm>
#include <iostream>

using ll = long long;

const int MAX_N = 1e5 + 1;

int N;
ll array[MAX_N];

ll get_maximum_points() {
  ll take = 0, skip = 0;
  for (int i = 1; i < MAX_N; i++) {
    ll a = skip + array[i], b = std::max(skip, take);
    take = a;
    skip = b;
  }

  return std::max(take, skip);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;
    array[x] += x;
  }

  std::cout << get_maximum_points() << '\n';

  return 0;
}
