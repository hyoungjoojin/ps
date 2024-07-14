// 8 ms, 2020 KB

#include <iostream>
#include <string>
#include <vector>

void print_solution(int, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0;
  std::cin >> N >> M;

  print_solution(N, M);

  return 0;
}

void print_solution_recursive(std::vector<bool> &visited, std::string &prefix,
                              int N, int M) {
  if (M == 0) {
    std::cout << prefix << '\n';
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i])
      continue;

    visited[i] = true;
    prefix += std::to_string(i + 1);
    prefix += ' ';

    print_solution_recursive(visited, prefix, N, M - 1);

    prefix.pop_back();
    prefix.pop_back();
    visited[i] = false;
  }
}

void print_solution(int N, int M) {
  std::vector<bool> visited(N, false);
  std::string prefix = "";
  print_solution_recursive(visited, prefix, N, M);
}
