#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

const int MAX_N = 51;

enum { WATER = 1, LAND = 2 };

int W;
int H;
int grid[MAX_N][MAX_N];
int distance[MAX_N][MAX_N];

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void init_distance() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      distance[i][j] = -1;
    }
  }
}

int get_distance() {
  int result = 0;
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == WATER) {
        continue;
      }

      init_distance();

      int max_distance = 0;
      distance[i][j] = 0;
      queue.push({i, j});

      while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();

        for (int di = 0; di < 4; di++) {
          int next_r = r + directions[di][0], next_c = c + directions[di][1];
          if (next_r < 0 || next_r >= H || next_c < 0 || next_c >= W ||
              grid[next_r][next_c] == WATER || distance[next_r][next_c] != -1) {
            continue;
          }

          distance[next_r][next_c] = distance[r][c] + 1;
          max_distance = std::max(max_distance, distance[next_r][next_c]);
          queue.push({next_r, next_c});
        }
      }

      result = std::max(result, max_distance);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> H >> W;

  std::string line;
  for (int i = 0; i < H; i++) {
    std::cin >> line;

    for (int j = 0; j < W; j++) {
      if (line[j] == 'W') {
        grid[i][j] = WATER;
      } else {
        grid[i][j] = LAND;
      }
    }
  }

  std::cout << get_distance() << '\n';

  return 0;
}
