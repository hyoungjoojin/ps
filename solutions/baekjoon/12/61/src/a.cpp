#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MAX_N = 101;
const int MAX_M = 101;
const int INF = std::numeric_limits<int>::max();

enum { WALL = 1, EMPTY = 0 };

int N;
int M;
int grid[MAX_N][MAX_M];
int distance[MAX_N][MAX_M];

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int compute_minimum_distance() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      distance[i][j] = INF;
    }
  }

  std::priority_queue<std::pair<int, std::pair<int, int>>,
                      std::vector<std::pair<int, std::pair<int, int>>>,
                      std::greater<>>
      pq;

  distance[0][0] = 0;
  pq.push({0, {0, 0}});

  while (!pq.empty()) {
    int d = pq.top().first;
    int r = pq.top().second.first, c = pq.top().second.second;
    pq.pop();

    if (distance[r][c] < d) {
      continue;
    }

    for (int di = 0; di < 4; di++) {
      int next_r = r + directions[di][0], next_c = c + directions[di][1];
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) {
        continue;
      }

      if (grid[next_r][next_c] == WALL) {
        if (distance[next_r][next_c] > d + 1) {
          distance[next_r][next_c] = d + 1;
          pq.push({d + 1, {next_r, next_c}});
        }
      } else {
        if (distance[next_r][next_c] > d) {
          distance[next_r][next_c] = d;
          pq.push({d, {next_r, next_c}});
        }
      }
    }
  }

  return distance[N - 1][M - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> M >> N;

  std::string line;
  for (int i = 0; i < N; i++) {
    std::cin >> line;

    for (int j = 0; j < M; j++) {
      grid[i][j] = (line[j] == '1' ? WALL : EMPTY);
    }
  }

  std::cout << compute_minimum_distance() << '\n';

  return 0;
}
