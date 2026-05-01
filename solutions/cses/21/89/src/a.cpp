#include <iostream>

long long cross_product(int x1, int y1, int x2, int y2, int x3, int y3) {
  long long vx = x2 - x1, vy = y2 - y1;
  long long ux = x3 - x1, uy = y3 - y1;
  return vx * uy - vy * ux;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  int x1, y1, x2, y2, x3, y3;
  for (int i = 0; i < t; i++) {
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long long c = cross_product(x1, y1, x2, y2, x3, y3);
    if (c > 0) {
      std::cout << "LEFT\n";
    } else if (c < 0) {
      std::cout << "RIGHT\n";
    } else {
      std::cout << "TOUCH\n";
    }
  }

  return 0;
}
