#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;

const ll INF = 1e16 + 1;

const int MAX_N = 501;

int N;
int M;
std::vector<std::pair<int, ll>> graph[MAX_N];

ll distance[MAX_N][MAX_N];

void get_distance() {
  for (int i = 1; i <= N; i++) {
    std::fill(distance[i], distance[i] + N + 1, INF);
    distance[i][i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    for (auto &[adj, w] : graph[i]) {
      distance[i][adj] = std::min(distance[i][adj], w);
      distance[adj][i] = std::min(distance[adj][i], w);
    }
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
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

  int Q;
  std::cin >> N >> M >> Q;

  for (int i = 0; i < M; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    graph[u].push_back({v, w});
  }

  get_distance();

  while (Q--) {
    int u, v;
    std::cin >> u >> v;

    std::cout << (distance[u][v] == INF ? -1 : distance[u][v]) << '\n';
  }

  return 0;
}
