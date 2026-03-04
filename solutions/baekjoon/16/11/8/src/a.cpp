#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 4001;
const long long INF = std::numeric_limits<long long>::max();

int N;
int M;
std::vector<std::pair<int, int>> graph[MAX_N];

long long distanceA[MAX_N];
long long distanceB[MAX_N][2];

void compute_distanceA() {
  for (int i = 0; i <= N; i++) {
    distanceA[i] = INF;
  }

  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>, std::greater<>>
      pq;

  distanceA[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    long long d_v = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if (distanceA[v] < d_v) {
      continue;
    }

    for (int ai = 0; ai < graph[v].size(); ai++) {
      int adj = graph[v][ai].first, w_adj = graph[v][ai].second;

      int next_distance = d_v + w_adj * 2;
      if (distanceA[adj] > next_distance) {
        distanceA[adj] = next_distance;
        pq.push({distanceA[adj], adj});
      }
    }
  }
}

void compute_distanceB() {
  for (int i = 0; i <= N; i++) {
    distanceB[i][0] = INF;
    distanceB[i][1] = INF;
  }

  std::priority_queue<std::pair<long long, std::pair<int, int>>,
                      std::vector<std::pair<long long, std::pair<int, int>>>,
                      std::greater<>>
      pq;

  distanceB[1][1] = 0;
  pq.push({0, {1, 1}});

  while (!pq.empty()) {
    long long d_v = pq.top().first;
    int boost = pq.top().second.first, v = pq.top().second.second;
    pq.pop();

    if (distanceB[v][boost] < d_v) {
      continue;
    }

    for (int ai = 0; ai < graph[v].size(); ai++) {
      int adj = graph[v][ai].first, w_adj = graph[v][ai].second;

      int next_distance = d_v + (boost == 1 ? w_adj : w_adj * 4);
      int b = (boost == 1 ? 0 : 1);

      if (distanceB[adj][b] > next_distance) {
        distanceB[adj][b] = next_distance;
        pq.push({next_distance, {b, adj}});
      }
    }
  }
}

int get_count() {
  int count = 0;

  for (int i = 1; i <= N; i++) {
    long long b = std::min(distanceB[i][0], distanceB[i][1]);

    if (distanceA[i] < b) {
      count++;
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  int u, v, w;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  compute_distanceA();
  compute_distanceB();

  std::cout << get_count() << '\n';

  return 0;
}
