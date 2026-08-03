#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MAX_N = 1001;
const int MAX_M = 1001;

enum { FLOOR = 0, WALL = 1 };

enum { LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3 };

constexpr char DIRECTION_LABELS[4] = {'L', 'R', 'U', 'D'};

constexpr int DIRECTIONS[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
};

int N;
int M;
int grid[MAX_N][MAX_M];

std::pair<int, int> start;
std::pair<int, int> end;
int previous[MAX_N][MAX_M];

std::vector<char> find_path() {
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      previous[i][j] = -1;
    }
  }

  previous[start.first][start.second] = -1;
  queue.push(start);

  while (!queue.empty()) {
    int r = queue.front().first, c = queue.front().second;
    queue.pop();

    for (int di = 0; di < 4; di++) {
      int next_r = r + DIRECTIONS[di][0], next_c = c + DIRECTIONS[di][1];
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M ||
          previous[next_r][next_c] != -1 || grid[next_r][next_c] == WALL) {
        continue;
      }

      previous[next_r][next_c] = di;
      queue.push({next_r, next_c});
    }
  }

  if (previous[end.first][end.second] == -1) {
    return std::vector<char>();
  }

  std::vector<char> path;

  int current_r = end.first, current_c = end.second;
  while (current_r != start.first || current_c != start.second) {
    int di = previous[current_r][current_c];
    path.push_back(DIRECTION_LABELS[di]);

    current_r -= DIRECTIONS[di][0];
    current_c -= DIRECTIONS[di][1];
  }

  for (int li = 0, ri = path.size() - 1; li < ri; li++, ri--) {
    std::swap(path[li], path[ri]);
  }

  return path;
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
      if (line[j] == 'A') {
        grid[i][j] = FLOOR;
        start = {i, j};
      } else if (line[j] == 'B') {
        grid[i][j] = FLOOR;
        end = {i, j};
      } else {
        grid[i][j] = (line[j] == '#' ? WALL : FLOOR);
      }
    }
  }

  std::vector<char> path = find_path();

  if (path.empty()) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    std::cout << path.size() << '\n';

    for (char i : path) {
      std::cout << i;
    }

    std::cout << '\n';
  }

  return 0;
}
