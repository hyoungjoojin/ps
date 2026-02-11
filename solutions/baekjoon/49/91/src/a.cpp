#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

enum { EMPTY = -1, BLOCKED = -2 };

int w;
int h;
int grid[21][21];

int num_spots;
int spots[11][2];
int distance[11][11];

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void compute_distance() {
  std::queue<std::pair<int, int>> queue;
  int _distance[21][21];

  for (int start = 0; start < num_spots; start++) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        _distance[i][j] = -1;
      }
    }

    _distance[spots[start][0]][spots[start][1]] = 0;
    queue.push({spots[start][0], spots[start][1]});

    while (!queue.empty()) {
      int r = queue.front().first, c = queue.front().second;
      queue.pop();

      if (grid[r][c] >= 0) {
        distance[start][grid[r][c]] = _distance[r][c];
      }

      for (int di = 0; di < 4; di++) {
        int next_r = r + d[di][0], next_c = c + d[di][1];
        if (next_r < 0 || next_r >= h || next_c < 0 || next_c >= w ||
            _distance[next_r][next_c] != -1 ||
            grid[next_r][next_c] == BLOCKED) {
          continue;
        }

        _distance[next_r][next_c] = _distance[r][c] + 1;
        queue.push({next_r, next_c});
      }
    }
  }
}

int _compute_minimum_recursive(std::vector<bool> &visited, int current,
                               int num_visited) {
  if (num_visited == num_spots) {
    return 0;
  }

  int cost = std::numeric_limits<int>::max();

  for (int i = 0; i < num_spots; i++) {
    if (!visited[i]) {
      visited[i] = true;
      cost = std::min(
          cost, distance[current][i] +
                    _compute_minimum_recursive(visited, i, num_visited + 1));
      visited[i] = false;
    }
  }

  return cost;
}

int compute_minimum() {
  std::vector<bool> visited(num_spots);
  visited[0] = true;

  return _compute_minimum_recursive(visited, 0, 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string line;

  while (true) {
    std::cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    int index = 1;

    for (int i = 0; i < h; i++) {
      std::cin >> line;

      for (int j = 0; j < w; j++) {
        if (line[j] == '.') {
          grid[i][j] = EMPTY;
        } else if (line[j] == 'x') {
          grid[i][j] = BLOCKED;
        } else if (line[j] == '*') {
          grid[i][j] = index;
          spots[index][0] = i;
          spots[index][1] = j;
          index++;
        } else {
          grid[i][j] = 0;
          spots[0][0] = i;
          spots[0][1] = j;
        }
      }
    }

    num_spots = index;
    for (int i = 0; i < num_spots; i++) {
      for (int j = 0; j < num_spots; j++) {
        distance[i][j] = -1;
      }
    }

    compute_distance();

    bool is_possible = true;
    for (int i = 0; i < num_spots; i++) {
      for (int j = 0; j < num_spots; j++) {
        if (distance[i][j] == -1) {
          is_possible = false;
        }
      }
    }

    std::cout << (is_possible ? compute_minimum() : -1) << '\n';
  }

  return 0;
}
