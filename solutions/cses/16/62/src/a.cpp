#include <iostream>
#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  long long sum = 0, count = 0;
  std::map<long long, long long> map;

  map[0] = 1;

  int input;
  for (int i = 0; i < n; i++) {
    std::cin >> input;

    sum += input;
    sum = (sum % n + n) % n;
    count += map[sum];
    map[sum]++;
  }

  std::cout << count << '\n';

  return 0;
}
