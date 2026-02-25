#include <algorithm>
#include <iostream>

const long long MAX_DISTANCE = 10000001;
const int MAX_NODES = 101;

int num_nodes;
int num_edges;
long long distance[MAX_NODES][MAX_NODES];

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

  int u, v;
  long long w;

  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v >> w;
    distance[u][v] = std::min(distance[u][v], w);
  }

  for (int i = 0; i <= num_nodes; i++) {
    distance[i][i] = 0;
  }

  compute_distance();

  for (int i = 1; i <= num_nodes; i++) {
    for (int j = 1; j <= num_nodes; j++) {
      std::cout << (distance[i][j] == MAX_DISTANCE ? 0 : distance[i][j]) << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  return 0;
}
