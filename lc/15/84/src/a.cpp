#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    int cost = 0;
    vector<bool> visited(n, false);
    vector<int> min_edge(n, numeric_limits<int>::max());

    min_edge[0] = 0;

    for (int i = 0; i < n; i++) {
      int v = -1;
      for (int j = 0; j < n; j++) {
        if (!visited[j] && (v == -1 || min_edge[j] < min_edge[v])) {
          v = j;
        }
      }

      visited[v] = true;
      cost += min_edge[v];

      for (int adj = 0; adj < n; adj++) {
        min_edge[adj] = min(min_edge[adj], distance(points[v], points[adj]));
      }
    }

    return cost;
  }

private:
  int distance(vector<int> &p1, vector<int> &p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};
