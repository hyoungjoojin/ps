#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string dna;
  std::cin >> dna;

  int maximum = 0, current = 0;
  char previous = dna[0];

  for (char ch : dna) {
    if (ch == previous) {
      current++;
    } else {
      maximum = std::max(maximum, current);
      current = 1;
      previous = ch;
    }
  }

  maximum = std::max(maximum, current);

  std::cout << maximum << '\n';

  return 0;
}
