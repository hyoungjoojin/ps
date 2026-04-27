#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 1e5 + 1;

int N;
int M;
std::vector<int> graph[MAX_N];

int previous[MAX_N];

std::vector<int> find_path() {
  int start = 1, end = N;
  std::queue<int> queue;

  for (int i = 1; i <= N; i++) {
    previous[i] = -1;
  }

  queue.push(start);
  previous[start] = start;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    if (front == end) {
      break;
    }

    for (int &adj : graph[front]) {
      if (previous[adj] == -1) {
        queue.push(adj);
        previous[adj] = front;
      }
    }
  }

  if (previous[end] == -1) {
    return std::vector<int>();
  }

  std::vector<int> path;

  int current = end;
  while (current != start) {
    path.push_back(current);
    current = previous[current];
  }
  path.push_back(start);

  for (int li = 0, ri = path.size() - 1; li < ri; li++, ri--) {
    std::swap(path[li], path[ri]);
  }

  return path;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  int a, b;
  for (int i = 0; i < M; i++) {
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<int> path = find_path();

  if (path.size() == 0) {
    std::cout << "IMPOSSIBLE\n";
  } else {
    std::cout << path.size() << '\n';

    for (int &i : path) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
