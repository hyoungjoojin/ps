#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_NODES = 801;

int num_nodes;
int num_edges;
std::vector<std::pair<int, int>> graph[MAX_NODES];

int from_1[MAX_NODES];
int from_a[MAX_NODES];
int from_b[MAX_NODES];

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<std::pair<int, int>>>
    pq;

void dijkstra(int start, int distance[MAX_NODES]) {
  for (int i = 0; i <= num_nodes; i++) {
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

    for (int i = 0; i < graph[v].size(); i++) {
      int to = graph[v][i].first, len = graph[v][i].second;

      if (distance[v] + len < distance[to]) {
        distance[to] = distance[v] + len;
        pq.push({distance[to], to});
      }
    }
  }

  for (int i = 0; i <= num_nodes; i++) {
    if (distance[i] == std::numeric_limits<int>::max()) {
      distance[i] = -1;
    }
  }
}

int compute_distance(int a, int b) {
  int end = num_nodes;

  dijkstra(1, from_1);
  dijkstra(a, from_a);
  dijkstra(b, from_b);

  int min = std::numeric_limits<int>::max();

  if (from_1[a] != -1 && from_a[b] != -1 && from_b[end] != -1) {
    min = std::min(min, from_1[a] + from_a[b] + from_b[end]);
  }

  if (from_1[b] != -1 && from_b[a] != -1 && from_a[end] != -1) {
    min = std::min(min, from_1[b] + from_b[a] + from_a[end]);
  }

  return min == std::numeric_limits<int>::max() ? -1 : min;
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
    graph[v].push_back({u, w});
  }

  int a, b;
  std::cin >> a >> b;

  std::cout << compute_distance(a, b) << '\n';

  return 0;
}
