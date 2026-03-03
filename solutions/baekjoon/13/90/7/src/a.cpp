#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_NODES = 1005;
const long long INF = std::numeric_limits<long long>::max();

int num_nodes;
int num_edges;
std::vector<std::pair<int, int>> graph[MAX_NODES];

int start;
int end;
long long distance[MAX_NODES][MAX_NODES];
int total_tax;

void dijkstra() {
  std::priority_queue<std::pair<long long, std::pair<int, int>>,
                      std::vector<std::pair<long long, std::pair<int, int>>>,
                      std::greater<>>
      pq;

  for (int i = 0; i <= num_nodes; i++) {
    for (int j = 0; j <= num_nodes; j++) {
      distance[i][j] = INF;
    }
  }

  distance[start][0] = 0;
  pq.push({0, {0, start}});

  while (!pq.empty()) {
    long long d_v = pq.top().first;
    int c_v = pq.top().second.first, v = pq.top().second.second;
    pq.pop();

    if (distance[v][c_v] < d_v) {
      continue;
    }

    for (int ai = 0; ai < graph[v].size(); ai++) {
      int adj = graph[v][ai].first, w_adj = graph[v][ai].second;

      if (distance[adj][c_v + 1] > d_v + w_adj) {
        distance[adj][c_v + 1] = d_v + w_adj;
        pq.push({distance[adj][c_v + 1], {c_v + 1, adj}});
      }
    }
  }
}

void init() {
  total_tax = 0;
  dijkstra();
}

long long compute_minimum_distance() {
  long long d = INF;
  for (int i = 0; i <= num_nodes; i++) {
    if (distance[end][i] == INF) {
      continue;
    }

    d = std::min(d, distance[end][i] + i * total_tax);
  }

  return d;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;
  std::cin >> num_nodes >> num_edges >> k;

  std::cin >> start >> end;

  int u, v, w;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  init();
  std::cout << compute_minimum_distance() << '\n';

  int tax;
  for (int i = 0; i < k; i++) {
    std::cin >> tax;
    total_tax += tax;

    std::cout << compute_minimum_distance() << '\n';
  }

  return 0;
}
