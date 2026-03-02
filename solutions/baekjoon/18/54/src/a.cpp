#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 1001;

int num_nodes;
int num_edges;
int k;
std::vector<std::pair<int, int>> graph[MAX_N];
std::priority_queue<int> distances[MAX_N];

int distance[MAX_N];

void compute_kth_distance() {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  pq.push({0, 1});
  distances[1].push(0);

  while (!pq.empty()) {
    int d_v = pq.top().first, v = pq.top().second;
    pq.pop();

    for (int ai = 0; ai < graph[v].size(); ai++) {
      int adj = graph[v][ai].first, adj_w = graph[v][ai].second;

      int d_adj = d_v + adj_w;

      if (distances[adj].size() < k) {
        distances[adj].push(d_adj);
        pq.push({d_adj, adj});
      } else if (distances[adj].top() > d_adj) {
        distances[adj].pop();
        distances[adj].push(d_adj);
        pq.push({d_adj, adj});
      }
    }
  }

  for (int i = 1; i <= num_nodes; i++) {
    if (distances[i].size() != k) {
      distance[i] = -1;
    } else {
      distance[i] = distances[i].top();
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges >> k;

  int u, v, w;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  compute_kth_distance();

  for (int i = 1; i <= num_nodes; i++) {
    std::cout << distance[i] << '\n';
  }

  return 0;
}
