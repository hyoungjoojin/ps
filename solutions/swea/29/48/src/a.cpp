#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  int n, m;
  std::unordered_map<std::string, bool> map;
  std::string input;

  for (int t = 1; t <= T; t++) {
    std::cin >> n >> m;

    while (n--) {
      std::cin >> input;
      map[input] = true;
    }

    int count = 0;

    while (m--) {
      std::cin >> input;

      if (map.find(input) != map.end()) {
        count++;
      }
    }

    map.clear();
    std::cout << '#' << t << ' ' << count << '\n';
  }

  return 0;
}
