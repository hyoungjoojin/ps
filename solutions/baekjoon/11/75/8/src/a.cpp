#include <iostream>

struct Point {
  int x;
  int y;
};

int ccw(Point &p1, Point &p2, Point &p3) {
  long long cross_product =
      (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);

  if (cross_product > 0) {
    return 1;
  } else if (cross_product < 0) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  Point points[3];
  for (int i = 0; i < 3; i++) {
    std::cin >> points[i].x >> points[i].y;
  }

  std::cout << ccw(points[0], points[1], points[2]) << '\n';

  return 0;
}
