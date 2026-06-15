#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    std::cin >> a[i];
  }

  std::vector<int> r(N + 1);
  for (int i = 1; i <= N; i++) {
    int x;
    std::cin >> x;
    r[x] = i;
  }

  bool ok = true;
  for (int i = 1; i <= N; i++) {
    if (a[i] != r[i]) {
      ok = false;
      break;
    }
  }

  std::cout << (ok ? "Yes\n" : "No\n");

  return 0;
}
