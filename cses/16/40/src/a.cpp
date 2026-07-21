#include <iostream>
#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, x;
  std::cin >> N >> x;

  std::map<int, int> map;

  bool found = false;

  for (int i = 1; i <= N; i++) {
    int a;
    std::cin >> a;

    if (map.find(x - a) != map.end()) {
      std::cout << map[x - a] << ' ' << i << '\n';
      found = true;
      break;
    }

    map[a] = i;
  }

  if (!found) {
    std::cout << "IMPOSSIBLE\n";
  }

  return 0;
}
