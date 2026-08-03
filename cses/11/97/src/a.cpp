#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using ll = long long;

const ll INF = std::numeric_limits<ll>::max();

const int MAX_N = 2501;
const int MAX_M = 5001;

int N;
int M;
std::pair<int, std::pair<int, int>> edges[MAX_M];

ll distance[MAX_N];
int previous[MAX_N];

std::vector<int> get_negative_cycle() {
  std::fill(distance, distance + N + 1, INF);
  std::fill(previous, previous + N + 1, -1);

  int start = -1;

  for (int i = 0; i < N; i++) {
    start = -1;

    for (auto &[w, edge] : edges) {
      auto &[u, v] = edge;

      if (distance[u] < INF && distance[u] + w < distance[v]) {
        distance[v] = distance[u] + w;
        previous[v] = u;
        start = v;
      }
    }
  }

  if (start == -1) {
    return std::vector<int>();
  }

  std::vector<int> cycle;
  int current = start;

  while (current != -1) {
    cycle.push_back(current);
    current = previous[current];
  }

  cycle.push_back(start);

  for (int li = 0, ri = cycle.size() - 1; li < ri; li++, ri--) {
    std::swap(cycle[li], cycle[ri]);
  }

  return cycle;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    std::cin >> edges[i].second.first >> edges[i].second.second >>
        edges[i].first;
  }

  std::vector<int> cycle = get_negative_cycle();

  if (cycle.size() == 0) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";

    for (int i : cycle) {
      std::cout << i << " ";
    }
    std::cout << '\n';
  }

  return 0;
}
