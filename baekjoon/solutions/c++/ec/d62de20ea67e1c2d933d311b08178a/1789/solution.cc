// 0 ms, 3508 KB

#include <iostream>

int get_solution(unsigned int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned int S = 0;
  std::cin >> S;

  std::cout << get_solution(S) << '\n';

  return 0;
}

int get_solution_recursive(unsigned int sum, int current_value) {
  if (sum == current_value)
    return 1;

  if (sum < current_value)
    return -1;

  int count = get_solution_recursive(sum - current_value, current_value + 1);
  if (count == -1)
    return get_solution_recursive(sum, current_value + 1);
  else
    return count + 1;
}

int get_solution(unsigned int sum) { return get_solution_recursive(sum, 1); }
