#include <iostream>
#include <queue>

const int MAX_N = 2e5 + 1;

int N;
int array[MAX_N];

std::priority_queue<int> pq;

long long get_maximum_total_power() {
  while (!pq.empty()) {
    pq.pop();
  }

  long long power = 0;
  for (int i = 0; i < N; i++) {
    if (array[i] != 0) {
      pq.push(array[i]);
    } else if (!pq.empty()) {
      power += pq.top();
      pq.pop();
    }
  }

  return power;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
      std::cin >> array[i];
    }

    std::cout << get_maximum_total_power() << '\n';
  }

  return 0;
}
