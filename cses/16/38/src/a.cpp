#include <iostream>
#include <string>

const int MOD = 1e9 + 7;

const int MAX_N = 1001;

constexpr int DIRECTIONS[2][2] = {{0, 1}, {1, 0}};

enum { EMPTY = 0, WALL = 1 };

int N;
int grid[MAX_N][MAX_N];

int memo[MAX_N][MAX_N];

int get_number_of_paths() {
  if (grid[0][0] == WALL) {
    return 0;
  }

  memo[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (auto &[di, dj] : DIRECTIONS) {
        int next_i = i + di, next_j = j + dj;
        if (next_i >= N || next_j >= N || grid[next_i][next_j] == WALL) {
          continue;
        }

        memo[next_i][next_j] = (memo[i][j] + memo[next_i][next_j]) % MOD;
      }
    }
  }

  return memo[N - 1][N - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::string line;
    std::cin >> line;

    for (int j = 0; j < N; j++) {
      grid[i][j] = (line[j] == '.' ? EMPTY : WALL);
    }
  }

  std::cout << get_number_of_paths() << '\n';

  return 0;
}
