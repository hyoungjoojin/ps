#include <iostream>
#include <map>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

int K;

ll get_number_of_subarrays() {
  ll count = 0;
  std::map<int, int> map;

  for (int li = 0, ri = 0; li < N; li++) {
    while (ri < N && (map[array[ri]] != 0 || map.size() <= K)) {
      map[array[ri++]]++;
    }

    count += (ri - li);

    if (--map[array[li]] == 0) {
      map.erase(array[li]);
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::cout << get_number_of_subarrays() << '\n';

  return 0;
}
