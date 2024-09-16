#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using Edge = std::pair<int, int>;

class Graph {
public:
  Graph(int, int);
  void solution(int);

private:
  int num_vertices_;
  std::vector<std::vector<Edge>> graph_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_vertices = 0, num_edges = 0, start = 0;
  std::cin >> num_vertices >> num_edges >> start;

  Graph graph = Graph(num_vertices, num_edges);
  graph.solution(start);

  return 0;
}

Graph::Graph(int num_vertices, int num_edges)
    : num_vertices_(num_vertices),
      graph_(num_vertices + 1, std::vector<Edge>()) {
  int u = 0, v = 0, weight = 0;
  while (num_edges--) {
    std::cin >> u >> v >> weight;
    graph_[u].push_back({v, weight});
  }
}

void Graph::solution(int start) {
  int inf = std::numeric_limits<int>::max();
  std::vector<int> distance(num_vertices_ + 1, inf);

  auto cmp = [](const Edge &e1, const Edge &e2) {
    return e1.second > e2.second;
  };
  std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);

  distance[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    auto [current_vertex, current_distance] = pq.top();
    pq.pop();

    if (distance[current_vertex] < current_distance)
      continue;

    for (auto [adjacent_vertex, weight] : graph_[current_vertex]) {
      int new_distance = current_distance + weight;

      if (new_distance > distance[adjacent_vertex])
        continue;

      distance[adjacent_vertex] = new_distance;
      pq.push({adjacent_vertex, new_distance});
    }
  }

  for (int i = 1; i <= num_vertices_; i++) {
    if (distance[i] == inf)
      std::cout << "INF\n";
    else
      std::cout << distance[i] << '\n';
  }
}
