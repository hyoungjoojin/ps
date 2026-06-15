#include <algorithm>
#include <iostream>
#include <utility>

const int MAX_N = 1001;
const int MAX_X = 1e5 + 1;

int N;
int X;
std::pair<int, int> books[MAX_N];

int memo[MAX_X], temp[MAX_X];

int get_maximum_number_of_pages() {
  for (int i = 0; i < N; i++) {
    auto [price, pages] = books[i];

    for (int x = price; x <= X; x++) {
      temp[x] = std::max(memo[x], memo[x - price] + pages);
    }

    for (int x = price; x <= X; x++) {
      memo[x] = temp[x];
    }
  }

  return memo[X];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> X;

  for (int i = 0; i < N; i++) {
    std::cin >> books[i].first;
  }

  for (int i = 0; i < N; i++) {
    std::cin >> books[i].second;
  }

  std::cout << get_maximum_number_of_pages() << '\n';

  return 0;
}
