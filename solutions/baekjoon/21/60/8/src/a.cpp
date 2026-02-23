#include <iostream>
#include <utility>

const int MAX_N = 25;

int n;
int grid[MAX_N][MAX_N];

int order[MAX_N * MAX_N];
bool likes[MAX_N * MAX_N][MAX_N * MAX_N];

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void fill() {
  for (int i = 0; i < n * n; i++) {
    int current = order[i];

    std::pair<int, int> selected = {0, 0};
    int max_friend_count = -1, max_empty_count = -1;
    int friend_count = 0, empty_count = 0;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] != 0) {
          continue;
        }

        friend_count = 0, empty_count = 0;
        for (int di = 0; di < 4; di++) {
          int next_r = r + directions[di][0], next_c = c + directions[di][1];
          if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) {
            continue;
          }

          if (grid[next_r][next_c] == 0) {
            empty_count++;
          } else if (likes[current][grid[next_r][next_c]]) {
            friend_count++;
          }
        }

        if (max_friend_count < friend_count) {
          selected.first = r, selected.second = c;
          max_friend_count = friend_count;
          max_empty_count = empty_count;
        } else if (max_friend_count == friend_count &&
                   max_empty_count < empty_count) {
          selected.first = r, selected.second = c;
          max_empty_count = empty_count;
        }
      }
    }

    grid[selected.first][selected.second] = current;
  }
}

int satisfactions[5] = {0, 1, 10, 100, 1000};

int get_satisfaction() {
  int satisfaction = 0;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      int friend_count = 0;

      for (int di = 0; di < 4; di++) {
        int next_r = r + directions[di][0], next_c = c + directions[di][1];
        if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) {
          continue;
        }

        if (likes[grid[r][c]][grid[next_r][next_c]]) {
          friend_count++;
        }
      }

      satisfaction += satisfactions[friend_count];
    }
  }

  return satisfaction;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = 0;
      likes[i][j] = false;
    }
  }

  int f;
  for (int i = 0; i < n * n; i++) {
    std::cin >> order[i];

    for (int j = 0; j < 4; j++) {
      std::cin >> f;
      likes[order[i]][f] = true;
    }
  }

  fill();
  std::cout << get_satisfaction() << '\n';

  return 0;
}
