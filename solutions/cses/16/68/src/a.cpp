#include <iostream>
#include <queue>
#include <vector>

const int MAX_NODES = 100001;

int num_nodes;
int num_edges;
std::vector<int> graph[MAX_NODES];

int teams[MAX_NODES];

bool match_teams() {
  for (int i = 1; i <= num_nodes; i++) {
    teams[i] = -1;
  }

  std::queue<int> queue;

  for (int i = 1; i <= num_nodes; i++) {
    if (teams[i] != -1) {
      continue;
    }

    teams[i] = 1;
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int ai = 0; ai < graph[front].size(); ai++) {
        int adj = graph[front][ai];

        if (teams[adj] == -1) {
          teams[adj] = 3 - teams[front];
          queue.push(adj);
        } else if (teams[adj] == teams[front]) {
          return false;
        }
      }
    }
  }

  return true;
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

  bool success = match_teams();

  if (success) {
    for (int i = 1; i <= num_nodes; i++) {
      std::cout << teams[i] << ' ';
    }
  } else {
    std::cout << "IMPOSSIBLE\n";
  }

  return 0;
}
