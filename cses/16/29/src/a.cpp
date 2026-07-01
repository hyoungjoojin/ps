#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_N = 2e5 + 1;

int N;
std::pair<int, int> movies[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> movies[i].first >> movies[i].second;
  }

  std::sort(movies, movies + N,
            [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
              return p1.second < p2.second;
            });

  int count = 0, current = 0;
  for (int i = 0; i < N; i++) {
    if (movies[i].first >= current) {
      current = movies[i].second;
      count++;
    }
  }

  std::cout << count << '\n';

  return 0;
}
