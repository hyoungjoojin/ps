#include <algorithm>
#include <iostream>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
int arraival[MAX_N];
int departure[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> arraival[i] >> departure[i];
  }

  std::sort(arraival, arraival + N);
  std::sort(departure, departure + N);

  int current = 0, result = 0;
  for (int i = 0, j = 0; i < N;) {
    if (arraival[i] < departure[j]) {
      result = std::max(result, ++current);
      i++;
    } else {
      current--;
      j++;
    }
  }

  std::cout << result << '\n';

  return 0;
}
