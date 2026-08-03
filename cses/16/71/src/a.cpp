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

std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>,
                    std::greater<>>
    pq;
ll distance[MAX_N];

void get_distance() {
  std::fill(distance, distance + N + 1, INF);

  int start = 1;
  distance[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [dv, v] = pq.top();
    pq.pop();

    if (distance[v] < dv) {
      continue;
    }

    for (auto &[adj, w] : graph[v]) {
      if (distance[v] + w < distance[adj]) {
        distance[adj] = distance[v] + w;
        pq.push({distance[adj], adj});
      }
    }
  }
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

  get_distance();

  for (int i = 1; i <= N; i++) {
    std::cout << distance[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
