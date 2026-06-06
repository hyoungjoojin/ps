#include <iostream>

long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }

bool coprime(long long x, long long y) { return gcd(x, y) == 1; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long l, r;
  std::cin >> l >> r;

  long long a = -1, b = -1, c = -1;
  bool found = false;

  for (long long i = l; i <= r; i++) {
    for (long long j = i + 1; j <= r; j++) {
      for (long long k = j + 1; k <= r; k++) {
        if (coprime(i, j) && coprime(j, k) && !coprime(i, k)) {
          a = i;
          b = j;
          c = k;
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }
  }

  if (found) {
    std::cout << a << " " << b << " " << c << "\n";
  } else {
    std::cout << "-1\n";
  }

  return 0;
}
