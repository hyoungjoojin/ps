#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_N = 2e5 + 1;
const int MAX_M = 2e5 + 1;

int N;
int M;
int K;
std::pair<int, int> applicants[MAX_N];
int apartments[MAX_M];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;
    applicants[i] = {x - K, x + K};
  }

  for (int i = 0; i < M; i++) {
    std::cin >> apartments[i];
  }

  std::sort(applicants, applicants + N);
  std::sort(apartments, apartments + M);

  int result = 0;

  for (int i = 0, j = 0; i < N && j < M;) {
    if (apartments[j] < applicants[i].first) {
      j++;
    } else if (apartments[j] > applicants[i].second) {
      i++;
    } else {
      result++;
      i++;
      j++;
    }
  }

  std::cout << result << '\n';

  return 0;
}
