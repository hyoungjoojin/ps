#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 2e5 + 1;

int N;
std::vector<int> graph[MAX_N];

std::queue<int> queue;
int distance[MAX_N];

int get_tree_diameter() {
  std::fill(distance, distance + N + 1, -1);

  int start = 1;
  queue.push(start);
  distance[start] = 0;

  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();

    for (int adj : graph[u]) {
      if (distance[adj] == -1) {
        queue.push(adj);
        distance[adj] = distance[u] + 1;
      }
    }
  }

  int farthest = 1;
  for (int i = 1; i <= N; i++) {
    if (distance[farthest] < distance[i]) {
      farthest = i;
    }
  }

  std::fill(distance, distance + N + 1, -1);

  start = farthest;
  queue.push(start);
  distance[start] = 0;

  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();

    for (int adj : graph[u]) {
      if (distance[adj] == -1) {
        queue.push(adj);
        distance[adj] = distance[u] + 1;
      }
    }
  }

  int result = 0;
  for (int i = 1; i <= N; i++) {
    result = std::max(result, distance[i]);
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::cout << get_tree_diameter() << '\n';

  return 0;
}
