#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string a, b;
  std::cin >> a >> b;

  for (int i = 0; i < a.length(); i++) {
    std::cout << (a[i] == b[i] ? '0' : '1');
  }

  std::cout << '\n';

  return 0;
}
