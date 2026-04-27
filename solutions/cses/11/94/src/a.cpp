#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MAX_N = 1001;
const int MAX_M = 1001;

enum { WALL = 0, EMPTY = 1 };

std::pair<std::pair<int, int>, char> DIRECTIONS[4] = {
    {{0, -1}, 'L'},
    {{0, 1}, 'R'},
    {{-1, 0}, 'U'},
    {{1, 0}, 'D'},
};

int N;
int M;
int graph[MAX_N][MAX_M];

std::pair<int, int> start;
std::vector<std::pair<int, int>> monsters;

int contaminated_at[MAX_N][MAX_M];
int previous[MAX_N][MAX_M];
int reached_time[MAX_N][MAX_M];

bool is_border(int r, int c) {
  return r == 0 || r == N - 1 || c == 0 || c == M - 1;
}

std::pair<bool, std::string> find_path() {
  if (is_border(start.first, start.second)) {
    return {true, ""};
  }

  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      contaminated_at[i][j] = -1;
      previous[i][j] = -1;
      reached_time[i][j] = -1;
    }
  }

  for (auto &[r, c] : monsters) {
    queue.push({r, c});
    contaminated_at[r][c] = 0;
  }

  while (!queue.empty()) {
    auto [r, c] = queue.front();
    queue.pop();

    for (auto &[d, _] : DIRECTIONS) {
      int next_r = r + d.first, next_c = c + d.second;
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M ||
          graph[next_r][next_c] == WALL ||
          contaminated_at[next_r][next_c] != -1) {
        continue;
      }

      queue.push({next_r, next_c});
      contaminated_at[next_r][next_c] = contaminated_at[r][c] + 1;
    }
  }

  bool reached_end = false;
  std::pair<int, int> end;

  previous[start.first][start.second] = 5;
  reached_time[start.first][start.second] = 0;
  queue.push(start);

  while (!queue.empty()) {
    auto [r, c] = queue.front();
    queue.pop();

    if (is_border(r, c)) {
      reached_end = true;
      end = {r, c};
      break;
    }

    for (int di = 0; di < 4; di++) {
      int next_r = r + DIRECTIONS[di].first.first,
          next_c = c + DIRECTIONS[di].first.second;

      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M ||
          graph[next_r][next_c] == WALL || previous[next_r][next_c] != -1 ||
          (contaminated_at[next_r][next_c] != -1 &&
           reached_time[r][c] + 1 >= contaminated_at[next_r][next_c])) {
        continue;
      }

      previous[next_r][next_c] = di;
      reached_time[next_r][next_c] = reached_time[r][c] + 1;
      queue.push({next_r, next_c});
    }
  }

  if (!reached_end) {
    return {false, ""};
  }

  std::string path;

  auto [current_r, current_c] = end;

  while (previous[current_r][current_c] != 5) {
    int di = previous[current_r][current_c];
    path.push_back(DIRECTIONS[di].second);

    current_r -= DIRECTIONS[di].first.first;
    current_c -= DIRECTIONS[di].first.second;
  }

  for (int li = 0, ri = path.size() - 1; li < ri; li++, ri--) {
    std::swap(path[li], path[ri]);
  }

  return {true, path};
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
      if (line[j] == '#') {
        graph[i][j] = WALL;
      } else {
        graph[i][j] = EMPTY;

        if (line[j] == 'A') {
          start = {i, j};
        } else if (line[j] == 'M') {
          monsters.push_back({i, j});
        }
      }
    }
  }

  auto [success, path] = find_path();

  if (success) {
    std::cout << "YES\n";
    std::cout << path.size() << '\n';
    std::cout << path << '\n';
  } else {
    std::cout << "NO\n";
  }

  return 0;
}
