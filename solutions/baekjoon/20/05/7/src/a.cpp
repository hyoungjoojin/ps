#include <iostream>

const int MAX_N = 500;

int N;
int grid[MAX_N][MAX_N];

int r;
int c;
int d;

int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int blocks[4][10][3] = {
    {{0, -2, 55},
     {0, -3, 5},
     {-1, -2, 10},
     {1, -2, 10},
     {-1, -1, 7},
     {1, -1, 7},
     {-2, -1, 2},
     {2, -1, 2},
     {-1, 0, 1},
     {1, 0, 1}},
    {{2, 0, 55},
     {3, 0, 5},
     {2, 1, 10},
     {2, -1, 10},
     {1, -1, 7},
     {1, 1, 7},
     {1, -2, 2},
     {1, 2, 2},
     {0, 1, 1},
     {0, -1, 1}},
    {{0, 2, 55},
     {0, 3, 5},
     {-1, 2, 10},
     {1, 2, 10},
     {-1, 1, 7},
     {1, 1, 7},
     {-2, 1, 2},
     {2, 1, 2},
     {-1, 0, 1},
     {1, 0, 1}},
    {{-2, 0, 55},
     {-3, 0, 5},
     {-2, 1, 10},
     {-2, -1, 10},
     {-1, -1, 7},
     {-1, 1, 7},
     {-1, -2, 2},
     {-1, 2, 2},
     {0, 1, 1},
     {0, -1, 1}},
};

int removed;

void move() {
  int sand = grid[r + directions[d][0]][c + directions[d][1]];
  grid[r + directions[d][0]][c + directions[d][1]] = 0;

  int removed_sand = 0;

  for (int i = 1; i < 10; i++) {
    int dr = blocks[d][i][0], dc = blocks[d][i][1], w = blocks[d][i][2];

    int next_r = r + dr, next_c = c + dc;
    int s = (sand * w) / 100;

    removed_sand += s;

    if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) {
      removed += s;
    } else {
      grid[next_r][next_c] += s;
    }
  }

  int next_r = r + blocks[d][0][0], next_c = c + blocks[d][0][1];
  if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) {
    removed += (sand - removed_sand);
  } else {
    grid[next_r][next_c] += (sand - removed_sand);
  }

  r += directions[d][0];
  c += directions[d][1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> grid[i][j];
    }
  }

  removed = 0;

  r = N / 2, c = N / 2;
  d = 0;
  for (int len = 1; len < N; len++) {
    for (int i = 0; i < len; i++) {
      move();
    }

    d = (d + 1) % 4;

    for (int i = 0; i < len; i++) {
      move();
    }

    d = (d + 1) % 4;
  }

  for (int i = 0; i < N; i++) {
    move();
  }

  std::cout << removed << '\n';

  return 0;
}
