#include <algorithm>
#include <iostream>
#include <limits>

const int MAX_DISTANCE = 4000001;
const int MAX_NODES = 401;

int num_nodes;
int num_edges;
int distance[MAX_NODES][MAX_NODES];

void compute_distance() {
  for (int k = 1; k <= num_nodes; k++) {
    for (int i = 1; i <= num_nodes; i++) {
      for (int j = 1; j <= num_nodes; j++) {
        distance[i][j] =
            std::min(distance[i][j], distance[i][k] + distance[k][j]);
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
    for (int j = 0; j <= num_nodes; j++) {
      distance[i][j] = MAX_DISTANCE;
    }
  }

  int u, v, w;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    distance[u][v] = w;
  }

  compute_distance();

  int result = std::numeric_limits<int>::max();
  for (int i = 1; i <= num_nodes; i++) {
    result = std::min(result, distance[i][i]);
  }

  std::cout << (result == MAX_DISTANCE ? -1 : result) << '\n';

  return 0;
}
