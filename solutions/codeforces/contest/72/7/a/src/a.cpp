#include <iostream>
#include <utility>
#include <vector>

std::vector<int> find_path(int a, int b) {
  std::vector<int> path;

  path.push_back(b);

  while (b > a) {
    if (b % 2 == 0) {
      b /= 2;
    } else if (b % 10 == 1) {
      b /= 10;
    } else {
      break;
    }

    path.push_back(b);
  }

  for (int li = 0, ri = path.size() - 1; li < ri; li++, ri--) {
    std::swap(path[li], path[ri]);
  }

  if (path[0] != a) {
    return std::vector<int>();
  } else {
    return path;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b;
  std::cin >> a >> b;

  std::vector<int> path = find_path(a, b);

  if (path.empty()) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    std::cout << path.size() << '\n';

    for (int &i : path) {
      std::cout << i << ' ';
    }
  }

  return 0;
}
