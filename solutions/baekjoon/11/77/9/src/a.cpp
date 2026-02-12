#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

const int MAX_NODES = 1001;

int num_nodes;
int num_edges;
std::vector<std::pair<int, int>> graph[MAX_NODES];

int distance[MAX_NODES];

int path_len;
int path[MAX_NODES];

void dijkstra(int start, int end) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  for (int i = 0; i <= num_nodes; i++) {
    distance[i] = std::numeric_limits<int>::max();
  }

  distance[start] = 0;
  pq.push({0, start});
  path[start] = start;

  while (!pq.empty()) {
    int d_v = pq.top().first, v = pq.top().second;
    pq.pop();

    if (distance[v] != d_v) {
      continue;
    }

    for (int i = 0; i < graph[v].size(); i++) {
      int to = graph[v][i].first, len = graph[v][i].second;

      if (distance[v] + len < distance[to]) {
        distance[to] = distance[v] + len;
        pq.push({distance[to], to});
        path[to] = v;
      }
    }
  }

  std::stack<int> stack;

  int current = end;
  while (current != path[current]) {
    stack.push(current);
    current = path[current];
  }
  stack.push(start);

  path_len = stack.size();
  for (int i = 0; i < path_len; i++) {
    path[i] = stack.top();
    stack.pop();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges;

  int u, v, w;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  int start, end;
  std::cin >> start >> end;

  dijkstra(start, end);

  std::cout << distance[end] << '\n';

  std::cout << path_len << '\n';
  for (int i = 0; i < path_len; i++) {
    std::cout << path[i] << ' ';
  }

  return 0;
}
