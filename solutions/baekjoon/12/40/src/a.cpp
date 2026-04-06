#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 1001;

int N;
std::vector<std::pair<int, int>> tree[MAX_N];

int memo[MAX_N][MAX_N];

void init() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      memo[i][j] = -1;
    }
  }
}

std::queue<std::pair<int, int>> queue;
int distance[MAX_N];

int get_distance(int u, int v) {
  if (memo[u][v] != -1) {
    return memo[u][v];
  }

  for (int i = 1; i <= N; i++) {
    distance[i] = -1;
  }

  distance[u] = 0;
  queue.push({u, 0});

  while (!queue.empty()) {
    int v = queue.front().first, d_v = queue.front().second;
    queue.pop();

    for (int ai = 0; ai < tree[v].size(); ai++) {
      int adj = tree[v][ai].first, w_adj = tree[v][ai].second;

      if (distance[adj] == -1) {
        distance[adj] = d_v + w_adj;
        queue.push({adj, distance[adj]});
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    memo[u][i] = distance[i];
    memo[i][u] = distance[i];
  }

  return memo[u][v];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int Q = 0;
  std::cin >> N >> Q;

  init();

  int u, v, w;
  for (int i = 0; i < N - 1; i++) {
    std::cin >> u >> v >> w;
    tree[u].push_back({v, w});
    tree[v].push_back({u, w});
  }

  for (int i = 0; i < Q; i++) {
    std::cin >> u >> v;
    std::cout << get_distance(u, v) << '\n';
  }

  return 0;
}
