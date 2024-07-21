#include <iostream>
#include <vector>

long long fibonacci(int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::cout << fibonacci(N) << '\n';

  return 0;
}

long long fibonacci(int N) {
  if (N == 0 || N == 1)
    return N;

  std::vector<long long> fibonacci_numbers(N + 1, -1);
  fibonacci_numbers[0] = 0;
  fibonacci_numbers[1] = 1;

  for (int i = 2; i <= N; i++)
    fibonacci_numbers[i] = fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2];

  return fibonacci_numbers[N];
}
