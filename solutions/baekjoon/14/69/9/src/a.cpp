#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 5001;

int N;
int M;
int heights[MAX_N];
std::vector<int> graph[MAX_N];

int memo[MAX_N];

void init() {
  for (int i = 0; i <= N; i++) {
    memo[i] = -1;
  }
}

int get_maximum_count(int i) {
  if (memo[i] != -1) {
    return memo[i];
  }

  int count = 0;

  for (int ai = 0; ai < graph[i].size(); ai++) {
    int adj = graph[i][ai];
    if (heights[adj] <= heights[i]) {
      continue;
    }

    count = std::max(count, get_maximum_count(adj));
  }

  return memo[i] = count + 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    std::cin >> heights[i];
  }

  int u, v;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  init();

  for (int i = 1; i <= N; i++) {
    std::cout << get_maximum_count(i) << '\n';
  }

  return 0;
}
