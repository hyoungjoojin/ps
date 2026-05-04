#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const long long INF = std::numeric_limits<long long>::max();

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<std::pair<int, int>> graph[MAX_N];

long long distance[MAX_N];
int previous[MAX_N];

std::vector<int> find_shortest_path() {
  for (int i = 1; i <= N; i++) {
    distance[i] = INF;
    previous[i] = -1;
  }

  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>, std::greater<>>
      pq;

  distance[1] = 0;
  pq.push({0, 1});
  previous[1] = 1;

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (distance[v] < d_v) {
      continue;
    }

    for (auto &[adj, w_adj] : graph[v]) {
      long long d_adj = d_v + w_adj;
      if (d_adj < distance[adj]) {
        distance[adj] = d_adj;
        pq.push({d_adj, adj});
        previous[adj] = v;
      }
    }
  }

  std::vector<int> path;

  int current = N;
  while (current != previous[current]) {
    path.push_back(current);
    current = previous[current];

    if (current == -1) {
      return std::vector<int>();
    }
  }

  path.push_back(1);

  for (int li = 0, ri = path.size() - 1; li < ri; li++, ri--) {
    std::swap(path[li], path[ri]);
  }

  return path;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  int a, b, w;
  for (int i = 0; i < M; i++) {
    std::cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }

  std::vector<int> path = find_shortest_path();

  if (path.empty()) {
    std::cout << "-1\n";
  } else {
    for (int &i : path) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
