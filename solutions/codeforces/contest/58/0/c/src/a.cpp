#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 2e5 + 1;

int N;
int K;
int nodes[MAX_N];
std::vector<int> tree[MAX_N];

bool visited[MAX_N];

int dfs(int node, int max_consecutive, int current_length) {
  visited[node] = true;

  int count = 0;
  int num_children = 0;

  current_length = nodes[node] ? current_length + 1 : 0;
  max_consecutive = std::max(max_consecutive, current_length);

  for (int adj : tree[node]) {
    if (visited[adj]) {
      continue;
    }

    count += dfs(adj, max_consecutive, current_length);
    num_children++;
  }

  if (num_children == 0) {
    return (max_consecutive <= K ? 1 : 0);
  } else {
    return count;
  }
}

int get_available_leaves() {
  for (int i = 1; i <= N; i++) {
    visited[i] = false;
  }

  return dfs(1, 0, 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    std::cin >> nodes[i];
  }

  int u, v;
  for (int i = 1; i < N; i++) {
    std::cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  std::cout << get_available_leaves() << '\n';

  return 0;
}
