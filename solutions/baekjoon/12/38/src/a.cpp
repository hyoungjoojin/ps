#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_NODES = 1001;

int num_nodes;
int num_edges;
std::vector<std::pair<int, int>> graph[MAX_NODES];
std::vector<std::pair<int, int>> reverse_graph[MAX_NODES];

int distance[MAX_NODES];
int total_distance[MAX_NODES];

void compute_distance(int start) {
  for (int i = 1; i <= num_nodes; i++) {
    distance[i] = std::numeric_limits<int>::max();
    total_distance[i] = 0;
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
    total_distance[i] += distance[i];
    distance[i] = std::numeric_limits<int>::max();
  }

  distance[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int d_v = pq.top().first, v = pq.top().second;
    pq.pop();

    if (distance[v] != d_v) {
      continue;
    }

    for (int i = 0; i < reverse_graph[v].size(); i++) {
      int to = reverse_graph[v][i].first, len = reverse_graph[v][i].second;

      if (distance[v] + len < distance[to]) {
        distance[to] = distance[v] + len;
        pq.push({distance[to], to});
      }
    }
  }

  for (int i = 1; i <= num_nodes; i++) {
    total_distance[i] += distance[i];
    distance[i] = std::numeric_limits<int>::max();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int start;
  std::cin >> num_nodes >> num_edges >> start;

  int u, v, w;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    reverse_graph[v].push_back({u, w});
  }

  compute_distance(start);

  int result = 0;
  for (int i = 1; i <= num_nodes; i++) {
    result = std::max(result, total_distance[i]);
  }

  std::cout << result << '\n';

  return 0;
}
