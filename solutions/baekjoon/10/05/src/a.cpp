#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 1001;

int num_nodes;
int num_edges;
int weights[MAX_N];

std::vector<int> graph[MAX_N];
int inbound_count[MAX_N];
int maximum_time[MAX_N];

int get_minimum_time(int node) {
  std::queue<int> queue;

  for (int i = 1; i <= num_nodes; i++) {
    if (inbound_count[i] == 0) {
      maximum_time[i] = weights[i];
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int ai = 0; ai < graph[front].size(); ai++) {
      int adj = graph[front][ai];

      if (inbound_count[adj] > 0) {
        maximum_time[adj] = std::max(maximum_time[adj], maximum_time[front]);
      }

      if (--inbound_count[adj] == 0) {
        maximum_time[adj] += weights[adj];
        queue.push(adj);
      }
    }
  }

  return maximum_time[node];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> num_nodes >> num_edges;

    for (int i = 0; i <= num_nodes; i++) {
      graph[i].clear();
    }

    for (int i = 1; i <= num_nodes; i++) {
      std::cin >> weights[i];
      inbound_count[i] = 0;
      maximum_time[i] = 0;
    }

    int u, v;
    for (int i = 0; i < num_edges; i++) {
      std::cin >> u >> v;
      graph[u].push_back(v);
      inbound_count[v]++;
    }

    int node;
    std::cin >> node;

    std::cout << get_minimum_time(node) << '\n';
  }

  return 0;
}
