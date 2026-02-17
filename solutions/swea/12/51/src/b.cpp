#include <cmath>
#include <iostream>
#include <limits>
#include <utility>

const int MAX_NODES = 1001;

int num_nodes;
std::pair<long long, long long> nodes[MAX_NODES];

long long compute_distance(int u, int v) {
  long long dx = nodes[u].first - nodes[v].first,
            dy = nodes[u].second - nodes[v].second;
  return dx * dx + dy * dy;
}

bool visited[MAX_NODES];
long long min_edge[MAX_NODES];

long long compute_price() {
  long long result = 0L;

  for (int i = 0; i < num_nodes; i++) {
    visited[i] = false;
    min_edge[i] = std::numeric_limits<long long>::max();
  }

  min_edge[0] = 0;

  for (int i = 0; i < num_nodes; i++) {
    int v = -1;
    for (int j = 0; j < num_nodes; j++) {
      if (!visited[j] && (v == -1 || min_edge[j] < min_edge[v])) {
        v = j;
      }
    }

    visited[v] = true;
    result += min_edge[v];

    for (int adj = 0; adj < num_nodes; adj++) {
      min_edge[adj] = std::min(min_edge[adj], compute_distance(v, adj));
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> num_nodes;

    for (int i = 0; i < num_nodes; i++) {
      std::cin >> nodes[i].first;
    }

    for (int i = 0; i < num_nodes; i++) {
      std::cin >> nodes[i].second;
    }

    double ratio;
    std::cin >> ratio;

    std::cout << '#' << t << ' ' << std::llround(compute_price() * ratio)
              << '\n';
  }

  return 0;
}
