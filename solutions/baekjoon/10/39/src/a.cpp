#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

const int MAX_LENGTH = 9;

int N;
int M;

int get_number_length(int x) {
  int length = 0;
  while (x) {
    x /= 10;
    length++;
  }

  return length;
}

int digits[MAX_LENGTH];
int swap(int x, int i, int j) {
  for (int i = M - 1; i >= 0; i--) {
    digits[i] = x % 10;
    x /= 10;
  }

  std::swap(digits[i], digits[j]);

  if (digits[0] == 0) {
    return -1;
  }

  int result = 0;
  for (int i = 0; i < M; i++) {
    result += digits[i];
    result *= 10;
  }

  return result / 10;
}

std::unordered_map<int, bool> visited[11];

int get_max(int num_operations) {
  std::queue<std::pair<int, int>> queue;

  int result = 0;
  queue.push({N, 0});
  visited[0][N] = true;

  while (!queue.empty()) {
    int number = queue.front().first, k = queue.front().second;
    queue.pop();

    if (k == num_operations) {
      result = std::max(result, number);
      continue;
    }

    for (int i = 0; i < M; i++) {
      for (int j = i + 1; j < M; j++) {
        int swapped = swap(number, i, j);
        if (swapped != -1 &&
            visited[k + 1].find(swapped) == visited[k + 1].end()) {
          queue.push({swapped, k + 1});
          visited[k + 1][swapped] = true;
        }
      }
    }
  }

  return (result == 0 ? -1 : result);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;
  std::cin >> N >> k;
  M = get_number_length(N);

  std::cout << get_max(k) << '\n';

  return 0;
}
