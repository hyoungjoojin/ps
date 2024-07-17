// 32 ms, 3356 KB

#include <algorithm>
#include <iostream>
#include <vector>

struct Edge {
  int u;
  int v;
  int weight;
};

class DisjointSet {
public:
  DisjointSet(int);

  int find(int);
  void merge(int, int);

private:
  std::vector<int> parent_;
};

int get_minimum_spanning_tree_weight(std::vector<Edge> &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int V = 0, E = 0;
  std::cin >> V >> E;

  std::vector<Edge> edges(E);
  for (auto &[u, v, weight] : edges)
    std::cin >> u >> v >> weight;

  std::cout << get_minimum_spanning_tree_weight(edges, V) << '\n';

  return 0;
}

DisjointSet::DisjointSet(int num_vertices) {
  parent_ = std::vector<int>(num_vertices + 1);
  for (int i = 0; i <= num_vertices; i++)
    parent_[i] = i;
}

int DisjointSet::find(int x) {
  while (parent_[x] != x)
    x = parent_[x] = parent_[parent_[x]];
  return parent_[x];
}

void DisjointSet::merge(int u, int v) {
  int u_parent = find(u), v_parent = find(v);
  if (u_parent != v_parent)
    parent_[u_parent] = v_parent;
}

int get_minimum_spanning_tree_weight(std::vector<Edge> &edges,
                                     int num_vertices) {
  std::sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2) {
    return e1.weight < e2.weight;
  });

  DisjointSet set = DisjointSet(num_vertices);

  int minimum_spanning_tree_weight = 0, minimum_spanning_tree_edges = 0;
  for (const auto &[u, v, weight] : edges) {
    if (set.find(u) == set.find(v))
      continue;

    set.merge(u, v);
    minimum_spanning_tree_weight += weight;
    if (++minimum_spanning_tree_edges == num_vertices - 1)
      break;
  }
  return minimum_spanning_tree_weight;
}
