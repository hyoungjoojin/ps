#include <iostream>
#include <vector>

const int MAX_N = 2e5 + 1;

int N;
std::vector<int> graph[MAX_N];

int children[MAX_N];

int count_children_recursive(int node) {
  int count = 0;

  for (int adj : graph[node]) {
    count += (count_children_recursive(adj) + 1);
  }

  return children[node] = count;
}

void count_children() { count_children_recursive(1); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int v = 2; v <= N; v++) {
    int u;
    std::cin >> u;
    graph[u].push_back(v);
  }

  count_children();

  for (int i = 1; i <= N; i++) {
    std::cout << children[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
