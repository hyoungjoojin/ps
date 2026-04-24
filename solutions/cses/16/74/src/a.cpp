#include <iostream>
#include <vector>

const int MAX_N = 200001;

int N;
std::vector<int> graph[MAX_N];

int subordinates[MAX_N];

int _compute_subordinates_recursive(int node) {
  int count = 0;

  for (int adj : graph[node]) {
    count += _compute_subordinates_recursive(adj) + 1;
  }

  return subordinates[node] = count;
}

void compute_subordinates() {
  int root = 1;
  _compute_subordinates_recursive(1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  int parent;
  for (int i = 2; i <= N; i++) {
    std::cin >> parent;
    graph[parent].push_back(i);
  }

  compute_subordinates();

  for (int i = 1; i <= N; i++) {
    std::cout << subordinates[i] << ' ';
  }

  return 0;
}
