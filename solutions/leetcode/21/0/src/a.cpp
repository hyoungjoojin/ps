#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inorder_count(numCourses, 0);

    queue<int> q;
    vector<bool> visited(numCourses, false);
    vector<int> order;

    for (auto &prerequisite : prerequisites) {
      int u = prerequisite[1], v = prerequisite[0];
      graph[u].push_back(v);
      inorder_count[v]++;
    }

    for (int i = 0; i < numCourses; i++) {
      if (inorder_count[i] == 0) {
        q.push(i);
        visited[i] = true;
      }
    }

    if (q.empty()) {
      return vector<int>();
    }

    while (!q.empty()) {
      int front = q.front();
      q.pop();

      order.push_back(front);

      for (int &adj : graph[front]) {
        if (visited[adj]) {
          continue;
        }

        if (--inorder_count[adj] == 0) {
          q.push(adj);
          visited[adj] = true;
        }
      }
    }

    for (int i = 0; i < numCourses; i++) {
      if (!visited[i]) {
        return vector<int>();
      }
    }

    return order;
  }
};
