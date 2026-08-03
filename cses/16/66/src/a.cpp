#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

std::queue<int> queue;
bool visited[MAX_N];

std::vector<int> get_components() {
  std::vector<int> components;

  std::fill(visited, visited + N + 1, false);

  for (int i = 1; i <= N; i++) {
    if (visited[i]) {
      continue;
    }

    components.push_back(i);

    queue.push(i);
    visited[i] = true;

    while (!queue.empty()) {
      int v = queue.front();
      queue.pop();

      for (int adj : graph[v]) {
        if (!visited[adj]) {
          queue.push(adj);
          visited[adj] = true;
        }
      }
    }
  }

  return components;
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

  std::vector<int> components = get_components();

  std::cout << components.size() - 1 << '\n';

  for (int i = 1; i < components.size(); i++) {
    std::cout << components[i - 1] << ' ' << components[i] << '\n';
  }

  return 0;
}
