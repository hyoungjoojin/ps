#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_N = 2e5 + 1;

int N;
std::pair<int, int> jobs[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> jobs[i].second >> jobs[i].first;
  }

  std::sort(jobs, jobs + N);

  int time = 0;
  bool possible = true;

  for (int i = 0; i < N; i++) {
    time += jobs[i].second;
    if (time > jobs[i].first) {
      possible = false;
      break;
    }
  }

  std::cout << (possible ? "Yes\n" : "No\n");

  return 0;
}
