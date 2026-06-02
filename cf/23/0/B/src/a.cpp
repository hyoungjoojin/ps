#include <cmath>
#include <iostream>

const int MAX_V = 1e6 + 1;

bool primes[MAX_V];

void compute_primes() {
  for (int i = 2; i < MAX_V; i++) {
    primes[i] = true;
  }

  for (int i = 2; i * i < MAX_V; i++) {
    if (primes[i]) {
      for (int j = i * i; j < MAX_V; j += i) {
        primes[j] = false;
      }
    }
  }
}

bool is_prime(int x) { return primes[x]; }

bool is_tprime(long long x) {
  long long root = (long long)std::sqrt(x);
  return root * root == x && is_prime(root);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  compute_primes();

  while (n--) {
    long long x;
    std::cin >> x;
    std::cout << (is_tprime(x) ? "YES" : "NO") << "\n";
  }

  return 0;
}
