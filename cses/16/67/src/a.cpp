#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

std::queue<int> queue;
int previous[MAX_N];

std::vector<int> find_shortest_path() {
  std::fill(previous, previous + N + 1, -1);

  int start = 1, end = N;

  queue.push(start);
  previous[start] = start;

  while (!queue.empty()) {
    int v = queue.front();
    queue.pop();

    for (int &adj : graph[v]) {
      if (previous[adj] == -1) {
        queue.push(adj);
        previous[adj] = v;
      }
    }
  }

  if (previous[end] == -1) {
    return std::vector<int>();
  }

  std::vector<int> path;

  int current = end;
  while (current != previous[current]) {
    path.push_back(current);
    current = previous[current];
  }
  path.push_back(start);

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

  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::vector<int> path = find_shortest_path();

  if (path.size() == 0) {
    std::cout << "IMPOSSIBLE\n";
  } else {
    std::cout << path.size() << '\n';

    for (int &i : path) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
