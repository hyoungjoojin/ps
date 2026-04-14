#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

const int MAX_NODES = 100001;

int num_nodes;
int num_edges;
std::vector<int> graph[MAX_NODES];

int num_components;
std::vector<std::vector<int>> condensed_graph;
std::vector<int> indegree;

int timer;
int time_in[MAX_NODES];
int time_low[MAX_NODES];

int roots[MAX_NODES];

std::stack<int, std::vector<int>> stack;

void init() {
  num_components = 0;
  condensed_graph.clear();
  indegree.clear();

  timer = 0;

  for (int i = 1; i <= num_nodes; i++) {
    graph[i].clear();
    time_in[i] = -1;
    time_low[i] = -1;
    roots[i] = -1;
  }

  stack = std::stack<int, std::vector<int>>();
}

void dfs(int v) {
  time_in[v] = time_low[v] = timer++;
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

  if (time_in[v] == time_low[v]) {
    int component_id = num_components++;

    while (true) {
      int u = stack.top();
      stack.pop();

      roots[u] = component_id;

      if (u == v) {
        break;
      }
    }
  }
}

void compute_scc() {
  for (int i = 1; i <= num_nodes; i++) {
    if (time_in[i] == -1) {
      dfs(i);
    }
  }

  condensed_graph.resize(num_components);

  for (int i = 1; i <= num_nodes; i++) {
    for (int ai = 0; ai < graph[i].size(); ai++) {
      int adj = graph[i][ai];

      if (roots[i] != roots[adj]) {
        condensed_graph[roots[i]].push_back(roots[adj]);
      }
    }
  }
}

void compute_indegree() {
  indegree.resize(num_components);

  for (int i = 0; i < num_components; i++) {
    for (int ai = 0; ai < condensed_graph[i].size(); ai++) {
      int adj = condensed_graph[i][ai];
      indegree[adj]++;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  for (int i = 0; i < T; i++) {
    std::cin >> num_nodes >> num_edges;

    init();

    int u, v;
    for (int j = 0; j < num_edges; j++) {
      std::cin >> u >> v;
      graph[u].push_back(v);
    }

    compute_scc();
    compute_indegree();

    int result = 0;
    for (int i = 0; i < num_components; i++) {
      if (indegree[i] == 0) {
        result++;
      }
    }

    std::cout << result << "\n";
  }

  return 0;
}
