#include <iostream>

const int MAX_SIZE = 1e6 + 1;

int n;
int array[MAX_SIZE];

int b;
int c;

int ceil(int x, int y) {
  int result = x / y;
  int remainder = x % y;

  return result + (remainder == 0 ? 0 : 1);
}

long long count() {
  long long result = 0;
  for (int i = 0; i < n; i++) {
    result += 1 + ceil(std::max(array[i] - b, 0), c);
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  std::cin >> b >> c;

  std::cout << count() << '\n';

  return 0;
}
