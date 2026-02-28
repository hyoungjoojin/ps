#include <iostream>
#include <queue>
#include <utility>

const int MAX_N = 128;

int N;
int grid[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void _turn_recursive(int r, int c, int length, int target_length) {
  if (length > target_length) {
    int half_length = length / 2;
    _turn_recursive(r, c, half_length, target_length);
    _turn_recursive(r + half_length, c, half_length, target_length);
    _turn_recursive(r, c + half_length, half_length, target_length);
    _turn_recursive(r + half_length, c + half_length, half_length,
                    target_length);
    return;
  }

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      temp[j][length - i - 1] = grid[r + i][c + j];
    }
  }

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      grid[r + i][c + j] = temp[i][j];
    }
  }
}

void turn(int l) {
  if (l == 0) {
    return;
  }

  int L = 1;
  while (l--) {
    L *= 2;
  }

  _turn_recursive(0, 0, N, L);
}

void melt() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      temp[r][c] = grid[r][c];
    }
  }

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (grid[r][c] == 0) {
        continue;
      }

      int count = 0;
      for (int di = 0; di < 4; di++) {
        int next_r = r + directions[di][0], next_c = c + directions[di][1];
        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) {
          continue;
        }

        if (grid[next_r][next_c] > 0) {
          count++;
        }
      }

      if (count < 3) {
        temp[r][c]--;
      }
    }
  }

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      grid[r][c] = temp[r][c];
    }
  }
}

int get_sum() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sum += grid[i][j];
    }
  }

  return sum;
}

bool visited[MAX_N][MAX_N];
std::queue<std::pair<int, int>> queue;

int get_largest_component_size() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      visited[r][c] = false;
    }
  }

  int max = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] || grid[i][j] == 0) {
        continue;
      }

      int size = 1;
      visited[i][j] = true;
      queue.push({i, j});

      while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();

        for (int di = 0; di < 4; di++) {
          int next_r = r + directions[di][0], next_c = c + directions[di][1];
          if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N ||
              visited[next_r][next_c] || grid[next_r][next_c] == 0) {
            continue;
          }

          size++;
          visited[next_r][next_c] = true;
          queue.push({next_r, next_c});
        }
      }

      if (size > max) {
        max = size;
      }
    }
  }

  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  N = 1;
  while (n--) {
    N *= 2;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> grid[i][j];
    }
  }

  int l;
  for (int i = 0; i < q; i++) {
    std::cin >> l;
    turn(l);
    melt();
  }

  std::cout << get_sum() << '\n';
  std::cout << get_largest_component_size() << '\n';

  return 0;
}
