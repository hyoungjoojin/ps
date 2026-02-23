#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_NODES = 1000001;

int num_nodes;
std::vector<int> graph[MAX_NODES];

bool visited[MAX_NODES];
int memo[MAX_NODES][2];

int _get_minimum_adapters_recursive(int node, int take) {
  if (memo[node][take] != -1) {
    return memo[node][take];
  }

  int count = (take ? 1 : 0);
  visited[node] = true;

  for (int ai = 0; ai < graph[node].size(); ai++) {
    int adj = graph[node][ai];
    if (visited[adj]) {
      continue;
    }

    if (take) {
      count += std::min(_get_minimum_adapters_recursive(adj, 0),
                        _get_minimum_adapters_recursive(adj, 1));
    } else {
      count += _get_minimum_adapters_recursive(adj, 1);
    }
  }

  visited[node] = false;
  return memo[node][take] = count;
}

int get_minimum_adapters() {
  for (int i = 0; i <= num_nodes; i++) {
    visited[i] = false;
    memo[i][0] = -1;
    memo[i][1] = -1;
  }

  return std::min(_get_minimum_adapters_recursive(1, 0),
                  _get_minimum_adapters_recursive(1, 1));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes;

  int u, v;
  for (int i = 0; i < num_nodes - 1; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << get_minimum_adapters() << '\n';

  return 0;
}
