#include <iostream>
#include <map>

const int MAX_NUMBERS = 200001;

int array[MAX_NUMBERS];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int size, target;
  std::cin >> size >> target;

  long long count = 0, sum = 0;
  std::map<long long, long long> map;

  map[0] = 1;

  long long input;
  for (int i = 0; i < size; i++) {
    std::cin >> input;

    sum += input;
    count += map[sum - target];
    map[sum]++;
  }

  std::cout << count << "\n";

  return 0;
}
