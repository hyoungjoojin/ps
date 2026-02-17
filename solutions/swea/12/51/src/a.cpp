#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_NODES = 1001;

int num_nodes;
std::pair<long long, long long> nodes[MAX_NODES];

long long compute_distance(int u, int v) {
  long long dx = nodes[u].first - nodes[v].first,
            dy = nodes[u].second - nodes[v].second;
  return dx * dx + dy * dy;
}

std::priority_queue<std::pair<long long, int>,
                    std::vector<std::pair<long long, int>>, std::greater<>>
    pq;

bool visited[MAX_NODES];

long long compute_price() {
  for (int i = 0; i < num_nodes; i++) {
    visited[i] = false;
  }

  long long result = 0L;
  pq.push({0, 0});

  while (!pq.empty()) {
    long long w_v = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if (visited[v]) {
      continue;
    }

    result += w_v;
    visited[v] = true;

    for (int adj = 0; adj < num_nodes; adj++) {
      if (!visited[adj]) {
        pq.push({compute_distance(v, adj), adj});
      }
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
