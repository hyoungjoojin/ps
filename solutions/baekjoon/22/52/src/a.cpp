#include <iostream>
#include <queue>
#include <vector>

const int MAX_NODES = 32001;

int num_nodes;
int num_edges;
std::vector<int> graph[MAX_NODES];
int indegree[MAX_NODES];

int order[MAX_NODES];

void get_order() {
  std::queue<int> queue;
  int current_order = 0;

  for (int i = 1; i <= num_nodes; i++) {
    if (indegree[i] == 0) {
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    order[current_order++] = front;

    for (int ai = 0; ai < graph[front].size(); ai++) {
      int adj = graph[front][ai];

      if (--indegree[adj] == 0) {
        queue.push(adj);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges;

  for (int i = 0; i <= num_nodes; i++) {
    indegree[i] = 0;
  }

  int u, v;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    indegree[v]++;
  }

  get_order();

  for (int i = 0; i < num_nodes; i++) {
    std::cout << order[i] << ' ';
  }

  return 0;
}
