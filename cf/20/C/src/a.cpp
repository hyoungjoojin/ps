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

ll distance[MAX_N];
int previous[MAX_N];

void dijkstra(int start) {
  for (int i = 1; i <= N; i++) {
    distance[i] = INF;
    previous[i] = -1;
  }

  std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>,
                      std::greater<>>
      pq;

  distance[start] = 0;
  previous[start] = start;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [dv, v] = pq.top();
    pq.pop();

    if (distance[v] < dv) {
      continue;
    }

    for (auto &[adj, w] : graph[v]) {
      if (dv + w < distance[adj]) {
        distance[adj] = dv + w;
        previous[adj] = v;
        pq.push({distance[adj], adj});
      }
    }
  }
}

std::vector<int> get_shortest_path(int u, int v) {
  dijkstra(u);

  if (previous[v] == -1) {
    return {};
  }

  std::vector<int> result;

  int current = v;
  while (current != previous[current]) {
    result.push_back(current);
    current = previous[current];
  }
  result.push_back(current);

  for (int li = 0, ri = result.size() - 1; li < ri; li++, ri--) {
    std::swap(result[li], result[ri]);
  }

  return result;
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
    graph[v].push_back({u, w});
  }

  std::vector<int> result = get_shortest_path(1, N);

  if (result.empty()) {
    std::cout << -1 << '\n';
  } else {
    for (int &i : result) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
