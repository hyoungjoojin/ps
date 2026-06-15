#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

std::vector<int> groups[2];
int color[MAX_N];

bool split() {
  for (int i = 0; i <= N; i++) {
    color[i] = -1;
  }

  bool possible = true;
  std::queue<int> queue;

  for (int start = 1; start <= N; start++) {
    if (color[start] != -1) {
      continue;
    }

    groups[color[start] = 0].push_back(start);
    queue.push(start);

    while (!queue.empty()) {
      int v = queue.front();
      queue.pop();

      for (int &adj : graph[v]) {
        if (color[adj] == -1) {
          groups[color[adj] = 1 - color[v]].push_back(adj);
          queue.push(adj);
        } else if (color[adj] == color[v]) {
          possible = false;
          break;
        }
      }

      if (!possible) {
        break;
      }
    }

    if (!possible) {
      break;
    }
  }

  return possible;
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
    for (int i = 0; i < 2; i++) {
      std::cout << groups[i].size() << '\n';
      for (int &x : groups[i]) {
        std::cout << x << ' ';
      }
      std::cout << '\n';
    }
  } else {
    std::cout << "-1\n";
  }

  return 0;
}
