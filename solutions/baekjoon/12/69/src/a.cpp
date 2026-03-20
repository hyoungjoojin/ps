#include <iostream>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::set<int> union_set, intersection_set;
  int input;

  for (int i = 0; i < N; i++) {
    std::cin >> input;
    union_set.insert(input);
  }

  for (int i = 0; i < M; i++) {
    std::cin >> input;

    if (union_set.find(input) == union_set.end()) {
      union_set.insert(input);
    } else {
      intersection_set.insert(input);
    }
  }

  int count = union_set.size() - intersection_set.size();
  std::cout << count << '\n';

  return 0;
}
