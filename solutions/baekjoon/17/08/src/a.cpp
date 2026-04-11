#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 100001;

struct Point {
  long long x;
  long long y;

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

int N;
Point points[MAX_N];

long long distance(Point &p1, Point &p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

long long ccw(Point &p1, Point &p2, Point &p3) {
  return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
}

int get_points_in_convex_hull() {
  int minimum = 0;
  for (int i = 0; i < N; i++) {
    if (points[i].y < points[minimum].y ||
        (points[i].y == points[minimum].y && points[i].x < points[minimum].x)) {
      minimum = i;
    }
  }

  Point start = points[minimum];

  std::sort(points, points + N, [&start](Point &p1, Point &p2) {
    long long orientation = ccw(start, p1, p2);
    if (orientation == 0) {
      return distance(start, p1) < distance(start, p2);
    }

    return orientation > 0;
  });

  std::vector<Point> hull;

  for (int i = 0; i < N; i++) {
    while (hull.size() >= 2 &&
           ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
      hull.pop_back();
    }

    hull.push_back(points[i]);
  }

  return hull.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> points[i].x >> points[i].y;
  }

  std::cout << get_points_in_convex_hull() << '\n';

  return 0;
}
