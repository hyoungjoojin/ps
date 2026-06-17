#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
  vector<vector<int>> graph(n + 1);
  for (auto &e : edge) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }

  vector<int> distance(n + 1, -1);
  queue<int> q;

  distance[1] = 0;
  int m = 0;
  q.push(1);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int &adj : graph[v]) {
      if (distance[adj] == -1) {
        distance[adj] = distance[v] + 1;
        m = max(m, distance[adj]);
        q.push(adj);
      }
    }
  }

  int answer = 0;
  for (int &d : distance) {
    if (d == m) {
      answer++;
    }
  }

  return answer;
}
