#include <iostream>
#include <queue>
#include <utility>

const int MAX_R = 101;
const int MAX_C = 101;

enum { EMPTY = 0, CHEESE = 1 };

int R;
int C;
int grid[MAX_R][MAX_C];

int cheese_count;

int visited[MAX_R][MAX_C];
std::queue<std::pair<int, int>> queue;
std::queue<std::pair<int, int>> melt_queue;

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void init() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visited[i][j] = false;
    }
  }
}

void melt() {
  if (queue.empty()) {
    queue.push({0, 0});
    visited[0][0] = true;
  }

  while (!queue.empty()) {
    int r = queue.front().first, c = queue.front().second;
    queue.pop();

    for (int di = 0; di < 4; di++) {
      int next_r = r + directions[di][0], next_c = c + directions[di][1];
      if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C ||
          visited[next_r][next_c]) {
        continue;
      }

      visited[next_r][next_c] = true;

      if (grid[next_r][next_c] == CHEESE) {
        melt_queue.push({next_r, next_c});
      } else {
        queue.push({next_r, next_c});
      }
    }
  }

  while (!melt_queue.empty()) {
    int r = melt_queue.front().first, c = melt_queue.front().second;
    melt_queue.pop();

    if (grid[r][c] == CHEESE) {
      queue.push({r, c});
      grid[r][c] = EMPTY;
      cheese_count--;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C;

  int input;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> input;
      grid[i][j] = (input == 0 ? EMPTY : CHEESE);

      if (grid[i][j] == CHEESE) {
        cheese_count++;
      }
    }
  }

  init();

  int time = 0, count = 0;

  while (true) {
    if (cheese_count == 0) {
      break;
    }

    count = cheese_count;
    melt();
    time++;
  }

  std::cout << time << '\n' << count << '\n';

  return 0;
}
