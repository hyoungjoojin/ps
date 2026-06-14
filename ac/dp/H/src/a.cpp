#include <iostream>
#include <string>

const int MOD = 1e9 + 7;
const int MAX_H = 1001;
const int MAX_W = 1001;

enum { EMPTY = 0, WALL = 1 };

constexpr int DIRECTIONS[2][2] = {{1, 0}, {0, 1}};

int H;
int W;
int grid[MAX_H][MAX_W];

int memo[MAX_H][MAX_W];

int get_number_of_paths() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      memo[i][j] = 0;
    }
  }

  memo[0][0] = 1;

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (grid[r][c] == WALL) {
        continue;
      }

      for (auto &[dr, dc] : DIRECTIONS) {
        int next_r = r + dr, next_c = c + dc;
        if (next_r >= H || next_c >= W || grid[next_r][next_c] == WALL) {
          continue;
        }

        memo[next_r][next_c] = (memo[r][c] + memo[next_r][next_c]) % MOD;
      }
    }
  }

  return memo[H - 1][W - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> H >> W;

  for (int i = 0; i < H; i++) {
    std::string line;
    std::cin >> line;

    for (int j = 0; j < W; j++) {
      grid[i][j] = (line[j] == '.' ? EMPTY : WALL);
    }
  }

  std::cout << get_number_of_paths() << '\n';

  return 0;
}
