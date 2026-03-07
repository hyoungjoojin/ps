#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

enum { LAND = -1, WATER = -2 };

const int MAX_N = 11;
const int MAX_M = 11;
const int MAX_NODES = 7;
const int INF = std::numeric_limits<int>::max();

int N;
int M;
int num_nodes;
int grid[MAX_N][MAX_M];
int graph[MAX_NODES][MAX_NODES];

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void find_connected_components() {
  num_nodes = 0;
  std::queue<std::pair<int, int>> queue;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] >= 0 || grid[i][j] == WATER) {
        continue;
      }

      grid[i][j] = num_nodes++;
      queue.push({i, j});

      while (!queue.empty()) {
        int r = queue.front().first, c = queue.front().second;
        queue.pop();

        for (int di = 0; di < 4; di++) {
          int next_r = r + directions[di][0], next_c = c + directions[di][1];
          if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M ||
              grid[next_r][next_c] >= 0 || grid[next_r][next_c] == WATER) {
            continue;
          }

          grid[next_r][next_c] = grid[r][c];
          queue.push({next_r, next_c});
        }
      }
    }
  }
}

void build_graph() {
  find_connected_components();

  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      graph[i][j] = INF;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0, len = 0, previous = -1; j < M; j++) {
      if (grid[i][j] == WATER) {
        len++;
        continue;
      }

      if (len >= 2 && len < graph[grid[i][j]][previous]) {
        graph[grid[i][j]][previous] = len;
        graph[previous][grid[i][j]] = len;
      }

      len = 0;
      previous = grid[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0, len = 0, previous = -1; j < N; j++) {
      if (grid[j][i] == WATER) {
        len++;
        continue;
      }

      if (len >= 2 && len < graph[grid[j][i]][previous]) {
        graph[grid[j][i]][previous] = len;
        graph[previous][grid[j][i]] = len;
      }

      len = 0;
      previous = grid[j][i];
    }
  }

  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      if (graph[i][j] == INF) {
        graph[i][j] = 0;
      }

      if (i == j) {
        graph[i][j] = 0;
      }
    }
  }
}

int find_minimum_spanning_tree_weight() {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  bool visited[MAX_NODES] = {false};

  int result = 0, count = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    int w_v = pq.top().first, v = pq.top().second;
    pq.pop();

    if (visited[v]) {
      continue;
    }

    visited[v] = true;
    result += w_v;
    count++;

    for (int adj = 0; adj < num_nodes; adj++) {
      int w_adj = graph[v][adj];
      if (w_adj == 0) {
        continue;
      }

      pq.push({w_adj, adj});
    }
  }

  return (count == num_nodes ? result : -1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  int input;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> input;
      grid[i][j] = (input == 0 ? WATER : LAND);
    }
  }

  build_graph();

  std::cout << find_minimum_spanning_tree_weight() << '\n';

  return 0;
}
