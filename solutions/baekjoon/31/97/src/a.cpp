#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_R = 1501;
const int MAX_C = 1501;

enum { LAND = 0, WATER = 1 };

int R;
int C;
int grid[MAX_R][MAX_C];

std::pair<int, int> swans[2];

int melting_day[MAX_R][MAX_C];

std::priority_queue<std::pair<int, std::pair<int, int>>,
                    std::vector<std::pair<int, std::pair<int, int>>>,
                    std::greater<>>
    melt_schedule;

int oceans[MAX_R * MAX_C];

int get_ocean_index(int r, int c) { return r * C + c; }

bool visited[MAX_R][MAX_C];
std::queue<std::pair<int, int>> queue;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int find_ocean(int i) {
  if (i == oceans[i]) {
    return i;
  }

  return oceans[i] = find_ocean(oceans[i]);
}

void merge_oceans(int r1, int c1, int r2, int c2) {
  int o1 = find_ocean(get_ocean_index(r1, c1)),
      o2 = find_ocean(get_ocean_index(r2, c2));

  if (o1 != o2) {
    oceans[o1] = o2;
  }
}

void build_oceans() {
  for (int i = 0; i < R * C; i++) {
    oceans[i] = i;
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (visited[i][j] || grid[i][j] == LAND) {
        continue;
      }

      visited[i][j] = true;
      queue.push({i, j});

      while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();

        for (int di = 0; di < 4; di++) {
          int next_r = r + d[di][0], next_c = c + d[di][1];
          if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C ||
              visited[next_r][next_c] || grid[next_r][next_c] == LAND) {
            continue;
          }

          merge_oceans(r, c, next_r, next_c);
        }
      }
    }
  }
}

void get_melt_schedule() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      melting_day[i][j] = 0;
      visited[i][j] = false;
    }
  }

  std::queue<std::pair<int, int>> melting_queue;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (visited[i][j] || grid[i][j] == WATER) {
        continue;
      }

      visited[i][j] = true;
      queue.push({i, j});

      while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();

        for (int di = 0; di < 4; di++) {
          int next_r = r + d[di][0], next_c = c + d[di][1];
          if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C ||
              visited[next_r][next_c]) {
            continue;
          }

          if (grid[next_r][next_c] == WATER) {
            visited[next_r][next_c] = true;
            melting_day[r][c] = 1;
            melting_queue.push({next_r, next_c});
          } else {
            visited[next_r][next_c] = true;
            queue.push({next_r, next_c});
          }
        }
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visited[i][j] = false;
    }
  }

  while (!melting_queue.empty()) {
    int r = melting_queue.front().first, c = melting_queue.front().second;
    melting_queue.pop();

    for (int di = 0; di < 4; di++) {
      int next_r = r + d[di][0], next_c = c + d[di][1];
      if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C ||
          visited[next_r][next_c] || grid[next_r][next_c] == WATER) {
        continue;
      }

      visited[next_r][next_c] = true;
      melting_day[next_r][next_c] = melting_day[r][c] + 1;
      melting_queue.push({next_r, next_c});
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (melting_day[i][j] != 0) {
        melt_schedule.push({melting_day[i][j], {i, j}});
      }
    }
  }
}

bool can_reach() {
  int o1 = find_ocean(get_ocean_index(swans[0].first, swans[0].second)),
      o2 = find_ocean(get_ocean_index(swans[1].first, swans[1].second));
  return o1 == o2;
}

void melt(int day) {
  while (!melt_schedule.empty()) {
    if (melt_schedule.top().first > day) {
      break;
    }

    int r = melt_schedule.top().second.first,
        c = melt_schedule.top().second.second;
    melt_schedule.pop();

    grid[r][c] = WATER;

    for (int di = 0; di < 4; di++) {
      int next_r = r + d[di][0], next_c = c + d[di][1];
      if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C ||
          grid[next_r][next_c] == LAND) {
        continue;
      }

      merge_oceans(r, c, next_r, next_c);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C;

  char input;
  int num_swans = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> input;

      if (input == 'L') {
        swans[num_swans++] = {i, j};
        grid[i][j] = WATER;
      } else if (input == '.') {
        grid[i][j] = WATER;
      } else {
        grid[i][j] = LAND;
      }
    }
  }

  build_oceans();
  get_melt_schedule();

  int days = 0;
  while (!can_reach()) {
    melt(++days);
  }

  std::cout << days << '\n';

  return 0;
}
