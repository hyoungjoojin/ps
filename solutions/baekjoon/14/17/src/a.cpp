#include <iostream>
#include <queue>

const int MAX_N = 51;

int N;
int array[MAX_N];

int get_minimum_people() {
  int result = 0;
  std::priority_queue<int> pq;
  for (int i = 1; i < N; i++) {
    pq.push(array[i]);
  }

  while (!pq.empty()) {
    int top = pq.top();
    pq.pop();

    if (top < array[0]) {
      break;
    }

    result++;
    array[0]++;
    pq.push({top - 1});
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  std::cout << get_minimum_people() << '\n';

  return 0;
}
