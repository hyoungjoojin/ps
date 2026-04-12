#include <cstdlib>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    const int INF = numeric_limits<int>::max();
    constexpr int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int num_rows = heights.size(), num_cols = heights[0].size();
    vector<vector<int>> distance(num_rows, vector<int>(num_cols, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<>>
        pq;

    distance[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
      int d_v = pq.top().first;
      int v_r = pq.top().second.first, v_c = pq.top().second.second;
      pq.pop();

      if (d_v > distance[v_r][v_c]) {
        continue;
      }

      for (int di = 0; di < 4; di++) {
        int next_r = v_r + directions[di][0], next_c = v_c + directions[di][1];
        if (next_r < 0 || next_r >= num_rows || next_c < 0 ||
            next_c >= num_cols) {
          continue;
        }

        int w_adj = max(abs(heights[next_r][next_c] - heights[v_r][v_c]), d_v);

        if (distance[next_r][next_c] > w_adj) {
          distance[next_r][next_c] = w_adj;
          pq.push({w_adj, {next_r, next_c}});
        }
      }
    }

    return distance[num_rows - 1][num_cols - 1];
  }
};
