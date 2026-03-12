#include <iostream>

int f(int x) {
  int m[2] = {0, 1};
  if (x <= 1) {
    return m[x];
  }

  for (int i = 2; i <= x; i++) {
    int t = m[0] + m[1];
    m[0] = m[1];
    m[1] = t;
  }

  return m[1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::cout << f(n) << "\n";

  return 0;
}
