#include <iostream>
#include <queue>
#include <vector>

const int MAX_NODES = 100001;

int num_nodes;
int num_edges;
std::vector<int> graph[MAX_NODES];
bool visited[MAX_NODES];

int num_connected_cities;
int connected_cities[MAX_NODES];

void find_connected_cities() {
  for (int i = 1; i <= num_nodes; i++) {
    visited[i] = false;
  }

  std::queue<int> queue;

  for (int i = 1; i <= num_nodes; i++) {
    if (visited[i]) {
      continue;
    }

    connected_cities[num_connected_cities++] = i;

    queue.push(i);
    visited[i] = true;

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int ai = 0; ai < graph[front].size(); ai++) {
        int adj = graph[front][ai];

        if (!visited[adj]) {
          queue.push(adj);
          visited[adj] = true;
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges;

  int u, v;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  find_connected_cities();

  std::cout << num_connected_cities - 1 << '\n';
  for (int i = 1; i < num_connected_cities; i++) {
    std::cout << connected_cities[i - 1] << ' ' << connected_cities[i] << '\n';
  }

  return 0;
}
