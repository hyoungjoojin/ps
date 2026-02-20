#include <iostream>
#include <stack>
#include <utility>

int directions[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                        {0, 1},  {1, 1},   {1, 0},  {1, -1}};
int shark_directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Cell {
  int count[8];
  bool smell[2];
};

Cell grid[4][4];
Cell copy[4][4];
Cell temp[4][4];

std::pair<int, int> shark;

void init() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        grid[i][j].count[k] = 0;
      }

      grid[i][j].smell[0] = false;
      grid[i][j].smell[1] = false;
    }
  }
}

void duplicate() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        copy[i][j].count[k] = grid[i][j].count[k];
      }
    }
  }
}

void copy_duplicate() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        grid[i][j].count[k] += copy[i][j].count[k];
      }
    }
  }
}

void move_fish() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        temp[i][j].count[k] = 0;
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        int count = grid[i][j].count[k];
        if (count == 0) {
          continue;
        }

        bool moved = false;

        int dir, next_r, next_c;
        for (int d = 0; d < 8; d++) {
          dir = (k - d + 8) % 8;
          next_r = i + directions[dir][0], next_c = j + directions[dir][1];

          if (next_r < 0 || next_r >= 4 || next_c < 0 || next_c >= 4) {
            continue;
          }

          if (shark.first == next_r && shark.second == next_c) {
            continue;
          }

          if (grid[next_r][next_c].smell[0] || grid[next_r][next_c].smell[1]) {
            continue;
          }

          temp[next_r][next_c].count[dir] += count;
          moved = true;
          break;
        }

        if (!moved) {
          temp[i][j].count[k] += count;
        }
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        grid[i][j].count[k] = temp[i][j].count[k];
      }
    }
  }
}

int paths[64][3] = {
    {0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 1, 0}, {0, 1, 1}, {0, 1, 2},
    {0, 1, 3}, {0, 2, 0}, {0, 2, 1}, {0, 2, 2}, {0, 2, 3}, {0, 3, 0}, {0, 3, 1},
    {0, 3, 2}, {0, 3, 3}, {1, 0, 0}, {1, 0, 1}, {1, 0, 2}, {1, 0, 3}, {1, 1, 0},
    {1, 1, 1}, {1, 1, 2}, {1, 1, 3}, {1, 2, 0}, {1, 2, 1}, {1, 2, 2}, {1, 2, 3},
    {1, 3, 0}, {1, 3, 1}, {1, 3, 2}, {1, 3, 3}, {2, 0, 0}, {2, 0, 1}, {2, 0, 2},
    {2, 0, 3}, {2, 1, 0}, {2, 1, 1}, {2, 1, 2}, {2, 1, 3}, {2, 2, 0}, {2, 2, 1},
    {2, 2, 2}, {2, 2, 3}, {2, 3, 0}, {2, 3, 1}, {2, 3, 2}, {2, 3, 3}, {3, 0, 0},
    {3, 0, 1}, {3, 0, 2}, {3, 0, 3}, {3, 1, 0}, {3, 1, 1}, {3, 1, 2}, {3, 1, 3},
    {3, 2, 0}, {3, 2, 1}, {3, 2, 2}, {3, 2, 3}, {3, 3, 0}, {3, 3, 1}, {3, 3, 2},
    {3, 3, 3},
};

int visited[4][4] = {0};
std::stack<std::pair<int, int>> stack;

int get_path() {
  int max = 0, max_index = 0;

  for (int p = 63; p >= 0; p--) {
    int r = shark.first, c = shark.second, fish = 0;
    bool valid = true;

    for (int i = 0; i < 3; i++) {
      r += shark_directions[paths[p][i]][0];
      c += shark_directions[paths[p][i]][1];

      if (r < 0 || r >= 4 || c < 0 || c >= 4) {
        valid = false;
        break;
      }

      if (!visited[r][c]) {
        for (int j = 0; j < 8; j++) {
          fish += grid[r][c].count[j];
        }

        visited[r][c] = 1;
        stack.push({r, c});
      }
    }

    while (!stack.empty()) {
      visited[stack.top().first][stack.top().second] = 0;
      stack.pop();
    }

    if (valid && fish >= max) {
      max = fish;
      max_index = p;
    }
  }

  return max_index;
}

void move_shark() {
  int p = get_path();

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      grid[i][j].smell[0] = grid[i][j].smell[1];
      grid[i][j].smell[1] = false;
    }
  }

  for (int i = 0; i < 3; i++) {
    shark.first += shark_directions[paths[p][i]][0];
    shark.second += shark_directions[paths[p][i]][1];

    int fish = 0;
    for (int j = 0; j < 8; j++) {
      fish += grid[shark.first][shark.second].count[j];
      grid[shark.first][shark.second].count[j] = 0;
    }

    if (fish > 0) {
      grid[shark.first][shark.second].smell[1] = true;
    }
  }
}

int count() {
  int result = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 8; k++) {
        result += grid[i][j].count[k];
      }
    }
  }

  return result;
}

int iterate() {
  duplicate();

  move_fish();
  move_shark();
  copy_duplicate();

  return count();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  init();

  int num_fish, iterations;
  std::cin >> num_fish >> iterations;

  int r, c, d;
  for (int i = 0; i < num_fish; i++) {
    std::cin >> r >> c >> d;
    grid[r - 1][c - 1].count[d - 1]++;
  }

  std::cin >> shark.first >> shark.second;
  shark.first--;
  shark.second--;

  int count = num_fish;
  while (iterations--) {
    count = iterate();
  }

  std::cout << count << '\n';

  return 0;
}
