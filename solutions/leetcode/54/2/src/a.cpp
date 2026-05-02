#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> distance(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          distance[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &[dr, dc] : DIRECTIONS) {
        int next_r = r + dr, next_c = c + dc;
        if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n ||
            distance[next_r][next_c] != -1) {
          continue;
        }

        distance[next_r][next_c] = distance[r][c] + 1;
        q.push({next_r, next_c});
      }
    }

    return distance;
  }

private:
  static constexpr int DIRECTIONS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
