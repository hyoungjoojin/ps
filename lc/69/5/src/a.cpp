#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();

    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    while (!q.empty()) {
      q.pop();
    }

    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j]) {
          continue;
        }

        result = max(result, getArea(grid, i, j));
      }
    }

    return result;
  }

private:
  static constexpr int DIRECTIONS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int m;
  int n;

  vector<vector<bool>> visited;
  queue<pair<int, int>> q;

  int getArea(vector<vector<int>> &grid, int i, int j) {
    if (grid[i][j] == 0) {
      visited[i][j] = true;
      return 0;
    }

    int area = 1;
    visited[i][j] = true;
    q.push({i, j});

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (auto [dr, dc] : DIRECTIONS) {
        int next_r = r + dr, next_c = c + dc;
        if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n ||
            visited[next_r][next_c] || grid[next_r][next_c] == 0) {
          continue;
        }

        area++;
        visited[next_r][next_c] = true;
        q.push({next_r, next_c});
      }
    }

    return area;
  }
};
