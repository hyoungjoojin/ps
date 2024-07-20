// 312 ms, 15032 KB

#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
public:
  Graph(int, int);

  int get_solution();

private:
  int num_vertices_;
  int num_edges_;

  struct Edge_ {
    int u;
    int v;
    int weight;
  };

  std::vector<int> parent_;
  int find_(int);
  void merge_(int, int);

  std::vector<Edge_> edges_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0;
  std::cin >> N >> M;

  Graph graph(N, M);
  std::cout << graph.get_solution() << '\n';

  return 0;
}

Graph::Graph(int num_vertices, int num_edges)
    : num_vertices_(num_vertices), num_edges_(num_edges) {
  parent_ = std::vector<int>(num_vertices_ + 1);
  for (int i = 0; i <= num_vertices_; i++)
    parent_[i] = i;

  edges_ = std::vector<Edge_>(num_edges_);
  for (auto &[u, v, weight] : edges_)
    std::cin >> u >> v >> weight;
}

int Graph::find_(int x) {
  while (parent_[x] != x)
    x = parent_[x] = parent_[parent_[x]];
  return parent_[x];
}

void Graph::merge_(int x, int y) {
  int parent_x = find_(x), parent_y = find_(y);
  if (parent_x != parent_y)
    parent_[parent_x] = parent_[parent_y];
}

int Graph::get_solution() {
  std::sort(edges_.begin(), edges_.end(), [](const Edge_ &e1, const Edge_ &e2) {
    return e1.weight < e2.weight;
  });

  int count = 0;
  std::vector<int> vertex_weights;
  for (const auto &[u, v, weight] : edges_) {
    if (find_(u) == find_(v))
      continue;

    merge_(u, v);
    vertex_weights.push_back(weight);

    if (++count == num_vertices_ - 1)
      break;
  }

  int total_weight = 0;
  for (const int &weight : vertex_weights)
    total_weight += weight;
  total_weight -=
      *std::max_element(vertex_weights.begin(), vertex_weights.end());

  return total_weight;
}
