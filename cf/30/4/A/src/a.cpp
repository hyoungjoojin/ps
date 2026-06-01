#include <algorithm>
#include <iostream>

const int MAX_N = 1e4 + 1;

int N;
int squares[MAX_N];

int find_triangles() {
  int count = 0;
  for (int c = 1; c <= N; c++) {
    for (int a = 1; a < c; a++) {
      count += std::binary_search(squares + a + 1, squares + c,
                                  squares[c] - squares[a]);
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i <= N; i++) {
    squares[i] = i * i;
  }

  std::cout << find_triangles() << '\n';

  return 0;
}
