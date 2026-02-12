#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_NODES = 20001;

int num_nodes;
int num_edges;
std::vector<std::pair<int, int>> graph[MAX_NODES + 1];

int start;
int distance[MAX_NODES];

void dijkstra(int start) {
  for (int i = 1; i <= num_nodes; i++) {
    distance[i] = std::numeric_limits<int>::max();
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  distance[start] = 0;
  pq.push({0, start});

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
      }
    }
  }

  for (int i = 1; i <= num_nodes; i++) {
    if (distance[i] == std::numeric_limits<int>::max()) {
      distance[i] = -1;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges >> start;

  int u, v, w;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  dijkstra(start);

  for (int i = 1; i <= num_nodes; i++) {
    if (distance[i] == -1) {
      std::cout << "INF\n";
    } else {
      std::cout << distance[i] << '\n';
    }
  }

  return 0;
}
