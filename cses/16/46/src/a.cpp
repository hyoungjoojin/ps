#include <iostream>

using ll = long long;

const int MAX_N = 2e5 + 1;

int N;
ll psum[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int Q;
  std::cin >> N >> Q;

  psum[0] = 0;
  for (int i = 1; i <= N; i++) {
    int x;
    std::cin >> x;
    psum[i] = psum[i - 1] + x;
  }

  for (int q = 1; q <= Q; q++) {
    int a, b;
    std::cin >> a >> b;
    std::cout << psum[b] - psum[a - 1] << '\n';
  }

  return 0;
}
