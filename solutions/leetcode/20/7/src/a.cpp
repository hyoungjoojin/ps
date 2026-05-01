#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> color(numCourses, 0);

    for (auto &prerequisite : prerequisites) {
      int u = prerequisite[1], v = prerequisite[0];
      graph[u].push_back(v);
    }

    for (int i = 0; i < numCourses; i++) {
      if (color[i] == 0) {
        if (!_canFinish(graph, color, i)) {
          return false;
        }
      }
    }

    return true;
  }

private:
  bool _canFinish(vector<vector<int>> &graph, vector<int> &color, int node) {
    color[node] = 1;

    for (int &adj : graph[node]) {
      if (color[adj] == 0) {
        if (!_canFinish(graph, color, adj)) {
          return false;
        }
      } else if (color[adj] == 1) {
        return false;
      }
    }

    color[node] = 2;
    return true;
  }
};
