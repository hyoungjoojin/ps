#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

int inorder[MAX_N];

std::vector<int> get_topological_ordering() {
  for (int u = 1; u <= N; u++) {
    for (int v : graph[u]) {
      inorder[v]++;
    }
  }

  std::vector<int> result;
  std::queue<int> queue;

  for (int i = 1; i <= N; i++) {
    if (inorder[i] == 0) {
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    result.push_back(front);

    for (int adj : graph[front]) {
      if (--inorder[adj] == 0) {
        queue.push(adj);
      }
    }
  }

  if (result.size() != N) {
    return {};
  }

  return result;
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
  }

  std::vector<int> result = get_topological_ordering();

  if (result.empty()) {
    std::cout << "IMPOSSIBLE\n";
  } else {
    for (int i : result) {
      std::cout << i << ' ';
    }
    std::cout << "\n";
  }

  return 0;
}
