#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    pair<int, int> start;
    bool found = false;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          start = {i, j};
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }

    int perimeter = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &[dr, dc] : DIRECTIONS) {
        int next_r = r + dr, next_c = c + dc;
        if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n ||
            grid[next_r][next_c] == 0) {
          perimeter++;
          continue;
        }

        if (visited[next_r][next_c]) {
          continue;
        }

        q.push({next_r, next_c});
        visited[next_r][next_c] = true;
      }
    }

    return perimeter;
  }

private:
  static constexpr int DIRECTIONS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
