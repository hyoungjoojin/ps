#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_NODES = 10001;

int num_nodes;
int weights[MAX_NODES] = {0};
std::vector<int> graph[MAX_NODES];

bool visited[MAX_NODES];
int memo[MAX_NODES][2];

struct Result {
  int sum;
  std::vector<int> nodes;
};

int _get_maximum_sum_recursive(int node, int take) {
  if (memo[node][take] != -1) {
    return memo[node][take];
  }

  int sum = 0;
  visited[node] = true;

  for (int i = 0; i < graph[node].size(); i++) {
    int adj = graph[node][i];
    if (visited[adj]) {
      continue;
    }

    if (take) {
      sum += _get_maximum_sum_recursive(adj, 0);
    } else {
      sum += std::max(_get_maximum_sum_recursive(adj, 0),
                      _get_maximum_sum_recursive(adj, 1));
    }
  }

  if (take) {
    sum += weights[node];
  }

  visited[node] = false;
  return memo[node][take] = sum;
}

int get_sum() {
  for (int i = 1; i <= num_nodes; i++) {
    memo[i][0] = -1;
    memo[i][1] = -1;
    visited[i] = false;
  }

  int max = std::max(_get_maximum_sum_recursive(1, 0),
                     _get_maximum_sum_recursive(1, 1));
  return max;
}

void _get_nodes_recursive(std::vector<int> &nodes, int node, int take) {
  visited[node] = true;

  if (take) {
    nodes.push_back(node);
  }

  for (int i = 0; i < graph[node].size(); i++) {
    int adj = graph[node][i];
    if (visited[adj]) {
      continue;
    }

    if (take) {
      _get_nodes_recursive(nodes, adj, 0);
    } else {
      bool take_node = memo[adj][1] > memo[adj][0];
      _get_nodes_recursive(nodes, adj, take_node);
    }
  }
}

void get_nodes(std::vector<int> &nodes) {
  for (int i = 1; i <= num_nodes; i++) {
    visited[i] = false;
  }

  bool take_node = memo[1][1] > memo[1][0];
  _get_nodes_recursive(nodes, 1, take_node);
}

Result get_result() {
  int sum = get_sum();

  std::vector<int> nodes;
  get_nodes(nodes);

  std::sort(nodes.begin(), nodes.end());
  return {sum, nodes};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes;

  for (int i = 1; i <= num_nodes; i++) {
    std::cin >> weights[i];
  }

  int u, v;
  for (int i = 0; i < num_nodes - 1; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  Result result = get_result();

  std::cout << result.sum << '\n';
  for (int i = 0; i < result.nodes.size(); i++) {
    std::cout << result.nodes[i] << ' ';
  }

  return 0;
}
