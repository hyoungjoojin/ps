#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
  int result = 0;

  vector<bool> visited(n, false);
  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }

    result++;
    visited[i] = true;
    q.push(i);

    while (!q.empty()) {
      int v = q.front();
      q.pop();

      for (int adj = 0; adj < n; adj++) {
        if (computers[v][adj] == 0 || visited[adj]) {
          continue;
        }

        visited[adj] = true;
        q.push(adj);
      }
    }
  }

  return result;
}
