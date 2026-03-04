#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 100001;

int N;
int M;
std::vector<std::pair<int, int>> graph[MAX_N];
bool visited[MAX_N];

long long total_weight;

long long get_minimum_weight() {
  for (int i = 0; i <= N; i++) {
    visited[i] = false;
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  long long weight = 0;
  int count = 0;

  pq.push({0, 1});

  while (!pq.empty()) {
    int w_v = pq.top().first, v = pq.top().second;
    pq.pop();

    if (visited[v]) {
      continue;
    }

    visited[v] = true;
    weight += w_v;
    count++;

    for (int ai = 0; ai < graph[v].size(); ai++) {
      int adj = graph[v][ai].first, w_adj = graph[v][ai].second;
      if (!visited[adj]) {
        pq.push({w_adj, adj});
      }
    }
  }

  if (count != N) {
    return -1;
  }

  return weight;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  total_weight = 0;

  int u, v, w;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v >> w;

    total_weight += w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  long long minimum_weight = get_minimum_weight();

  if (minimum_weight == -1) {
    std::cout << "-1\n";
  } else {
    std::cout << total_weight - minimum_weight << '\n';
  }

  return 0;
}
