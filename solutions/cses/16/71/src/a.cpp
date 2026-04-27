#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 1e5 + 1;

const long long INF = std::numeric_limits<long long>::max();

int N;
int M;
std::vector<std::pair<int, int>> graph[MAX_N];

std::vector<long long> get_distance() {
  std::vector<long long> distance(N + 1);
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>, std::greater<>>
      pq;

  for (int i = 0; i <= N; i++) {
    distance[i] = INF;
  }

  distance[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (d_v > distance[v]) {
      continue;
    }

    for (auto &[adj, w_adj] : graph[v]) {
      long long new_distance = d_v + w_adj;
      if (distance[adj] > new_distance) {
        distance[adj] = new_distance;
        pq.push({new_distance, adj});
      }
    }
  }

  return distance;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  int a, b, c;
  for (int i = 0; i < M; i++) {
    std::cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }

  std::vector<long long> distance = get_distance();

  for (int i = 1; i <= N; i++) {
    std::cout << distance[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
