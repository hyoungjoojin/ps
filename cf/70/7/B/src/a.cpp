#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using ll = long long;

const ll INF = std::numeric_limits<ll>::max();

const int MAX_N = 1e5 + 1;

int N;
int M;
int K;

std::vector<std::pair<int, int>> graph[MAX_N];
ll distance[MAX_N];
bool storage[MAX_N];

ll get_minimum_price() {
  for (int i = 1; i <= N; i++) {
    distance[i] = INF;
  }

  std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>,
                      std::greater<>>
      pq;

  distance[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [dv, v] = pq.top();
    pq.pop();

    if (distance[v] < dv) {
      continue;
    }

    for (auto &[adj, w] : graph[v]) {
      if (dv + w < distance[adj]) {
        distance[adj] = dv + w;
        pq.push({distance[adj], adj});
      }
    }
  }

  ll result = INF;
  for (int i = 1; i <= N; i++) {
    if (!storage[i]) {
      result = std::min(result, distance[i]);
    }
  }

  return result == INF ? -1 : result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M >> K;

  for (int i = 0; i < M; i++) {
    int u, v, l;
    std::cin >> u >> v >> l;
    graph[u].push_back({v, l});
    graph[v].push_back({u, l});
  }

  for (int i = 0; i < K; i++) {
    int u;
    std::cin >> u;
    storage[u] = true;
    graph[0].push_back({u, 0});
  }

  std::cout << get_minimum_price() << '\n';

  return 0;
}
