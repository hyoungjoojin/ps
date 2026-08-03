#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

std::queue<int> queue;
int colors[MAX_N];

bool split() {
  std::fill(colors, colors + N + 1, -1);

  for (int i = 1; i <= N; i++) {
    if (colors[i] != -1) {
      continue;
    }

    queue.push(i);
    colors[i] = 1;

    while (!queue.empty()) {
      int v = queue.front();
      queue.pop();

      for (int &adj : graph[v]) {
        if (colors[adj] == -1) {
          queue.push(adj);
          colors[adj] = 3 - colors[v];
        } else if (colors[adj] == colors[v]) {
          return false;
        }
      }
    }
  }

  return true;
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

  if (split()) {
    for (int i = 1; i <= N; i++) {
      std::cout << colors[i] << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "IMPOSSIBLE\n";
  }

  return 0;
}
