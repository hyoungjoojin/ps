#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <string>

const int MAX_N = 1001;
const int MAX_M = 1001;
const int MAX_K = 11;

enum { EMPTY = 0, WALL = 1 };

int N;
int M;
int K;
int grid[MAX_N][MAX_M];

struct State {
  int r;
  int c;
  int k;
};

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int distance[MAX_N][MAX_M][MAX_K];
std::queue<State> queue;

int get_minimum_distance() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k <= K; k++) {
        distance[i][j][k] = std::numeric_limits<int>::max();
      }
    }
  }

  distance[0][0][K] = 1;
  queue.push({0, 0, K});

  int min = std::numeric_limits<int>::max();

  while (!queue.empty()) {
    State state = queue.front();
    queue.pop();

    int r = state.r, c = state.c, k = state.k, d = distance[r][c][k];

    if (r == N - 1 && c == M - 1) {
      min = std::min(min, d);
      continue;
    }

    for (int di = 0; di < 4; di++) {
      int next_r = r + directions[di][0], next_c = c + directions[di][1];
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) {
        continue;
      }

      if (grid[next_r][next_c] == WALL && k > 0 &&
          distance[next_r][next_c][k - 1] > d + 1) {
        distance[next_r][next_c][k - 1] = d + 1;
        queue.push({next_r, next_c, k - 1});
      }

      if (grid[next_r][next_c] == EMPTY &&
          distance[next_r][next_c][k] > d + 1) {
        distance[next_r][next_c][k] = d + 1;
        queue.push({next_r, next_c, k});
      }
    }
  }

  if (min == std::numeric_limits<int>::max()) {
    return -1;
  }

  return min;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M >> K;

  std::string line;
  for (int i = 0; i < N; i++) {
    std::cin >> line;

    for (int j = 0; j < M; j++) {
      grid[i][j] = (line[j] == '0' ? EMPTY : WALL);
    }
  }

  std::cout << get_minimum_distance() << '\n';

  return 0;
}
