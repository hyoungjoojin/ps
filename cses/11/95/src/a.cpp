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
std::vector<std::pair<int, int>> graph[MAX_N];

std::priority_queue<std::pair<ll, std::pair<int, int>>,
                    std::vector<std::pair<ll, std::pair<int, int>>>,
                    std::greater<>>
    pq;

ll distance[MAX_N][2];

ll get_shortest_distance() {
  for (int i = 1; i <= N; i++) {
    distance[i][0] = distance[i][1] = INF;
  }

  int start = 1, end = N;

  distance[start][0] = 0;
  pq.push({0, {start, 0}});

  while (!pq.empty()) {
    auto [dv, tv] = pq.top();
    auto [v, used] = tv;
    pq.pop();

    if (distance[v][used] < dv) {
      continue;
    }

    for (auto &[adj, w] : graph[v]) {
      if (distance[v][used] + w < distance[adj][used]) {
        distance[adj][used] = distance[v][used] + w;
        pq.push({distance[adj][used], {adj, used}});
      }

      int hw = w / 2;
      if (used == 0 && distance[v][0] + hw < distance[adj][1]) {
        distance[adj][1] = distance[v][0] + hw;
        pq.push({distance[adj][1], {adj, 1}});
      }
    }
  }

  return std::min(distance[end][0], distance[end][1]);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    graph[u].push_back({v, w});
  }

  std::cout << get_shortest_distance() << '\n';

  return 0;
}
