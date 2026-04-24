#include <iostream>
#include <queue>
#include <string>
#include <utility>

const int MAX_N = 1001;
const int MAX_M = 1001;

enum { FLOOR = 0, WALL = 1 };

constexpr int DIRECTIONS[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int N;
int M;
int grid[MAX_N][MAX_M];

bool visited[MAX_N][MAX_M];

int get_number_of_rooms() {
  int rooms = 0;
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] || grid[i][j] == WALL) {
        continue;
      }

      rooms++;
      visited[i][j] = true;
      queue.push({i, j});

      while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();

        for (int di = 0; di < 4; di++) {
          int next_r = r + DIRECTIONS[di][0], next_c = c + DIRECTIONS[di][1];
          if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M ||
              visited[next_r][next_c] || grid[next_r][next_c] == WALL) {
            continue;
          }

          visited[next_r][next_c] = true;
          queue.push({next_r, next_c});
        }
      }
    }
  }

  return rooms;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  std::string line;
  for (int i = 0; i < N; i++) {
    std::cin >> line;

    for (int j = 0; j < M; j++) {
      grid[i][j] = (line[j] == '#' ? WALL : FLOOR);
    }
  }

  std::cout << get_number_of_rooms() << '\n';

  return 0;
}
