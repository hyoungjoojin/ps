#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 501;
const int INF = std::numeric_limits<int>::max();

int num_nodes;
int num_edges;
int graph[MAX_N][MAX_N];
std::vector<int> reverse_graph[MAX_N];

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<>>
    pq;

int distance[MAX_N];

void dijkstra(int start) {
  for (int i = 0; i < num_nodes; i++) {
    distance[i] = INF;
    reverse_graph[i].clear();
  }

  distance[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int d_v = pq.top().first, v = pq.top().second;
    pq.pop();

    if (d_v > distance[v]) {
      continue;
    }

    for (int ai = 0; ai < num_nodes; ai++) {
      if (graph[v][ai] == 0) {
        continue;
      }

      int new_distance = distance[v] + graph[v][ai];

      if (distance[ai] > new_distance) {
        distance[ai] = new_distance;
        pq.push({new_distance, ai});
        reverse_graph[ai].clear();
        reverse_graph[ai].push_back(v);
      } else if (distance[ai] == new_distance) {
        reverse_graph[ai].push_back(v);
      }
    }
  }
}

std::queue<int> queue;
int visited[MAX_N];

void remove_edges(int node) {
  for (int i = 0; i < num_nodes; i++) {
    visited[i] = false;
  }

  queue.push(node);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (visited[front]) {
      continue;
    }

    visited[front] = true;

    for (int ai = 0; ai < reverse_graph[front].size(); ai++) {
      int adj = reverse_graph[front][ai];
      queue.push(adj);
      graph[adj][front] = 0;
    }
  }
}

int get_almost_shortest_distance(int start, int end) {
  dijkstra(start);
  int shortest = distance[end];
  if (shortest == INF) {
    return -1;
  }

  remove_edges(end);

  dijkstra(start);
  shortest = distance[end];
  if (shortest == INF) {
    return -1;
  }

  return shortest;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  while (true) {
    std::cin >> num_nodes >> num_edges;
    if (num_nodes == 0 && num_edges == 0) {
      break;
    }

    for (int i = 0; i < num_nodes; i++) {
      for (int j = 0; j < num_nodes; j++) {
        graph[i][j] = 0;
      }
    }

    int start, end;
    std::cin >> start >> end;

    int u, v, w;
    for (int i = 0; i < num_edges; i++) {
      std::cin >> u >> v >> w;
      graph[u][v] = w;
    }

    std::cout << get_almost_shortest_distance(start, end) << '\n';
  }

  return 0;
}
