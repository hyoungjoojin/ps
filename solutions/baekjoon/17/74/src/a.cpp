#include <cmath>
#include <iostream>
#include <limits>
#include <utility>

const int MAX_NODES = 1001;

int num_nodes;
std::pair<int, int> nodes[MAX_NODES];
double distance[MAX_NODES][MAX_NODES];

double compute_distance(int i, int j) {
  double dx = nodes[i].first - nodes[j].first,
         dy = nodes[i].second - nodes[j].second;
  return std::sqrt(dx * dx + dy * dy);
}

void compute_distance() {
  for (int i = 1; i <= num_nodes; i++) {
    for (int j = i + 1; j <= num_nodes; j++) {
      double d = compute_distance(i, j);
      distance[i][j] = d;
      distance[j][i] = d;
    }
  }
}

bool visited[MAX_NODES];
double min_edge[MAX_NODES];

double get_minimum_path() {
  for (int i = 0; i <= num_nodes; i++) {
    visited[i] = false;
    min_edge[i] = std::numeric_limits<double>::max();
  }

  double result = 0;
  min_edge[1] = 0;

  for (int i = 0; i < num_nodes; i++) {
    int v = -1;
    for (int j = 1; j <= num_nodes; j++) {
      if (!visited[j] && (v == -1 || min_edge[j] < min_edge[v])) {
        v = j;
      }
    }

    if (v == -1) {
      continue;
    }

    visited[v] = true;
    result += min_edge[v];

    for (int j = 1; j <= num_nodes; j++) {
      if (distance[v][j] < min_edge[j]) {
        min_edge[j] = distance[v][j];
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes;

  int num_edges;
  std::cin >> num_edges;

  for (int i = 1; i <= num_nodes; i++) {
    std::cin >> nodes[i].first >> nodes[i].second;
  }

  compute_distance();

  int u, v;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v;
    distance[u][v] = 0;
    distance[v][u] = 0;
  }

  std::cout.precision(2);
  std::cout << std::fixed;
  std::cout << get_minimum_path() << '\n';

  return 0;
}
