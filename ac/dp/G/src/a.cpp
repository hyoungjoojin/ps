#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

int memo[MAX_N];

int get_longest_path_recursive(int start) {
  if (memo[start] != -1) {
    return memo[start];
  }

  int longest = 0;
  for (int &adj : graph[start]) {
    longest = std::max(longest, get_longest_path_recursive(adj) + 1);
  }

  return memo[start] = longest;
}

int get_longest_path() {
  for (int i = 1; i <= N; i++) {
    memo[i] = -1;
  }

  int result = 0;

  for (int i = 1; i <= N; i++) {
    if (memo[i] == -1) {
      result = std::max(result, get_longest_path_recursive(i));
    }
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

  std::cout << get_longest_path() << '\n';

  return 0;
}
