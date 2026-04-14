#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

const int MAX_NODES = 10001;

int num_nodes;
int num_edges;
std::vector<int> graph[MAX_NODES];

std::vector<std::vector<int>> components;
int roots[MAX_NODES];

int timer;
int time_in[MAX_NODES];
int time_low[MAX_NODES];

std::stack<int, std::vector<int>> stack;

void dfs(int v) {
  int id = timer++;
  time_low[v] = id;
  time_in[v] = id;

  stack.push(v);

  for (int ai = 0; ai < graph[v].size(); ai++) {
    int adj = graph[v][ai];

    if (time_in[adj] == -1) {
      dfs(adj);
    }

    if (roots[adj] == -1) {
      time_low[v] = std::min(time_low[v], time_low[adj]);
    }
  }

  if (time_low[v] == time_in[v]) {
    components.push_back({v});

    while (true) {
      int u = stack.top();
      stack.pop();

      roots[u] = components.size() - 1;

      if (u == v) {
        break;
      }

      components.back().push_back(u);
    }
  }
}

void scc() {
  components.clear();

  timer = 0;

  for (int i = 1; i <= num_nodes; i++) {
    roots[i] = -1;
    time_in[i] = -1;
    time_low[i] = -1;
  }

  for (int i = 1; i <= num_nodes; i++) {
    if (time_in[i] == -1) {
      dfs(i);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_nodes >> num_edges;

  int u, v;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
  }

  scc();

  for (int i = 0; i < components.size(); i++) {
    std::sort(components[i].begin(), components[i].end());
  }

  std::sort(components.begin(), components.end(),
            [](const std::vector<int> &v1, const std::vector<int> &v2) {
              return v1[0] < v2[0];
            });

  std::cout << components.size() << "\n";

  for (int i = 0; i < components.size(); i++) {
    for (int j = 0; j < components[i].size(); j++) {
      std::cout << components[i][j] << " ";
    }

    std::cout << "-1\n";
  }

  return 0;
}
