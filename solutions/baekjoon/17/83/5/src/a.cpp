#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 100001;
const long long INF = std::numeric_limits<long long>::max();

int num_nodes;
int num_edges;
int num_marks;
std::vector<std::pair<long long, int>> graph[MAX_N];

long long distance[MAX_N];

std::priority_queue<std::pair<long long, int>,
                    std::vector<std::pair<long long, int>>, std::greater<>>
    pq;

void dijkstra(int start) {
  for (int i = 0; i <= num_nodes; i++) {
    distance[i] = INF;
  }

  pq.push({0, 0});
  distance[0] = 0;

  while (!pq.empty()) {
    long long d_v = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if (distance[v] < d_v) {
      continue;
    }

    for (int ai = 0; ai < graph[v].size(); ai++) {
      int adj = graph[v][ai].first;
      long long w_adj = graph[v][ai].second;

      if (distance[adj] > distance[v] + w_adj) {
        distance[adj] = distance[v] + w_adj;
        pq.push({distance[adj], adj});
      }
    }
  }

  for (int i = 0; i <= num_nodes; i++) {
    if (distance[i] == INF) {
      distance[i] = -1;
    }
  }
}

int compute_distance() {
  dijkstra(0);

  int maximum = 1;
  for (int i = 1; i <= num_nodes; i++) {
    if (distance[maximum] < distance[i]) {
      maximum = i;
    }
  }

  return maximum;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges >> num_marks;

  int u, v;
  long long w;

  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    graph[v].push_back({u, w});
  }

  int mark;
  for (int i = 0; i < num_marks; i++) {
    std::cin >> mark;
    graph[0].push_back({mark, 0});
  }

  int index = compute_distance();
  std::cout << index << '\n' << distance[index] << '\n';

  return 0;
}
