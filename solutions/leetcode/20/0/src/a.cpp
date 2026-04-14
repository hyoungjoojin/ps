#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int num_rows = grid.size(), num_cols = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < num_rows; i++) {
      for (int j = 0; j < num_cols; j++) {
        if (grid[i][j] != '1') {
          continue;
        }

        count++;
        grid[i][j] = 0;
        q.push({i, j});

        while (!q.empty()) {
          int r = q.front().first, c = q.front().second;
          q.pop();

          for (int di = 0; di < 4; di++) {
            int next_r = r + DIRECTIONS[di][0], next_c = c + DIRECTIONS[di][1];

            if (next_r < 0 || next_r >= num_rows || next_c < 0 ||
                next_c >= num_cols || grid[next_r][next_c] != '1') {
              continue;
            }

            grid[next_r][next_c] = 0;
            q.push({next_r, next_c});
          }
        }
      }
    }

    return count;
  }

private:
  static constexpr int DIRECTIONS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
